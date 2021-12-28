#include "plane.h"

using glm::vec3;

double Plane::GetDistance(vec3 point) {
  return abs(point.y - y_);
}
