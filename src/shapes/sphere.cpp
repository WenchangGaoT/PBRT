#include <tiny-renderer/shapes/sphere.h>
#include "tiny-renderer/math/point.h"
#include <cmath>

namespace TinyRenderer {
  bool Sphere::Intersect(const Ray *ray, SurfaceInteraction *hit) const {
    Vector3<double> dir = ray->GetDirection() ;
    Point3<double> o1 = ray->GetPosition();
    Vector3<double> delta_o = o1 - pos;
    double a = dir.Dot(dir), b = dir.Dot(delta_o), c = delta_o.Dot(delta_o) - radius * radius;
    double b2 = b * b;
    double ac = a * c;
    double delta = b2 - ac;
    if (delta >= 0) {
      double t1 = (std::sqrt(delta)-b)/a;
      double t2 = (-std::sqrt(delta)-b)/a;
      if (t1 < 0 && t2 < 0) return false;
      if (t1 < t2) hit->t = t1 >= 0 ? t1 : t2;
      else hit->t = t2 >= 0? t2 : t1;
      // hit->t = t1 <= t2 ? t1 : t2;
      hit->pos = o1 + dir * hit->t; 
      hit->n = (Normal3<double>) (hit-> pos - pos);
      return true;
    }
    return false;
  }
}
