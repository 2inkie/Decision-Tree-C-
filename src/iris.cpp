// src/iris.cpp
#include "../include/iris.h"

Iris::Iris() {
    for (int i = 0; i < 4; ++i) {
        feature[i] = 0.0;
    }
    variety = "Unknown";
}

Iris::Iris(const double _f[4], const std::string _v) {
    for (int i = 0; i < 4; i++) {
        feature[i] = _f[i];
    }
    variety = _v;
}