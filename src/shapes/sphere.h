#pragma once

#include "ofMain.h"
#include "shape.h"

class Sphere : public Shape {
  static double constexpr kREFLECT_RATIO = 0.5;
  double r_;

public:
  Sphere(glm::vec3 pos, ofColor col, double rad) :
    Shape("Sphere", pos, col, kREFLECT_RATIO), r_(rad){}
  Sphere(std::string type, glm::vec3 pos, ofColor col, double rad) :
    Shape(type, pos, col, kREFLECT_RATIO), r_(rad) {}

  double GetDistance(glm::vec3 point);
  ~Sphere(){};
};
