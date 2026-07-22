#pragma once 

#ifndef TINYRENDERER_PARSER_PARSER_H
#define TINYRENDERER_PARSER_PARSER_H
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <memory>
#include <tiny-renderer/shapes/shape.h>
#include <tiny-renderer/camera/camera.h>
#include <tiny-renderer/camera/pinhole_camera.h>
#include <tiny-renderer/scene/scene.h>
#include <tiny-renderer/math/point.h>
#include <tiny-renderer/math/vector.h>
#include <tiny-renderer/shapes/sphere.h>

namespace TinyRenderer {
  class Parser {

  };

  class JsonParser: public Parser {
  public:
    JsonParser() {} 
    nlohmann::json ParseJsonFile(const std::string&);
    void ParseJsonFile(const std::string&, std::vector<std::shared_ptr<Camera>>&, Scene& ) const;
    void SetCameras(const nlohmann::json&, std::vector<std::shared_ptr<Camera>>&) const;
    void SetScene(const nlohmann::json&, Scene&) const;
    std::shared_ptr<Camera> InstantiateCamera(const nlohmann::json&) const;
    std::shared_ptr<Shape> InstantiateShape(const nlohmann::json&) const;

    // Cameras
    std::shared_ptr<PinholeCamera> InstantiatePinholeCamera(const nlohmann::json&) const;

    // Shapes
    std::shared_ptr<Sphere> InstantiateSphere(const nlohmann::json&) const;
  };
}

#endif // TINYRENDERER_PARSER_PARSER_H