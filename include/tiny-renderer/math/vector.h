#pragma once

#ifndef TINYRENDERER_MATH_VECTOR_H
#define TINYRENDERER_MATH_VECTOR_H

#include <cmath> 
#include <cassert>

namespace TinyRenderer {
  template<typename T>
  class Vector2 {
  private:
    T x, y;

  public:
    Vector2() {x = y = 0;}
    Vector2(T x, T y): x(x), y(y){};

    bool HasNans() const {
      return std::isnan(x) || std::isnan(y);
    }

    T operator[](int i) const {
      assert(0 <= i && i <= 1);
      if (i == 0) return x;
      if (i == 1) return y;
      return y;
    }
    T &operator[](int i) {
      assert(0 <= i && i <= 1);
      if (i == 0) return x;
      if (i == 1) return y;
      return y;
    }
    Vector2<T> operator+(const Vector2<T> &v) const {
      return Vector2<T>(x+v.x, y+v.y);
    }
    Vector2<T> &operator+=(const Vector2<T> &v) {
      x += v.x; y += v.y;
      return *this;
    }
    Vector2<T> operator*(const Vector2<T> &v) const {
      return Vector2<T>(x*v.x, y*v.y);
    }
    Vector2<T> &operator*=(const Vector2<T> &v) {
      x *= v.x; y *= v.y;
      return *this;
    }
    Vector2<T> operator-(const Vector2<T> &v) const {
      return Vector2<T>(x-v.x, y-v.y);
    }
    Vector2<T> &operator-=(const Vector2<T> &v) {
      x -= v.x; y -= v.y;
      return *this;
    }
    Vector2<T> operator/(const Vector2<T> &v) const {
      return Vector2<T>(x/v.x, y/v.y);
    }
    Vector2<T> &operator/=(const Vector2<T> &v) {
      x /= v.x; y /= v.y;
      return *this;
    }
    Vector2<T> operator-() const {
      return Vector2<T>(-x, -y);
    }
    double LengthSquared() const {
      return x*x + y*y;
    }
    double Length() const {
      return std::sqrt(LengthSquared());
    }
  };


  template<typename T>
  class Vector3 {
  private:
    T x, y, z; 

  public:
    Vector3() {x = y = z = 0;}
    Vector3(T x, T y, T z): x(x), y(y), z(z){};

    // properties
    bool HasNans() const {
      return std::isnan(x) || std::isnan(y) || std::isnan(z);
    }
    double LengthSquared() const {
      return x*x + y*y + z*z;
    }
    double Length() const {
      return std::sqrt(LengthSquared());
    }

    // indexing
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
    Vector3<T> Normalize() const {
      double length = Length();
      return Vector3<T>(x / length, y / length, z / length);
    }

    // operations
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
    Vector3<T> operator*(const double t) const {
      return Vector3<T>(t*x, t*y, t*z);
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
    double Dot(const Vector3<T> &v) const {
      return x*v.x + y*v.y + z*v.z;
    }
    Vector3 Cross(const Vector3<T> &v) const {
      double v1x = x, v1y = y, v1z = z; 
      double v2x = v.x, v2y = v.y, v2z = v.z;
      return Vector3<T>(v1y*v2z-v1z*v2y, -v1x*v2z+v2x*v1z, v1x*v2y-v1y*v2x);
    }
  };
};

#endif // TINYRENDERER_MATH_VECTOR_H
