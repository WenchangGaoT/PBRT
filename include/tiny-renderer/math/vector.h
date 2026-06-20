#pragma once

#include <cmath> 
#include <cassert>

namespace TinyRenderer {

  template<typename T>
  class Vector3 {
  private:
    T x, y, z; 

  public:
    Vector3() {x = y = z = 0;}
    Vector3(T x, T y, T z): x(x), y(y), z(z){};

    bool HasNans() const {
      return std::isnan(x) || std::isnan(y) || std::isnan(z);
    }

    T operator[](int i) const {
      assert(0 <= i && i <= 2);
      if (i == 0) return x;
      if (i == 1) return y;
      return z;
    }
    T &operator[](int i) {
      assert(0 <= i && i <= 2);
      if (i == 0) return x;
      if (i == 1) return y;
      return z;
    }
    Vector3<T> operator+(const Vector3<T> &v) const {
      return Vector3<T>(x+v.x, y+v.y, z+v.z);
    }
    Vector3<T> &operator+=(const Vector3<T> &v) {
      x += v.x; y += v.y; z += v.z;
      return *this;
    }
    Vector3<T> operator*(const Vector3<T> &v) const {
      return Vector3<T>(x*v.x, y*v.y, z*v.z);
    }
    Vector3<T> &operator*=(const Vector3<T> &v) {
      x *= v.x; y *= v.y; z *= v.z;
      return *this;
    }
    Vector3<T> operator-(const Vector3<T> &v) const {
      return Vector3<T>(x-v.x, y-v.y, z-v.z);
    }
    Vector3<T> &operator-=(const Vector3<T> &v) {
      x -= v.x; y -= v.y; z -= v.z;
      return *this;
    }
    Vector3<T> operator/(const Vector3<T> &v) const {
      return Vector3<T>(x/v.x, y/v.y, z/v.z);
    }
    Vector3<T> &operator/=(const Vector3<T> &v) {
      x /= v.x; y /= v.y; z /= v.z;
      return *this;
    }
    Vector3<T> operator-() const {
      return Vector3<T>(-x, -y, -z);
    }
  };

};
