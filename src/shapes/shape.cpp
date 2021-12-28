#include "shape.h"

bool operator==(const Shape& s1, const Shape& s2) {
  return s1.pos_ == s2.pos_;
}
