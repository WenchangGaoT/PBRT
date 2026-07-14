
#pragma once 

#ifndef TINYRENDERER_TRANSFORMS_TRANSFORM_H
#define TINYRENDERER_TRANSFORMS_TRANSFORM_H

#include <tiny-renderer/math/point.h>
#include <tiny-renderer/math/vector.h> 
#include <tiny-renderer/math/normal.h>
#include <tiny-renderer/math/matrix.h>
#include <tiny-renderer/math/ray.h>

namespace TinyRenderer {
  class Transform{
  public:
    double m[4][4], mInv[4][4];

    Transform() {
      // Identity by default
      for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
          m[i][j] = mInv[i][j] = i == j;
        }
      }
    }
    Transform(const Transform& t) {
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          m[i][j] = t.m[i][j];
          mInv[i][j] = t.mInv[i][j];
        }
      }
    }
    void SetValue(const int i, const int j, const double v) {
      m[i][j] = v;
    }
    void SetRotation(const SquareMatrix3<double>& r) {
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          m[i][j] = r.m[i][j];
        }
      }
    }
    void SetTranslation(const Point3<double>& d) {
      for (int i = 0; i < 3; ++i)
        m[i][3] = d[i];
    }
    Vector3<double> ApplyTransform(const Vector3<double>& p) const {
      double value[3] = {0, 0, 0};
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          value[i] += m[i][j] * p[j];
        }
      }
      return Vector3<double>(value[0], value[1], value[2]);
    }
    Point3<double> ApplyTransform(const Point3<double>& p) const {
      double value[3] = {0, 0, 0};
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
          value[i] += j < 3 ? m[i][j] * p[j] : m[i][j];
        }
      }
      return Point3<double>(value[0], value[1], value[2]);
    }
    Ray ApplyTransform(const Ray& r) const {
      Point3<double> newP = ApplyTransform(r.GetPosition());
      Vector3<double> newD = ApplyTransform(r.GetDirection());
      return Ray(newP, newD, r.GetMaxT());
    }
  };

};

#endif // TINYRENDERER_TRANSFORMS_TRANSFORM_H
