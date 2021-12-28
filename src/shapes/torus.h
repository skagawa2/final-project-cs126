#pragma once

#include "ofMain.h"
#include "shape.h"

class Torus : public Shape {
  static double constexpr kREFLECT_RATIO = 0.4;
  double radiusOut_;
  double radiusIn_;

public:
  Torus(glm::vec3 pos, ofColor col, double rO, double rI) :
    Shape("Torus", pos, col, kREFLECT_RATIO), radiusOut_(rO), radiusIn_(rI){}

  double GetDistance(glm::vec3 point);
  ~Torus(){};
};
