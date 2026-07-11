#include "tiny-renderer/camera/camera.h" 

namespace TinyRenderer {
  Camera::Camera(): pos(), film(nullptr) {}

  Camera::Camera(const Point3<double>& p, const Point2<int>& res, const std::string& of) {
    pos = p;
    film = new Film(res, of);
  }

  Camera::~Camera() {
    delete film;
  }

  double Camera::GenerateRay(CameraSample& sample, Ray* ray) const {
    (void) sample;
    (void) ray;
    return 0;
  }

  void Camera::WriteImage() const {
    film->WriteImage();
  }

  void Camera::Render(Scene& scene) {
    Point2<int> res = film->GetResolution();
    int imageX = res[0], imageY = res[1];

    for (int i = 0; i < imageX; i++) {
      for (int j = 0; j < imageY; j++) {
        Vector3<double> dir(imageX, imageY, -1);
        Ray r(this->pos, dir, 1000);
        Point2<double> pFilm;
        Point2<double> pLens;
        CameraSample cSample({pFilm, pLens, 0}); 
        double weight = this->GenerateRay(cSample, &r);
      }
    }
  }
}
