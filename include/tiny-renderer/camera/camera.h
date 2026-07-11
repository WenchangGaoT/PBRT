#pragma once

#ifndef TINYRENDERER_CAMERA_CAMERA_H
#define TINYRENDERER_CAMERA_CAMERA_H

#include <tiny-renderer/transforms/transform.h>
#include <tiny-renderer/math/vector.h>
#include <tiny-renderer/math/point.h>
#include <tiny-renderer/math/ray.h>
#include <tiny-renderer/film/film.h>
#include <tiny-renderer/scene/scene.h>
#include <string>

namespace TinyRenderer {

  struct CameraSample {
    Point2<double> pFilm; 
    Point2<double> pLens;
    double time;
  };

  class Camera {
  public:
    Point3<double> pos;
    Film* film;

    Camera(); 
    Camera(const Point3<double>& p, const Point2<int>& res, const std::string& of); 
    virtual ~Camera();
    virtual double GenerateRay(CameraSample& sample, Ray* ray) const;
    virtual void WriteImage() const;
    virtual void Render(Scene&);
  };

};

#endif // TINYRENDERER_CAMERA_CAMERA_H
