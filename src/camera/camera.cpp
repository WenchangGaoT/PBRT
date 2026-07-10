#include "tiny-renderer/camera/camera.h" 

namespace TinyRenderer {
  Camera::Camera(): pos(), film(nullptr) {}

  Camera::Camera(const Point3<double>& p, const Point2<int>& res, const std::string& of) {
    pos = p;
    film = new Film(res, of);
  }

  Camera::~Camera() = default;

  double Camera::GenerateRay(CameraSample& sample, Ray* ray) const {
    (void) sample;
    (void) ray;
    return 0;
  }

  void Camera::WriteImage() const {
    film->WriteImage();
  }
}
