#pragma once

#ifndef TINYRENDERER_MATH_MATRIX_H
#define TINYRENDERER_MATH_MATRIX_H

namespace TinyRenderer {
  template <typename T>
  class SquareMatrix3 {
  public:
    T m[3][3];
    void SetValue(const int i, const int j, const T v) {m[i][j] = v;}
    Point3<T> Multiply(const Point3<T> p) const { 
      T value[3] = {0, 0, 0};
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          value[i] += m[i][j] * p[j];
        }
      }
      return Point3<T>(value[0], value[1], value[2]);
    }
    Vector3<T> Multiply(const Vector3<T> p) const { 
      T value[3] = {0, 0, 0};
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          value[i] += m[i][j] * p[j];
        }
      }
      return Vector3<T>(value[0], value[1], value[2]);
    }
    SquareMatrix3<T> Transpose() const {
      SquareMatrix3<T> m1;
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          m1.SetValue(i, j, m[j][i]);
        }
      }
      return m1;
    }
  };
}

#endif // TINYRENDERER_MATH_MATRIX_H