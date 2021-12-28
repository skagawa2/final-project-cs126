#include "torus.h"

using glm::vec2;
using glm::vec3;

// http://iquilezles.org/www/articles/distfunctions/distfunctions.htm
double Torus::GetDistance(vec3 point) {
  // torus on X-Z axis
  vec2 q = vec2(
      glm::length(vec2(point.x - pos_.x,
                       point.z - pos_.z))
                        - radiusOut_,
      point.y - pos_.y);
  return glm::length(q) - radiusIn_;
}
