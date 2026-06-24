#pragma once 

#include <tiny-renderer/math/point.h>
#include <tiny-renderer/math/ray.h>
#include <tiny-renderer/math/vector.h> 

namespace TinyRenderer {
  template <typename T> 
  inline Vector3<T> Normalize(const Vector3<T> &v);
}