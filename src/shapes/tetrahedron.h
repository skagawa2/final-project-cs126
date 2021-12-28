#pragma once

#include "ofMain.h"
#include "shape.h"

class Tetrahedron : public Shape {
  static double constexpr kREFLECT_RATIO = 0.1;
  double radius_;
  glm::vec3 rotation_;

  glm::vec3 RotatePoint(glm::vec3 point, glm::vec3 about, glm::vec3 rotation);
  glm::vec2 RotatePoint(glm::vec2 point, glm::vec2 about, double rotation);

public:
  Tetrahedron(glm::vec3 pos, ofColor col, double r)
      : Shape("Tetrahedron", pos, col, kREFLECT_RATIO), radius_(r),
        rotation_(glm::vec3(0)) {}
  Tetrahedron(glm::vec3 pos, ofColor col, double r, glm::vec3 rotation)
      : Shape("Tetrahedron", pos, col, kREFLECT_RATIO), radius_(r),
        rotation_(rotation) {}

  double GetDistance(glm::vec3 point);
  ~Tetrahedron(){};
};
