//
// Created by pk on 11/18/26.
//

#ifndef MYLIB_CAMERA_H
#define MYLIB_CAMERA_H

#include "mylib/export.h"

namespace mylib {

    class MYLIB_API Camera {
    public:
        Camera(double x = 0.0, double y = 0.0, double z = 0.0,
               double lda = 0.0, double loa = 0.0,
               double fov_h = 0.0, double fov_v = 0.0);

        double x() const;
        void x(double val);

        double y() const;
        void y(double val);

        double z() const;
        void z(double val);

        double lda() const;
        void lda(double val);

        double loa() const;
        void loa(double val);

        double fov_h() const;
        void fov_h(double val);

        double fov_v() const;
        void fov_v(double val);

    private:
        double _x{0.0};
        double _y{0.0};
        double _z{0.0};
        double _lda{0.0};
        double _loa{0.0};
        double _fov_h{0.0};
        double _fov_v{0.0};
    };

} // namespace mylib


#endif //MYLIB_CAMERA_H
