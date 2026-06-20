#pragma once
#include "tiny-renderer/transforms/transform.h"

namespace TinyRenderer {
  class Shape {
  public: 
    const Transform *ObjToWorld, *WorldToObj;
    const bool reverseOrientation;
    const bool transformSwapsHandedness;
    Shape(const Transform *ObjToWorld, const Transform *WorldToObj, bool reverseOrientation);
  };
};

