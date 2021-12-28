#include "worlds/fractalworld.h"

#include "fractals/mengerfractal.h"
#include "fractals/sierpinskitetrahedron.h"
#include "shapes/plane.h"

using glm::vec3;

FractalWorld::FractalWorld() {
  shapes_.push_back(shared_ptr<Shape>(new Plane(0, ofColor::darkRed)));

  // shapes_.push_back(shared_ptr<Shape>(
  //       new MengerFractal(vec3(0, 5, 3), ofColor::lightGreen, 5, 3)));
  shapes_.push_back(shared_ptr<Shape>(
      new SierpinskiTetrahedron(vec3(0, 5, 3), ofColor::orange, 5, 4)));
}

void FractalWorld::Update(long millis) {}
