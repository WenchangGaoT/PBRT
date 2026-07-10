/*
 * Main for tiny renderer
 */

#include <iostream>
#include "tiny-renderer/camera/camera.h"
#include "tiny-renderer/film/film.h"
#include "tiny-renderer/scene/scene.h"
#include "tiny-renderer/shapes/shape.h"
#include "tiny-renderer/shapes/sphere.h"

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;

  TinyRenderer::Point3<double> p;
  TinyRenderer::Point2<int> p2;
  std::string of(argv[1]);
  TinyRenderer::Camera camera(p, p2, of); 
  TinyRenderer::Scene scene; 

  // Rendering loop here
  // TODO: Add this

  camera.WriteImage();
  return 0;
}
