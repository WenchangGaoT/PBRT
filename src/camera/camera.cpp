#include "tiny-renderer/camera/camera.h" 

namespace TinyRenderer {
  Camera::Camera(): pos(), film(nullptr) {}

  Camera::Camera(const Point3<double>& p, const Point2<int>& res, const std::string& of) {
    pos = p;
    film = new Film(res, of);
  }

  Camera::Camera(const Point3<double>& p, const Vector3<double>& lookat, const Vector3<double>& y,
    const Point2<int>& res, const std::string& of) {
    GetCameraTransform(p, lookat, y, &CameraFromWorld, &WorldFromCamera);
    film = new Film(res, of);
  }

  Camera::Camera(const CameraInitPose& cip, const FilmInitParams& fip) {
    GetCameraTransform(cip.pWorld, cip.zWorld, cip.yWorld, &CameraFromWorld, &WorldFromCamera);
    film = new Film(fip.resolution, fip.outFile);
  }

  void GetCameraTransform(const Point3<double>& p, const Vector3<double>& z, const Vector3<double>& y,
                                Transform* cameraFromWorld, Transform* worldFromCamera) {
    Vector3<double> zn = z.Normalize(), yn = y.Normalize();
    Vector3<double> x = yn.Cross(zn);
    Vector3<double> xn = x.Normalize();
    SquareMatrix3<double> rotation;
    rotation.SetValue(0, 0, xn[0]);
    rotation.SetValue(0, 1, xn[1]);
    rotation.SetValue(0, 2, xn[2]);
    rotation.SetValue(1, 0, yn[0]);
    rotation.SetValue(1, 1, yn[1]);
    rotation.SetValue(1, 2, yn[2]);
    rotation.SetValue(2, 0, zn[0]);
    rotation.SetValue(2, 1, zn[1]);
    rotation.SetValue(2, 2, zn[2]);
    Point3<double> translation = rotation.Multiply(p);
    cameraFromWorld->SetRotation(rotation);
    cameraFromWorld->SetTranslation(-translation);
    worldFromCamera->SetRotation(rotation.Transpose());
    worldFromCamera->SetTranslation(p);
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
      }
    }
  }
}
