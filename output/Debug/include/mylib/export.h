//
// Created by pk on 11/17/26.
//

#ifndef LIBRARYSKELETON_EXPORT_H
#define LIBRARYSKELETON_EXPORT_H

#if defined(_WIN32) && defined(MYLIB_SHARED)
#  ifdef MYLIB_BUILDING
#    define MYLIB_API __declspec(dllexport)
#  else
#    define MYLIB_API __declspec(dllimport)
#  endif
#elif defined(__GNUC__) && defined(MYLIB_SHARED)
#  define MYLIB_API __attribute__((visibility("default")))
#else
#  define MYLIB_API
#endif

#endif //LIBRARYSKELETON_EXPORT_H
