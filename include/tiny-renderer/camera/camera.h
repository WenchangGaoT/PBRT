#pragma once

#include <tiny-renderer/transforms/transform.h>
#include <tiny-renderer/math/vector.h>
#include <tiny-renderer/math/ray.h>
#include <tiny-renderer/film/film.h>

namespace TinyRenderer {

  class Camera {
  private:
    Vector3<float> pos;
    Film* film;
  
  public:
    Camera(); 
    ~Camera();
    Ray GenerateRay();
  };

};
