#pragma once 

#ifndef TINYRENDERER_MATH_NORMAL_H
#define TINYRENDERER_MATH_NORMAL_H

#include <tiny-renderer/math/point.h>
#include <tiny-renderer/math/vector.h>

namespace TinyRenderer {

  template <typename T>
  class Normal3 {
    T x, y, z;

  public:
    explicit Normal3(const Vector3<T> &v): x(v[0]), y(v[1]), z(v[2]) {}
    explicit Normal3(T x, T y, T z): x(x), y(y), z(z) {}

  };

}

#endif // TINYRENDERER_MATH_NORMAL_H
