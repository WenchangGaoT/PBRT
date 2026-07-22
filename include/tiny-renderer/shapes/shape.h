#pragma once

#ifndef TINYRENDERER_SHAPES_SHAPE_H
#define TINYRENDERER_SHAPES_SHAPE_H
#include "tiny-renderer/transforms/transform.h"
#include "tiny-renderer/math/ray.h"
#include "tiny-renderer/math/normal.h"
#include <nlohmann/json.hpp>
#include <memory>

namespace TinyRenderer {
  struct SurfaceInteraction {
    Point3<double> pos; 
    Normal3<double> n; 
    double t;

    SurfaceInteraction(): pos(0, 0, 0), n(0, 0, 0), t(INFINITY) {}
    SurfaceInteraction(const Point3<double> &p, const Normal3<double> &n, const double &t):
      pos(p), n(n), t(t) {}

  };


  class Shape {
    // const Transform *ObjToWorld, *WorldToObj;
    // const bool reverseOrientation;
    // const bool transformSwapsHandedness;
  
  public:
    Shape() {}
    virtual ~Shape() = default;
    // Shape(const Transform *ObjToWorld, const Transform *WorldToObj, bool reverseOrientation);
    virtual bool Intersect(const Ray* ray, SurfaceInteraction* hit) const = 0;
    static std::shared_ptr<Shape> InstantiateShape(const nlohmann::json&);
  };

  enum class ShapeType {
    Invalid = 0,
    Sphere = 1,
  };

  NLOHMANN_JSON_SERIALIZE_ENUM(ShapeType, {
    {ShapeType::Invalid, "unknown"}, 
    {ShapeType::Sphere, "sphere"},
  })
};

#endif // TINYRENDERER_SHAPES_SHAPE_H
