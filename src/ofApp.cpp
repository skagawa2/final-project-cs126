#include "ofApp.h"

#include "worlds/demoworld.h"
#include "worlds/fractalworld.h"

#include <future>

using glm::vec3;

//--------------------------------------------------------------
void ofApp::setup() {
  WIDTH = ofGetWidth();
  HEIGHT = ofGetHeight();
  img_.allocate(WIDTH, HEIGHT, OF_IMAGE_COLOR_ALPHA);
  cameraPos_.x = 0;
  cameraPos_.y = 5;
  cameraPos_.z = -10;

  world_ = shared_ptr<World>(new FractalWorld());
}

//--------------------------------------------------------------
void ofApp::update() {
  double lastFrameTime = ofGetElapsedTimef();

  // UPDATE SHAPE POSITIONS
  world_->Update(ofGetElapsedTimef());

  // UPDATE IMAGE PIXELS
  queue<std::future<void>> futures;
  int numPartitions = 2;
  for (int i = 0; i < numPartitions; ++i) {
    for (int j = 0; j < numPartitions; ++j) {
      futures.push(
          std::async(std::launch::async, &ofApp::UpdatePixels, this,
                     WIDTH * i / numPartitions, WIDTH * (i + 1) / numPartitions,
                     HEIGHT * j / numPartitions,
                     HEIGHT * (j + 1) / numPartitions, rho_, theta_, phi_));
    }
  }
  for (int i = 0; i < futures.size(); ++i) {
    futures.front().get();
    futures.pop();
  }

  // UPDATE IMAGE OBJECT
  img_.update();

  // UPDATE FRAMERATE
  std::cout << ofGetElapsedTimef() - lastFrameTime << " seconds to calculate frame"
            << std::endl;
  framerate_ = round(1000.0 / (ofGetElapsedTimef() - lastFrameTime)) / 1000.0;
}

//--------------------------------------------------------------
void ofApp::draw() { img_.draw(0, 0); }

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  double x = kWALK_STEP * glm::sin(phi_) * glm::sin(theta_);
  double z = kWALK_STEP * glm::sin(phi_) * glm::cos(theta_);
  // forward
  if (key == 'w') {
    cameraPos_ += vec3(x, 0, z);
    // backward
  } else if (key == 's') {
    cameraPos_ -= vec3(x, 0, z);
    // right
  } else if (key == 'd') {
    cameraPos_ += vec3(z, 0, -x);
    // left
  } else if (key == 'a') {
    cameraPos_ -= vec3(z, 0, -x);
    // up
  } else if (key == 'q') {
    cameraPos_.y += kWALK_STEP; // 0.1;
    // down
  } else if (key == 'z') {
    cameraPos_.y -= kWALK_STEP; // 0.1;
  }

  if (key == 'i') {
    // look up
    phi_ -= kWALK_STEP; // 0.1;
  } else if (key == 'j') {
    // look left
    theta_ -= kWALK_STEP; // 0.1;
  } else if (key == 'l') {
    // look right
    theta_ += kWALK_STEP; // 0.1;
  } else if (key == 'm') {
    // look down
    phi_ += kWALK_STEP; // 0.1;
  }

  // NOT ZOOMING, JUST MOVING VIEW SPHERE TO AND AWAY FROM CAMERA
  // if (key == 'e') {
  //   // zoom in
  //   rho_ += kWALK_STEP;
  // } else if (key == 'c') {
  //   // zoom out
  //   if (rho_ >= kWALK_STEP) {
  //     rho_ -= kWALK_STEP;
  //   }
  // }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
