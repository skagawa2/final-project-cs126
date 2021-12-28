#pragma once

#include "worlds/world.h"

#include "shapes/light.h"
#include "shapes/shape.h"

class DemoWorld : public World {

  std::shared_ptr<Light> l;
  std::shared_ptr<Shape> c;
  std::shared_ptr<Shape> c2;

public:
  DemoWorld();
  void Update(long millis);
};
