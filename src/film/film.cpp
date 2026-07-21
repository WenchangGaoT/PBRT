#include "tiny-renderer/film/film.h"

#include <filesystem>

namespace TinyRenderer {
  void Film::SetResolution(const Point2<int>& res) {
    this->resolution = res;
  }

  void Film::SetOutputFile(const std::string& o) {
    this->filename = o;
  }

  void Film::WriteImage() const{
    const std::filesystem::path outputPath(filename);
    const std::filesystem::path outputDirectory = outputPath.parent_path();

    if (!outputDirectory.empty()) {
      std::error_code error;
      std::filesystem::create_directories(outputDirectory, error);
      if (error) {
        throw std::runtime_error(
          "Failed to create output directory " + outputDirectory.string() +
          ": " + error.message()
        );
      }
    }

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
