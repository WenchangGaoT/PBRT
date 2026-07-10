#pragma once

#ifndef TINYRENDERER_CAMERA_CAMERA_H
#define TINYRENDERER_CAMERA_CAMERA_H

#include <tiny-renderer/transforms/transform.h>
#include <tiny-renderer/math/vector.h>
#include <tiny-renderer/math/point.h>
#include <tiny-renderer/math/ray.h>
#include <tiny-renderer/film/film.h>
#include <string>

namespace TinyRenderer {

  struct CameraSample {
    Point2<double> pFilm; 
    Point2<double> pLens;
    double time;
  };

  class Camera {
  private:
    Point3<double> pos;
    Film* film;
  
  public:
    Camera(); 
    Camera(const Point3<double>& p, const Point2<int>& res, const std::string& of); 
    ~Camera();
    virtual double GenerateRay(CameraSample& sample, Ray* ray) const;
    virtual void WriteImage() const;
  };

};

#endif // TINYRENDERER_CAMERA_CAMERA_H
