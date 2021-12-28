#pragma once

#include "ofMain.h"
#include "shape.h"

class Box : public Shape {
  static double constexpr kREFLECT_RATIO = 0.1;
  double height_;
  double width_;
  double depth_;

public:
  Box(glm::vec3 pos, ofColor col, double h, double w, double d) :
    Shape("Box", pos, col, kREFLECT_RATIO), height_(h), width_(w), depth_(d){}

  double GetDistance(glm::vec3 point);
  ~Box(){};
};
