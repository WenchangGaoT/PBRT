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
#include "tiny-renderer/parser/parser.h"

int main(int argc, char** argv) {

  TinyRenderer::JsonParser parser;
  std::vector<std::shared_ptr<TinyRenderer::Camera>> cameras;
  TinyRenderer::Scene scene;
  parser.ParseJsonFile("scenes/test.json", cameras, scene);


  // TinyRenderer::Point3<double> p;
  // TinyRenderer::Point2<int> resolution(1024, 1024);

  // TinyRenderer::CameraInitPose cip(
  //   TinyRenderer::Point3<double>(0.1, 0.1, 0.1),
  //   TinyRenderer::Vector3<double>(0, 0, 1), 
  //   TinyRenderer::Vector3<double>(0, 1, 0)
  // );
  // TinyRenderer::FilmInitParams fip(
  //   TinyRenderer::Point2<int>(1024, 1024), 
  //   std::string("outputs/test2.ppm")
  // );

  // TinyRenderer::PinholeCamera camera(cip, fip, 1, 1); 
  // TinyRenderer::Scene scene; 
  // scene.AddObject(
  //   std::make_shared<TinyRenderer::Sphere>(
  //     TinyRenderer::Sphere(TinyRenderer::Point3<double>(0, 0, 0.5), 0.2)
  //   )
  // );
  for (const std::shared_ptr<TinyRenderer::Camera>& c : cameras) {
    c->Render(scene); 
    c->WriteImage();
  }
  return 0;
}
