//
// Created by pk on 11/18/26.
//

#include "mylib/cameras_calculator.h"
#include "math_utils.h"

namespace mylib {

    struct CamerasCalculator::Impl {
        std::vector<Camera> cameras;
        double wheel_radius{0.0};
    };

    CamerasCalculator::CamerasCalculator()
        : impl_(std::make_unique<Impl>()) {}

    CamerasCalculator::CamerasCalculator(const std::vector<Camera>& cameras,
                                         double wheel_radius)
        : impl_(std::make_unique<Impl>()) {
        impl_->cameras = cameras;
        impl_->wheel_radius = wheel_radius;
    }

    CamerasCalculator::~CamerasCalculator() = default;

    CamerasCalculator::CamerasCalculator(const CamerasCalculator& other)
        : impl_(std::make_unique<Impl>(*other.impl_)) {}

    CamerasCalculator& CamerasCalculator::operator=(const CamerasCalculator& other) {
        if (this != &other) {
            *impl_ = *other.impl_;
        }
        return *this;
    }

    CamerasCalculator::CamerasCalculator(CamerasCalculator&&) noexcept = default;
    CamerasCalculator& CamerasCalculator::operator=(CamerasCalculator&&) noexcept = default;

    void CamerasCalculator::adjust_lda(double degree_diff) {
        for (auto& cam : impl_->cameras) {
            cam.lda(internal::normalize_degree(cam.lda() + degree_diff));
        }
    }

    void CamerasCalculator::adjust_loa(double degree_diff) {
        for (auto& cam : impl_->cameras) {
            cam.loa(internal::normalize_degree(cam.loa() + degree_diff));
        }
    }

    void CamerasCalculator::update_wheel_radius(double radius) {
        impl_->wheel_radius = radius;
    }

    std::vector<Camera> CamerasCalculator::get_cameras() const {
        return impl_->cameras;
    }

    void CamerasCalculator::reset() {
        impl_->cameras.clear();
        impl_->wheel_radius = 0.0;
    }

} // namespace mylib
