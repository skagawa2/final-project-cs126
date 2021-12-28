#include "worlds/demoworld.h"

#include "shapes/box.h"
#include "shapes/light.h"
#include "shapes/plane.h"
#include "shapes/sphere.h"
#include "shapes/tetrahedron.h"
#include "shapes/torus.h"

using glm::vec3;

double Map(double value, double origMin, double origMax, double outMin,
           double outMax) {
  return outMin + (outMax - outMin) * ((value - outMin) / (outMax - outMin));
}

DemoWorld::DemoWorld() {
  shapes_.push_back(shared_ptr<Shape>(new Plane(0, ofColor::darkRed)));
  shapes_.push_back(
      shared_ptr<Shape>(new Sphere(vec3(0, 5, 3), ofColor::red, 1)));

  l = shared_ptr<Light>(new Light(vec3(0, 2, 5), ofColor::yellow));
  lights_.push_back(l);
  lights_.push_back(
      shared_ptr<Light>(new Light(vec3(4, 1, 0), ofColor::azure)));

  c = shared_ptr<Sphere>(new Sphere(vec3(0, 1, 6), ofColor::blue, 1));
  c2 = shared_ptr<Sphere>(new Sphere(vec3(-3, 1.5, 1), ofColor::purple, 0.5));
  shapes_.push_back(c);
  shapes_.push_back(c2);

  shapes_.push_back(
      shared_ptr<Shape>(new Sphere(vec3(-2, 1, 1.5), ofColor::yellow, 1)));
  shapes_.push_back(
      shared_ptr<Shape>(new Sphere(vec3(5, 2.5, 2.5), ofColor::coral, 2)));

  shapes_.push_back(shared_ptr<Shape>(
      new Box(vec3(-5, 2.5, -2.5), ofColor::burlyWood, 2, 3, 4)));
  shapes_.push_back(
      shared_ptr<Shape>(new Box(vec3(0, 5, -3), ofColor::deepPink, 3, 1, 2)));

  shapes_.push_back(shared_ptr<Shape>(
      new Torus(vec3(5, 2.5, -2.5), ofColor::red, 0.5, 0.25)));
  shapes_.push_back(
      shared_ptr<Shape>(new Torus(vec3(0, 8, -3), ofColor::green, 0.75, 0.1)));

  shapes_.push_back(
      shared_ptr<Shape>(new Tetrahedron(vec3(0, 3, 5), ofColor::blue, 3)));
}

void DemoWorld::Update(long millis) {
  vec3 currCPos = c->GetPos();
  double changedY2 = Map(sin(millis), -1, 1, 1, 6);
  c->SetPos(vec3(currCPos.x, changedY2, currCPos.z));

  vec3 currCPos2 = c2->GetPos();
  double changedX2 = Map(sin(millis), -1, 1, -10, 6);
  c2->SetPos(vec3(changedX2, currCPos2.y, currCPos2.z));

  l->SetPos(vec3(l->GetPos().x, ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 10),
                 l->GetPos().z));
}
