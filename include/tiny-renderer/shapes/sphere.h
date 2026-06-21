#pragma once 

#include <tiny-renderer/shapes/shape.h>
#include <tiny-renderer/math/vector.h>

namespace TinyRenderer {

  class Sphere: Shape {
  private: 
    float radius;
    Vector3<float> pos;

  public:

    Sphere();
  };

}
