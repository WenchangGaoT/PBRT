#include <tiny-renderer/math/geometry.h>

namespace TinyRenderer {
  template <typename T> inline Vector3<T> Normalize(Vector3<T> &v) {
    return v / v.Length();
  }

  template <typename T> inline T MinComponent(const Vector3<T>& v) {
    return std::min(v.x, std::min(v.y, v.z));
  }

  template <typename T> inline T MaxComponent(const Vector3<T>& v) {
    return std::max(v.x, std::max(v.y, v.z));
  }
}