#pragma once

#include "ofMain.h"

#include "worlds/world.h"

#include <vector>

class ofApp : public ofBaseApp {

  // CONSTANTS
  const double kMIN_DIST = 0.01;
  const double kMAX_DIST = 50;
  const int kMAX_MARCH_STEP = 50;
  const ofColor kSKY_COLOR = ofColor(255);
  const double kSHADOW_FACTOR = 0.5;
  const double kBLEND_FACTOR = 0.5;
  const double kHORIZ_FOV = glm::pi<double>() * 3 / 4;
  const double kVERT_FOV = glm::pi<double>() * 3 / 4;
  const int kMAX_REFLECTIONS = 3;
  const double kWALK_STEP = 0.1;
  const double kLIGHT_RATIO = 0.2;

  int WIDTH;
  int HEIGHT;
  double framerate_;

  // WORLD
  shared_ptr<World> world_;

  // POSITIONS
  ofImage img_;
  glm::vec3 cameraPos_;
  double rho_ = 1;
  double phi_ = glm::pi<double>() / 2;
  double theta_ = 0;

  // METHODS
  void UpdatePixels(int minWidth, int maxWidth, int minHeight, int maxHeight,
                    double rho, double theta, double phi);
  ofColor RayMarch(glm::vec3 start, glm::vec3 direction, int numReflections);
  ofColor GetLightColor(glm::vec3 point, glm::vec3 normal);
  std::pair<std::shared_ptr<Shape>, double> FindClosestShape(glm::vec3 point);
  glm::vec3 GetSurfaceNormal(glm::vec3 point, shared_ptr<Shape> closestShape);

public:
  void setup();
  void update();
  void draw();

  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void mouseEntered(int x, int y);
  void mouseExited(int x, int y);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);
};
