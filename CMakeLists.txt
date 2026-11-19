cmake_minimum_required(VERSION 3.15)

project(mylib
        VERSION 0.1.0
        DESCRIPTION "A C++ library with public/private header isolation"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_SHARED_LIBS "Build shared library" OFF)
option(MYLIB_BUILD_EXAMPLES "Build examples" ON)

include(GNUInstallDirs)

set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/output/${CMAKE_BUILD_TYPE}")

# ---------- 生成版本头 ----------
configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/version.h.in
        ${CMAKE_CURRENT_BINARY_DIR}/generated/mylib/version.h
        @ONLY
)

# ---------- 库目标 ----------
add_library(mylib
        src/camera.cpp
        src/cameras_calculator.cpp
)

target_include_directories(mylib
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/generated>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_definitions(mylib PRIVATE MYLIB_BUILDING)
if(BUILD_SHARED_LIBS)
    target_compile_definitions(mylib PUBLIC MYLIB_SHARED)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(mylib PRIVATE
            -fvisibility=hidden -fvisibility-inlines-hidden)
endif()

set_target_properties(mylib PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
)

# ---------- 示例 ----------
if(MYLIB_BUILD_EXAMPLES)
    add_executable(mylib_example examples/main.cpp)
    target_link_libraries(mylib_example PRIVATE mylib)
endif()

# ---------- 安装（必须在 add_library 之后） ----------
install(TARGETS mylib
        EXPORT mylibTargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY include/mylib
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILES_MATCHING PATTERN "*.h"
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/generated/mylib/version.h
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/mylib
)

install(EXPORT mylibTargets
        FILE mylibTargets.cmake
        NAMESPACE mylib::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/mylib
)

include(CMakePackageConfigHelpers)

configure_package_config_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/mylibConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/mylibConfig.cmake
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/mylib
)

write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/mylibConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
)

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/mylibConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/mylibConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/mylib
)

add_subdirectory(consumer)
