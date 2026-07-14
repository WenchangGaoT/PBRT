#pragma once
#ifndef TINYRENDERER_CAMRERA_PINHOLE_CAMERA_H
#define TINYRENDERER_CAMRERA_PINHOLE_CAMERA_H

#include <tiny-renderer/camera/camera.h>

namespace TinyRenderer {
  class PinholeCamera: public Camera {
    double filmWidth, filmHeight; // Film width and height in camera space

  public: 
    PinholeCamera(): Camera(), filmWidth(0), filmHeight(0) {}
    PinholeCamera(double filmWidth, double filmHeight, const Point3<double>& p, const Point2<int>& r, const std::string& of);
    PinholeCamera(const CameraInitPose&, const FilmInitParams&, double filmWidth, double filmHeight);
    double GenerateRay(CameraSample& c, Ray* ray) const override;
    void Render(Scene&) override;
  };
}

#endif // TINYRENDERER_CAMRERA_PINHOLE_CAMERA_H