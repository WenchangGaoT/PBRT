#pragma once 

#ifndef TINYRENDERER_SHAPES_SPHERE_H
#define TINYRENDERER_SHAPES_SPHERE_H

#include <tiny-renderer/shapes/shape.h>
#include <tiny-renderer/math/vector.h>
#include <tiny-renderer/math/point.h>

namespace TinyRenderer {

  class Sphere: public Shape {
  private: 
    double radius;
    Point3<double> pos;

  public:
    // Sphere(
    //   const Transform *ObjToWorld, const Transform *WorldToObj, bool reverseOrientation,
    //   double x, double y, double z, double r): Shape(ObjToWorld, WorldToObj, reverseOrientation), pos(x, y, z), radius(r) {
    //     // some checks here.
    //   }
    Sphere(const Point3<double> &pos, double r): radius(r), pos(pos) {} 
    bool Intersect(const Ray *ray, SurfaceInteraction *hit) const override;
  };

}

#endif // TINYRENDERER_SHAPES_SPHERE_H
