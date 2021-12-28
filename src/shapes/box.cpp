#include "box.h"

using glm::vec3;
using std::min;
using std::max;

// http://iquilezles.org/www/articles/distfunctions/distfunctions.htm
double Box::GetDistance(vec3 point) {
  vec3 d = glm::abs(point - pos_) - vec3(height_ / 2, width_ / 2, depth_ / 2);
    return glm::length(glm::max(d, vec3(0.0)));// +
//    glm::min( glm::max(d.x, d.y, d.z), 0.0f);
}
