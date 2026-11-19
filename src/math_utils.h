//
// Created by pk on 11/18/26.
//

#ifndef MYLIB_MATH_UTILS_H
#define MYLIB_MATH_UTILS_H

namespace mylib {
    namespace internal {

        constexpr double kPi = 3.14159265358979323846;

        inline double deg2rad(double deg) { return deg * kPi / 180.0; }
        inline double rad2deg(double rad) { return rad * 180.0 / kPi; }

        inline double normalize_degree(double deg) {
            deg = deg - 360.0 * static_cast<int>(deg / 360.0);
            if (deg >= 180.0) deg -= 360.0;
            if (deg < -180.0) deg += 360.0;
            return deg;
        }

    } // namespace internal
} // namespace mylib

#endif //MYLIB_MATH_UTILS_H
