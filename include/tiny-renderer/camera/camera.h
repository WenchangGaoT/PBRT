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

namespace TinyRenderer {

  struct CameraSample {
    Point2<double> pFilm; 
    Point2<double> pLens;
    double time;
  };

  struct CameraInitPose {
    Point3<double> pWorld; 
    Vector3<double> zWorld;
    Vector3<double> yWorld;

    CameraInitPose(const Point3<double>& p, const Vector3<double> z, const Vector3<double> y):
    pWorld(p), zWorld(z), yWorld(y) {}
  };

  class Camera {
  public:
    Point3<double> pos;
    Film* film;
    Transform CameraFromWorld, WorldFromCamera;

    Camera(); 
    Camera(const Point3<double>& p, const Point2<int>& res, const std::string& of); 
    Camera(const Point3<double>& p, const Vector3<double>& lookat, const Vector3<double>& y,
           const Point2<int>& res, const std::string& of); 
    Camera(const CameraInitPose&, const FilmInitParams&);
    virtual ~Camera();
    virtual double GenerateRay(CameraSample& sample, Ray* ray) const;
    virtual void WriteImage() const;
    virtual void Render(Scene&);
  };

  void GetCameraTransform(const Point3<double>& p, const Vector3<double>& z, const Vector3<double>& y, Transform*, Transform*); 
};

#endif // TINYRENDERER_CAMERA_CAMERA_H
