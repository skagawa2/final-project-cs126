#include "ofApp.h"
#include "ofMain.h"

#include "shapes/box.h"
#include "shapes/light.h"
#include "shapes/plane.h"
#include "shapes/sphere.h"

#include <algorithm>
#include <cmath>
#include <future>

using glm::vec2;
using glm::vec3;
using std::queue;
using std::shared_ptr;

vec3 ofApp::GetSurfaceNormal(vec3 point, shared_ptr<Shape> closestShape) {
  // http://iquilezles.org/www/articles/normalsSDF/normalsSDF.htm
  double epsilon = 1e-2;
  vec3 vertex1 = vec3(1, -1, -1) *
                 closestShape->GetDistance(point + epsilon * vec3(1, -1, -1));
  vec3 vertex2 = vec3(-1, -1, 1) *
                 closestShape->GetDistance(point + epsilon * vec3(-1, -1, 1));
  vec3 vertex3 = vec3(-1, 1, -1) *
                 closestShape->GetDistance(point + epsilon * vec3(-1, 1, -1));
  vec3 vertex4 = vec3(1, 1, 1) *
                 closestShape->GetDistance(point + epsilon * vec3(1, 1, 1));
  return glm::normalize(vertex1 + vertex2 + vertex3 + vertex4);
}

void ofApp::UpdatePixels(int minWidth, int maxWidth, int minHeight,
                         int maxHeight, double rho, double theta, double phi) {

  // for the async tasks
//  queue<std::future<ofColor>> handles;

  int max = std::max(WIDTH, HEIGHT);
  for (int y = minHeight; y < maxHeight; ++y) {
    for (int x = minWidth; x < maxWidth; ++x) {
      double xAngle = ofMap(x, 0, max - 1, -kHORIZ_FOV / 2, kHORIZ_FOV / 2);
      double yAngle = ofMap(y, 0, max - 1, -kVERT_FOV / 2, kVERT_FOV / 2);

      // EXPLORING DIFFERENT TYPES OF VIEW PLANES
      // sphere inner view plane
      double horizAngle = theta + xAngle;
      double vertAngle = phi + yAngle;
      // spherical coordinates to cartesian direction vector
      vec3 direction = vec3(rho * glm::sin(vertAngle) * glm::sin(horizAngle),
                            rho * glm::cos(vertAngle),
                            rho * glm::sin(vertAngle) * glm::cos(horizAngle));

      img_.setColor(x, y, RayMarch(cameraPos_, direction, 0));
    }
  }
}

ofColor ofApp::RayMarch(vec3 start, vec3 direction, int numReflections) {
  if (numReflections > kMAX_REFLECTIONS) {
    return ofColor::black;
  }

  double distFromOrigin = 0;
  // for each step along the ray...
  for (int step = 0; step < kMAX_MARCH_STEP; ++step) {
    if (distFromOrigin > kMAX_DIST) {
      break;
    }
    // find the point at the end of the ray
    vec3 point = start + direction * distFromOrigin;
    // find the closest shape to that point
    pair<shared_ptr<Shape>, double> closestShape = FindClosestShape(point);
    if (closestShape.first == nullptr) {
      break;
    }
    // then figure out the distance to that closest point
    double dist = closestShape.second;
    if (dist < kMIN_DIST) {
      vec3 surfaceNormal = GetSurfaceNormal(point, closestShape.first);
      ofColor lightCol =
          GetLightColor(start, surfaceNormal); // combined light colors

      vec3 newDirection = glm::reflect(direction, surfaceNormal);

      // get the point out of the actual shape so the distance isn't
      // less than kMIN_DIST anymore
      vec3 newMarchingPoint = point - direction;

      // reflect the light ray
      double reflectRatio = closestShape.first->GetReflectionRatio();
      return ((1 - reflectRatio) *
                  ((1 - kLIGHT_RATIO) * closestShape.first->GetColor() +
                   kLIGHT_RATIO * lightCol) +
              reflectRatio *
                  RayMarch(newMarchingPoint, newDirection, numReflections + 1));
    }
    // march in the direction
    distFromOrigin += dist;
  }
  return kSKY_COLOR;
}

ofColor ofApp::GetLightColor(vec3 point, vec3 normal) {
  // calculate the light color by iterating through all lights, figuring out
  // each of their color weights (diffusion intensity) and adding them up.
  if (world_->GetLights().size() == 0) {
    return ofColor::black;
  }

  vector<ofColor> colors;
  vector<double> weights;
  double sumWeights = 0;

  for (int i = 0; i < world_->GetLights().size(); ++i) {
    // http://www.michaelwalczyk.com/blog/2017/5/25/ray-marching
    vec3 directionToLight = glm::normalize(point - world_->GetLights()[i]->GetPos());
    double diffusionItensity =
        std::max(0.0f, glm::dot(directionToLight, point));

    weights.push_back(diffusionItensity);
    sumWeights += diffusionItensity;
    colors.push_back(world_->GetLights()[i]->GetColor());
  }

  ofColor blendedColor = colors[0] * weights[0] / sumWeights;
  for (int i = 1; i < colors.size(); ++i) {
    blendedColor += colors[i] * weights[i] / sumWeights;
  }
  return blendedColor;
}

pair<shared_ptr<Shape>, double> ofApp::FindClosestShape(vec3 point) {
  if (world_->GetShapes().size() == 0) {
    return pair<shared_ptr<Shape>, double>(nullptr, 0);
  }

  double minDist = world_->GetShapes()[0]->GetDistance(point);
  shared_ptr<Shape> minDistShape = world_->GetShapes()[0];

  for (int i = 1; i < world_->GetShapes().size(); ++i) {
    double dist = world_->GetShapes()[i]->GetDistance(point);
    if (dist < minDist) {
      minDist = dist;
      minDistShape = world_->GetShapes()[i];
    }
  }
  return pair<shared_ptr<Shape>, double>(minDistShape, minDist);
}
