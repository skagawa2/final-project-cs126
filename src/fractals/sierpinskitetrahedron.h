#pragma once

#include "../shapes/shape.h"

class SierpinskiTetrahedron : public Shape {
  static double constexpr kREFLECT_RATIO = 0.1;
  double radius_;
  double levels_;

  double GetDistance(glm::vec3 center, glm::vec3 point, double radius,
                     double currlevel);

public:
  SierpinskiTetrahedron(glm::vec3 pos, ofColor col, double r, double levels)
      : Shape("SierpinskiTetrahedron", pos, col, kREFLECT_RATIO), radius_(r),
        levels_(levels) {}

  double GetDistance(glm::vec3 point);
  ~SierpinskiTetrahedron(){};
};
