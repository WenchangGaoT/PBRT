#pragma once

#ifndef TINYRENDERER_CAMERA_CAMERA_H
#define TINYRENDERER_CAMERA_CAMERA_H

#include <tiny-renderer/transforms/transform.h>
#include <tiny-renderer/math/vector.h>
#include <tiny-renderer/math/point.h>
#include <tiny-renderer/math/ray.h>
#include <tiny-renderer/film/film.h>
#include <tiny-renderer/scene/scene.h>
#include <tiny-renderer/math/matrix.h>
#include <string>
#include <memory>
#include <nlohmann/json.hpp>

namespace TinyRenderer {

  struct CameraSample {
    Point2<double> pFilm; 
    Point2<double> pLens;
    double time;
  };

  struct CameraInitPose {
    Point3<double> pWorld; // Location of camera in world space
    Vector3<double> zWorld; // Camera z-axis in world space
    Vector3<double> yWorld; // Camera y-axis in world space

    CameraInitPose(const Point3<double>& p, const Vector3<double> z, const Vector3<double> y):
    pWorld(p), zWorld(z), yWorld(y) {}
  };

  class Camera {
  public:
    Point3<double> pos;
    Film* film = nullptr;
    Transform CameraFromWorld, WorldFromCamera;

    Camera(); 
    Camera(const Point3<double>& p, const Point2<int>& res, const std::string& of); 
    Camera(const Point3<double>& p, const Vector3<double>& lookat, const Vector3<double>& y,
           const Point2<int>& res, const std::string& of); 
    Camera(const CameraInitPose&, const FilmInitParams&);
    virtual ~Camera();
    Camera(const Camera&) = delete;
    Camera& operator=(const Camera&) = delete;
    virtual double GenerateRay(CameraSample& sample, Ray* ray) const;
    virtual void WriteImage() const;
    virtual void Render(Scene&);
  };

  enum class CameraType {
    Invalid = 0,
    Pinhole = 1 << 0,
    Orthographic = 1 << 1,
  };

  NLOHMANN_JSON_SERIALIZE_ENUM(CameraType, {
    {CameraType::Invalid, "invalid"}, 
    {CameraType::Pinhole, "pinhole"}, 
    {CameraType::Orthographic, "orthographic"},
  })

  void GetCameraTransform(const Point3<double>& p, const Vector3<double>& z, const Vector3<double>& y, Transform*, Transform*); 
};

#endif // TINYRENDERER_CAMERA_CAMERA_H
