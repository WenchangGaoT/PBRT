#pragma once 

#ifndef TINYRENDERER_MATH_POINT_H
#define TINYRENDERER_MATH_POINT_H

#include <tiny-renderer/math/vector.h>
#include <cassert>
#include <nlohmann/json.hpp>

namespace TinyRenderer {
  template <typename T>
  class Point2 {
  public:
    T x, y;

  public:
    Point2() {x=y=0;}
    Point2(T x, T y): x(x), y(y) {}
    Point2<T>  operator+(const Vector2<T> &v) const {
      return Point2<T>(x + v.x, y + v.y);
    }
    Point2<T> &operator+=(const Vector2<T> &v) {
      x += v.x; y += v.y;
      return *this;
    }
    Point2<T>  operator-(const Vector2<T> &v) const {
      return Point2<T>(x - v.x, y - v.y);
    }
    Point2<T> &operator-=(const Vector2<T> &v) {
      x -= v.x; y -= v.y;
      return *this;
    }
    Vector2<T> operator-(const Point2<T> &p) const {
      return Vector2<T>(x - p.x, y - p.y);
    }
    T operator[](int i) const {
      assert(0 <= i && i <= 1);
      if (i == 0) return x;
      return y;
    }
    T &operator[](int i) {
      assert(0 <= i && i <= 1);
      if (i == 0) return x;
      return y;
    }
    Point2<T> operator-() const {
      return Point2<T>(-x, -y);
    }
  };


  template <typename T>
  class Point3 {
  public:
    T x, y, z;
    Point3() {x=y=z=0;}
    Point3(T x, T y, T z): x(x), y(y), z(z) {}
    Point3<T>  operator+(const Vector3<T> &v) const {
      return Point3<T>(x + v[0], y + v[1], z + v[2]);
    }
    Point3<T> &operator+=(const Vector3<T> &v) {
      x += v[0]; y += v[1]; z += v[2];
      return *this;
    }
    Point3<T>  operator-(const Vector3<T> &v) const {
      return Point3<T>(x - v[0], y - v[1], z - v[2]);
    }
    Point3<T> &operator-=(const Vector3<T> &v) {
      x -= v[0]; y -= v[1]; z -= v[2];
      return *this;
    }
    Vector3<T> operator-(const Point3<T> &p) const {
      return Vector3<T>(x - p.x, y - p.y, z - p.z);
    }
    Point3<T> operator-() const {
      return Point3<T>(-x, -y, -z);
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
  };

  template <typename T>
  void from_json(const nlohmann::json& vJson, Point2<T>& p) {
    if (!vJson.is_array() || vJson.size() != 2) {
      throw std::runtime_error("Point3 must bu an array of three numbers");
    }
    vJson.at(0).get_to(p.x);
    vJson.at(1).get_to(p.y);
  }

  template <typename T>
  void from_json(const nlohmann::json& vJson, Point3<T>& p) {
    if (!vJson.is_array() || vJson.size() != 3) {
      throw std::runtime_error("Point3 must bu an array of three numbers");
    }
    vJson.at(0).get_to(p.x);
    vJson.at(1).get_to(p.y);
    vJson.at(2).get_to(p.z);
  }
}

#endif // TINYRENDERER_MATH_POINT_H
