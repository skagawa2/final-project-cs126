#pragma once

#include "ofMain.h"

#include "shapes/shape.h"
#include "shapes/light.h"

class World {

protected:
  std::vector<std::shared_ptr<Shape>> shapes_;
  std::vector<std::shared_ptr<Light>> lights_;

public:
  std::vector<std::shared_ptr<Shape>>& GetShapes() { return shapes_; }
  std::vector<std::shared_ptr<Light>>& GetLights() { return lights_; }

  virtual void Update(long millis) = 0;
  virtual ~World() {};
};
