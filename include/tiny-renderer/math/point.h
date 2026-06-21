#pragma once 

#include <tiny-renderer/math/vector.h>

namespace TinyRenderer {
  template <typename T>
  class Point3 {
  private:
    T x, y, z;

  public:
    Point3() {x=y=z=0;}
    Point3(T x, T y, T z): x(x), y(y), z(z) {}
    Point3<T>  operator+(const Vector3<T> &v) const {
      return Point3<T>(x + v.x, y + v.y, z + v.z);
    }
    Point3<T> &operator+=(const Vector3<T> &v) {
      x += v.x; y += v.y; z += v.z;
      return *this;
    }
    Point3<T>  operator-(const Vector3<T> &v) const {
      return Point3<T>(x - v.x, y - v.y, z - v.z);
    }
    Point3<T> &operator-=(const Vector3<T> &v) {
      x -= v.x; y -= v.y; z -= v.z;
      return *this;
    }
    Vector3<T> operator-(const Point3<T> &p) const {
      return Vectore3<T>(x - p.x, y - p.y, z - p.z);
    }

  };
}
