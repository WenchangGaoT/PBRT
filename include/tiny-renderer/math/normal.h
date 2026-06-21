#pragma once 

#include <tiny-renderer/math/point.h>
#include <tiny-renderer/math/vector.h>

namespace TinyRenderer {

  template <typename T>
  class Normal3 {
    T x, y, z;

  public:
    explicit Normal3(const Vector3<T> &v): x(v.x), y(v.y), z(v.z) {}

  };

}
