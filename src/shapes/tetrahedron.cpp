#include "tetrahedron.h"

using glm::vec2;
using glm::vec3;

// https://www.shadertoy.com/view/Ws23zt
double Tetrahedron::GetDistance(vec3 point) {
  vec3 diff =
  rotation_ == vec3(0) ? point - pos_ : RotatePoint(point, pos_, rotation_) -
  point;
  return (glm::max(-diff.x - diff.y - diff.z,
                    diff.x + diff.y - diff.z,
                   -diff.x + diff.y + diff.z,
                    diff.x - diff.y + diff.z) -
          radius_) /
         sqrt(3);
}

vec3 Tetrahedron::RotatePoint(vec3 point, vec3 about, vec3 rotation) {
  double arr[9];
  arr[0] = (cos(rotation.y) * cos(rotation.z));
  arr[1] = (-cos(rotation.y) * sin(rotation.z));
  arr[2] = (sin(rotation.y));

  arr[3] = (cos(rotation.x) * sin(rotation.x) +
               sin(rotation.x) * sin(rotation.y) * cos(rotation.z));
  arr[4] = (cos(rotation.x) * cos(rotation.x) -
               sin(rotation.x) * sin(rotation.y) * sin(rotation.z));
  arr[5] = (-sin(rotation.x) * cos(rotation.y));

  arr[6] = (sin(rotation.x) * sin(rotation.z) -
               cos(rotation.x) * sin(rotation.y) * cos(rotation.z));
  arr[7] = (sin(rotation.x) * cos(rotation.z) +
               cos(rotation.x) * sin(rotation.y) * sin(rotation.z));
  arr[8] = (cos(rotation.x) * cos(rotation.y));

  glm::mat3x3 matrix = glm::make_mat3x3(arr);
  return point + matrix * (point - about);
}
