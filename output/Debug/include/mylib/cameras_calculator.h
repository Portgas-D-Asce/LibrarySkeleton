//
// Created by pk on 11/18/26.
//

#ifndef MYLIB_CAMERAS_CACULATOR_H
#define MYLIB_CAMERAS_CACULATOR_H

#include <memory>
#include <vector>
#include "mylib/export.h"
#include "mylib/camera.h"

namespace mylib {

    class MYLIB_API CamerasCalculator {
    public:
        CamerasCalculator();
        explicit CamerasCalculator(const std::vector<Camera>& cameras,
                                   double wheel_radius = 0.3);
        ~CamerasCalculator();

        CamerasCalculator(const CamerasCalculator&);
        CamerasCalculator& operator=(const CamerasCalculator&);
        CamerasCalculator(CamerasCalculator&&) noexcept;
        CamerasCalculator& operator=(CamerasCalculator&&) noexcept;

        void adjust_lda(double degree_diff);
        void adjust_loa(double degree_diff);
        void update_wheel_radius(double radius);
        std::vector<Camera> get_cameras() const;
        void reset();

    private:
        struct Impl;
        std::unique_ptr<Impl> impl_;
    };

} // namespace mylib


#endif //MYLIB_CAMERAS_CACULATOR_H
