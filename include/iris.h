// include/iris.h
#pragma once

#include <string>

class Iris {
  public:
    double feature[4];
    std::string variety;

    Iris();
    Iris(const double _f[4], const std::string _v);
};
