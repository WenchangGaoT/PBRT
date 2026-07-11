#include <tiny-renderer/scene/scene.h>

namespace TinyRenderer {
  void Scene::AddObject(const std::shared_ptr<Shape>& obj) {
    aggregate.push_back(obj);
  }

  bool Scene::Intersect(const Ray* ray, SurfaceInteraction* hit) const {
    bool intersected = false;
    for(const auto& o: aggregate) {
      SurfaceInteraction localHit;
      if (o->Intersect(ray, &localHit)) {
        intersected = true;
        if (localHit.t < hit->t) // make sure the hit is the closest hit
          *hit = localHit;
      }
    }
    return intersected;
  }
}
