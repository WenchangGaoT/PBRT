#pragma once 

#ifndef TYNYRENDERER_FILM_FILM_H
#define TYNYRENDERER_FILM_FILM_H

#include <tiny-renderer/math/point.h>
#include <string>
#include <memory>
#include <fstream>
#include <stdexcept>

namespace TinyRenderer{ 
  struct Pixel {
    double xyz[3] = {0, 0, 0};

    std::string String() const {
      auto toByte = [](double value) {
        if (value < 0) return 0;
        if (value > 255) return 255;
        return static_cast<int>(value);
      };

      int r = toByte(xyz[0]);
      int g = toByte(xyz[1]);
      int b = toByte(xyz[2]);
      return std::to_string(r) + " " + std::to_string(g) + " " + std::to_string(b);
    }
  };

  class Film {
  private: 
    const Point2<int> resolution; 
    const std::string filename;
    std::unique_ptr<Pixel[]> pixels;

  public: 
    Film(const Point2<int>& res, const std::string &filename):
      resolution(res), filename(filename), pixels(std::make_unique<Pixel[]>(res[0] * res[1])) {}
    Point2<int> GetResolution() const;
    virtual void WriteImage() const; 
    virtual void SetPixel(const Point2<int>&, const Pixel&);
 };
}

#endif // TYNYRENDERER_FILM_FILM_H
