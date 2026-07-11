/*
 * Main for tiny renderer
 */

#include <iostream>
#include <memory>
#include "tiny-renderer/camera/camera.h"
#include "tiny-renderer/film/film.h"
#include "tiny-renderer/scene/scene.h"
#include "tiny-renderer/shapes/shape.h"
#include "tiny-renderer/shapes/sphere.h"
#include "tiny-renderer/camera/pinhole_camera.h"
#include "tiny-renderer/shapes/sphere.h"

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;

  TinyRenderer::Point3<double> p;
  TinyRenderer::Point2<int> resolution(480, 480);
  std::string of(argv[1]);
  TinyRenderer::PinholeCamera camera(1, 1, p, resolution, of); 
  TinyRenderer::Scene scene; 
  scene.AddObject(
    std::make_shared<TinyRenderer::Sphere>(
      TinyRenderer::Sphere(TinyRenderer::Point3<double>(0, 0, 0.5), 0.2)
    )
  );

  // Rendering loop here
  // TODO: Add this

  camera.Render(scene);
  camera.WriteImage();
  return 0;
}
