//
// Created by pk on 11/18/26.
//

#include <cstdio>
#include <vector>
#include "mylib/mylib.h"

int main() {
    std::printf("mylib version: %s (num=%d)\n",
                MYLIB_VERSION_STRING, MYLIB_VERSION_NUM);

    mylib::Camera cam(1.0, 2.0, 3.0, 10.0, 20.0, 60.0, 40.0);
    std::printf("camera lda before: %.1f\n", cam.lda());

    std::vector<mylib::Camera> cams{cam};
    mylib::CamerasCalculator calc(cams, 0.3);
    calc.adjust_lda(180.0);

    auto result = calc.get_cameras();
    std::printf("camera lda after adjust_lda(180): %.1f\n", result[0].lda());
    return 0;
}
