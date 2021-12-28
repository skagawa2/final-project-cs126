#include "sierpinskitetrahedron.h"
#include "../shapes/tetrahedron.h"

using glm::vec3;

double SierpinskiTetrahedron::GetDistance(vec3 point) {
  return GetDistance(pos_, point, radius_, levels_);
}

double SierpinskiTetrahedron::GetDistance(vec3 center, vec3 point,
                                          double radius, double currlevel) {
  if (currlevel < 1) {
    return 1e16; // arbitrarily large number
  }

  if (currlevel == 1) {
    // get distance from tetrahedron minus tetrahedron flipped upside down
    return glm::max(Tetrahedron(center, GetColor(), radius).GetDistance(point),
                    -Tetrahedron(center, GetColor(), radius,
                                 vec3(0, glm::pi<double>() / 2, 0))
                         .GetDistance(point));

  } else {
    double newRadius = radius / 2.0;
    double diff = radius / 2.0;
    return glm::min(
            glm::min(GetDistance(center + vec3(diff, diff, diff), point,
                                 newRadius, currlevel - 1),
                     GetDistance(center + vec3(-diff, -diff, diff), point,
                                 newRadius, currlevel - 1)),
            glm::min(GetDistance(center + vec3(-diff, diff, -diff), point,
                                 newRadius, currlevel - 1),
                     GetDistance(center + vec3(diff, -diff, -diff), point,
                                 newRadius, currlevel - 1)));
  }
}
