#pragma once

#include "ofMain.h"

class Shape {
  ofColor col_;
  std::string type_;
  double reflect_;

protected:
  glm::vec3 pos_;

public:
  Shape(std::string type, glm::vec3 pos, ofColor col, double reflect)
    : col_(col), type_(type), reflect_(reflect), pos_(pos){}

  // GETTERS
  ofColor GetColor() { return col_; }
  glm::vec3 GetPos() { return pos_; }
  std::string GetType() { return type_; }
  double GetReflectionRatio() { return reflect_; }

  // SETTERS
  void SetPos(glm::vec3 pos) { pos_ = pos; }

  // VIRTUAL FUNCTIONS
  virtual ~Shape(){};
  virtual double GetDistance(glm::vec3 point) = 0;

  friend bool operator==(const Shape &s1, const Shape &s2);
};
