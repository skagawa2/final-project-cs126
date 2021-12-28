#include "sphere.h"

using glm::vec3;

double Sphere::GetDistance(vec3 point) {
  return glm::length(point - pos_) - r_;
}
