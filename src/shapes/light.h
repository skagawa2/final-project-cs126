#pragma once

#include "ofMain.h"
#include "sphere.h"

class Light : public Sphere {
  static constexpr double LIGHT_RADIUS = 0.5;

public:
  Light(glm::vec3 pos, ofColor col) :
    Sphere("Light", pos, col, LIGHT_RADIUS){}
  ~Light(){}
};
