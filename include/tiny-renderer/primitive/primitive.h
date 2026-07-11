#pragma once 

#ifndef TINYRENDERER_PRIMITIVE_PRIMITIVE_H
#define TINYRENDERER_PRIMITIVE_PRIMITIVE_H

#include <tiny-renderer/shapes/shape.h>
#include <memory>

namespace TinyRenderer {
  class Primitive {
    std::shared_ptr<Shape[]> shapes;

  };
}

#endif // TINYRENDERER_PRIMITIVE_PRIMITIVE_H