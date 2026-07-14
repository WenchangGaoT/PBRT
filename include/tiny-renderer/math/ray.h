#pragma once 

#ifndef TINYRENDERER_MATH_RAY_H
#define TINYRENDERER_MATH_RAY_H

#include <tiny-renderer/math/vector.h>
#include <tiny-renderer/math/point.h>
#include <cmath>

namespace TinyRenderer {

  class Ray {
    Point3<double> pos;
    Vector3<double> dir;
    double maxT=0;

    public:
      Ray(): pos(), dir(), maxT(0) {};
      Ray(const Point3<double> &pos, const Vector3<double> &dir, const double &maxT): 
        pos(pos), dir(dir), maxT(maxT) {};
      Point3<double> operator()(const double t) const {
        double nt = t < maxT ? t : maxT;
        return pos + dir*nt;
      }
      Point3<double> GetPosition() const {
        return pos;
      }
      Vector3<double> GetDirection() const {
        return dir;
      }
      double GetMaxT() const {
        return maxT;
      }
      void SetPosition(const Point3<double>& p) {
        pos = p;
      }
      void SetDirection(const Vector3<double>& d) {
        dir = d;
      }

  };
}

#endif // TINYRENDERER_MATH_RAY_H
