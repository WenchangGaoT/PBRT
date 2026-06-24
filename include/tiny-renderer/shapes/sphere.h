#pragma once 

#ifndef TINYRENDERER_SHAPES_SPHERE_H
#define TINYRENDERER_SHAPES_SPHERE_H

#include <tiny-renderer/shapes/shape.h>
#include <tiny-renderer/math/vector.h>
#include <tiny-renderer/math/point.h>

namespace TinyRenderer {

  class Sphere: Shape {
  private: 
    double radius;
    Point3<double> pos;

  public:
    Sphere(

      const Transform *ObjToWorld, const Transform *WorldToObj, bool reverseOrientation,
      double x, double y, double z, double r): Shape(ObjToWorld, WorldToObj, reverseOrientation), pos(x, y, z), radius(r) {
        // some checks here.
      }
  };

}

#endif // TINYRENDERER_SHAPES_SPHERE_H
