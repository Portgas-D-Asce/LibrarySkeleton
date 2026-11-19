//
// Created by pk on 11/19/26.
//

#include <cstdio>
#include "mylib/mylib.h"

int main() {
    mylib::Camera cam(1, 2, 3, 10, 20, 60, 40);
    mylib::CamerasCalculator calc({cam}, 0.3);
    calc.adjust_lda(90);
    std::printf("lda=%.1f version=%s\n",
                calc.get_cameras()[0].lda(), MYLIB_VERSION_STRING);
    return 0;
}
