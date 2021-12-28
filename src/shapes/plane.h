#pragma once

#include "ofMain.h"
#include "shape.h"

class Plane : public Shape {
  static double constexpr kREFLECT_RATIO = 0.1;
  double y_;

public:
  Plane(double y, ofColor col) :
    Shape("Plane", glm::vec3(0, y, 0), col, kREFLECT_RATIO), y_(y) {}
  double GetDistance(glm::vec3 point);
  ~Plane(){};
};
