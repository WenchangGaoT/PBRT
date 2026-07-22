#include <tiny-renderer/camera/pinhole_camera.h>
#include <iostream>

namespace TinyRenderer {
  PinholeCamera::PinholeCamera(double filmWidth, double filmHeight, const Point3<double>& p, const Point2<int>& r, const std::string& of):
    Camera(p, r, of), filmWidth(filmWidth), filmHeight(filmHeight) {}
  
  PinholeCamera::PinholeCamera(const CameraInitPose& cip, const FilmInitParams& fip, 
  const double filmWidth, const double filmHeight): Camera(cip, fip) {
    this->filmWidth = filmWidth; 
    this->filmHeight = filmHeight;
  }

  double PinholeCamera::GenerateRay(CameraSample& cSample, Ray* ray) const {
    ray->SetPosition(Point3<double>(0, 0, 0));
    Point2<double> pFilm = cSample.pFilm;
    double pSampleCameraX = filmWidth / 2 - filmWidth / film->GetResolution()[0] * pFilm[0];
    double pSampleCameraY = filmHeight / 2 - filmHeight / film->GetResolution()[1] * pFilm[1];
    Vector3<double> dir(-pSampleCameraX, -pSampleCameraY, 1);
    ray->SetDirection(dir);
    return 1;
  }

  void PinholeCamera::Render(Scene& scene) {
    Point2<int> imgResolution = film->GetResolution();
    for (int i = 0; i < imgResolution[0]; i++) {
      for (int j = 0; j < imgResolution[1]; j++) {
        Ray ray;
        CameraSample cSample({
          Point2<double>(i+0.5, j+0.5),
          Point2<double>(0, 0), 
          0
        });
        bool weight = GenerateRay(cSample, &ray);
        ray = WorldFromCamera.ApplyTransform(ray);
        SurfaceInteraction hit;
        bool intersected = scene.Intersect(&ray, &hit);
        if (intersected) {
          film->SetPixel(Point2<int>(i, j), Pixel({255, 255, 255}));
        }
      }
    }
  }

  // Old implementation that directly generates rays in world space
  // double PinholeCamera::GenerateRay(CameraSample& cSample, Ray* ray) const {
  //   ray->SetPosition(this->pos);
  //   Point2<double> pFilm = cSample.pFilm;
  //   double pSampleCameraX = filmWidth / 2 - filmWidth / film->GetResolution()[0] * pFilm[0];
  //   double pSampleCameraY = filmHeight / 2 - filmHeight / film->GetResolution()[1] * pFilm[1];
  //   Vector3<double> dir(-pSampleCameraX, -pSampleCameraY, 1);
  //   ray->SetDirection(dir);
  //   return 1;
  // }
  // void PinholeCamera::Render(Scene& scene) {
  //   Point2<int> imgResolution = film->GetResolution();
  //   for (int i = 0; i < imgResolution[0]; i++) {
  //     for (int j = 0; j < imgResolution[1]; j++) {
  //       Ray ray;
  //       CameraSample cSample({
  //         Point2<double>(i+0.5, j+0.5),
  //         Point2<double>(0, 0), 
  //         0
  //       });
  //       bool weight = GenerateRay(cSample, &ray);
  //       SurfaceInteraction hit;
  //       bool intersected = scene.Intersect(&ray, &hit);
  //       if (intersected) {
  //         film->SetPixel(Point2<int>(i, j), Pixel({255, 255, 255}));
  //       }
  //     }
  //   }
  // }
}
