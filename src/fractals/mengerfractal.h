#pragma once

#include "../shapes/shape.h"

class MengerFractal : public Shape {
  static double constexpr kREFLECT_RATIO = 0.1;
  double size_;
  double levels_;

  double BoxDistance(glm::vec3 boxCenter, glm::vec3 point, double w, double h,
                     double d);
  double CrossDistance(glm::vec3 boxCenter, glm::vec3 point, double size);
  double GetDistance(glm::vec3 center, glm::vec3 point, double size,
                     int currlevel);

public:
  MengerFractal(glm::vec3 pos, ofColor col, double size, double levels)
      : Shape("Box", pos, col, kREFLECT_RATIO), size_(size), levels_(levels) {}

  double GetDistance(glm::vec3 point);
  ~MengerFractal(){};
};
