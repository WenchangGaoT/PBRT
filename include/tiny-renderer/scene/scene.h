#pragma once 

#ifndef TINYRENDERER_SCENES_SCENE_H
#define TINYRENDERER_SCENES_SCENE_H

#include <vector>
#include <memory>
#include <tiny-renderer/shapes/shape.h>
#include <tiny-renderer/light/light.h>

namespace TinyRenderer {
  class Scene {
  public:
    std::vector<std::shared_ptr<Shape>> aggregate;
    std::vector<std::shared_ptr<Light>> light;
    void AddObject(const std::shared_ptr<Shape>& obj);
    bool Intersect(const Ray*, SurfaceInteraction*) const;
  };
}

#endif // TINYRENDERER_SCENES_SCENE_H
