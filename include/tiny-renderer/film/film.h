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
  };

  class Film {
  private: 
    const Point2<int> resolution; 
    const std::string filename;
    std::unique_ptr<Pixel[]> pixels;

  public: 
    Film(const Point2<int>& res, const std::string &filename): resolution(res), filename(filename) {}
    virtual void WriteImage() const; 
 };
}

#endif // TYNYRENDERER_FILM_FILM_H
