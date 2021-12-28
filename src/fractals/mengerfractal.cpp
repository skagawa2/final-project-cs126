#include "mengerfractal.h"

using glm::vec3;
using std::max;
using std::min;

// http://iquilezles.org/www/articles/distfunctions/distfunctions.htm
double MengerFractal::GetDistance(vec3 point) {
  return GetDistance(pos_, point, size_, levels_);
}

double MengerFractal::GetDistance(vec3 center, vec3 point, double size,
                                  int currlevel) {
  if (currlevel < 1) {
    return 1e16; // arbitrarily large number
  }

  double maxDist = size * sqrt(3) / 2;
  double boxDist = BoxDistance(center, point, size, size, size);
  if (glm::length(point - center) - boxDist > maxDist) {
    return maxDist;
  }

  if (currlevel == 1) {
    // find distance to a box with the cross subtracted
    // make big box
    // max(box, -cross) -> subtract cross from box
    return glm::max(boxDist, -CrossDistance(center, point, size));

  } else {
    // recursively create smaller boxes at each of the 20 other locations
    // small optimization: only check on the side that the point is on
    bool half[] = {
      point.x - center.x > 0,
      point.y - center.y > 0,
      point.z - center.z > 0
    };
    for (int i = half[0] ? 0 : -1; i <= half[0] ? 1 : 0; ++i) {
      for (int j = half[1] ? 0 : -1; j <= half[1] ? 1 : 0; ++j) {
        for (int k = half[2] ? 0 : -1; k <= half[2] ? 1 : 0; ++k) {
          if (abs(i) + abs(j) + abs(k) <= 1) {
            continue;
          }

          // create smaller crosses here
          vec3 newCenter = center + size / 3.0 * vec3(i, j, k);
          // min adds objects together
          maxDist = glm::min(
              maxDist, GetDistance(newCenter, point, size / 3.0, currlevel - 1));
        }
      }
    }
    return maxDist;
  }
}

// same as Box::GetDistance(), wasn't sure if faster to do calculations or
// create objects and call the GetDistance method
double MengerFractal::BoxDistance(vec3 boxCenter, vec3 point, double w,
                                  double h, double d) {
  vec3 dist = glm::abs(point - boxCenter) - vec3(w / 2, h / 2, d / 2);
  return glm::length(glm::max(dist, vec3(0.0)))
         + glm::min(glm::max(glm::max(dist.x, dist.y), dist.z), 0.0f);
}

double MengerFractal::CrossDistance(vec3 boxCenter, vec3 point, double size) {
  // gets the minimum distance of 3 elongated Boxes
  return glm::min(glm::min(
    BoxDistance(boxCenter, point, size + 0.5, size / 3.0, size / 3.0),
    BoxDistance(boxCenter, point, size / 3.0, size + 0.5, size / 3.0)),
    BoxDistance(boxCenter, point, size / 3.0, size / 3.0, size + 0.5)
  );
}
