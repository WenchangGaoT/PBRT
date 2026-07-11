#include "tiny-renderer/film/film.h"

namespace TinyRenderer {
  void Film::WriteImage() const{
    std::ofstream out(filename);
    if (!out) {
      throw std::runtime_error("Failed to open output image file: " + filename);
    }

    const int width = resolution[0];
    const int height = resolution[1];

    out << "P3\n";
    out << width << " " << height << "\n";
    out << "255\n";

    for (int y = 0; y < height; ++y) {
      for (int x = 0; x < width; ++x) {
        out << pixels[y * width + x].String() << "\n";
      }
    }
  }

  Point2<int> Film::GetResolution() const {
    return resolution;
  }

  void Film::SetPixel(const Point2<int>& pos, const Pixel& pixel) {
    int index = pos[1] * resolution[0] + pos[0];
    pixels[index] = pixel;
  }
}
