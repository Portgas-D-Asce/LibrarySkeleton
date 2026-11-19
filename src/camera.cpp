//
// Created by pk on 11/18/26.
//

#include "mylib/camera.h"

namespace mylib {

    Camera::Camera(double x, double y, double z,
                   double lda, double loa,
                   double fov_h, double fov_v)
        : _x(x), _y(y), _z(z), _lda(lda), _loa(loa), _fov_h(fov_h), _fov_v(fov_v) {}

    double Camera::x() const { return _x; }
    void Camera::x(double val) { _x = val; }

    double Camera::y() const { return _y; }
    void Camera::y(double val) { _y = val; }

    double Camera::z() const { return _z; }
    void Camera::z(double val) { _z = val; }

    double Camera::lda() const { return _lda; }
    void Camera::lda(double val) { _lda = val; }

    double Camera::loa() const { return _loa; }
    void Camera::loa(double val) { _loa = val; }

    double Camera::fov_h() const { return _fov_h; }
    void Camera::fov_h(double val) { _fov_h = val; }

    double Camera::fov_v() const { return _fov_v; }
    void Camera::fov_v(double val) { _fov_v = val; }

} // namespace mylib
