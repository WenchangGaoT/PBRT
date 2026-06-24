#pragma once

#ifndef TINYRENDERER_SHAPES_SHAPE_H
#define TINYRENDERER_SHAPES_SHAPE_H
#include "tiny-renderer/transforms/transform.h"
#include "tiny-renderer/math/ray.h"

namespace TinyRenderer {
  class Shape {
    const Transform *ObjToWorld, *WorldToObj;
    const bool reverseOrientation;
    const bool transformSwapsHandedness;
  
  public:
    Shape(const Transform *ObjToWorld, const Transform *WorldToObj, bool reverseOrientation);
    virtual bool Intersect(const Ray* ray) {}
  };
};

#endif // TINYRENDERER_SHAPES_SHAPE_H
