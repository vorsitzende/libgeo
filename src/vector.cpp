
#include <vector.hpp>

namespace geo {

  std::ostream& operator<< (std::ostream& os, const Vector& v) {
    os << "[" << v.a_ << "," << v.b_ << "]";
    return os;
  };

  double_t Vector::length (void) const {
    return Segment (Point (0, 0), Point (a_, b_)).length ();
  };

  Vector& Vector::operator= (const Vector& v) {
    a_ = v.a_;
    b_ = v.b_;
    return *this;
  };

  Vector& Vector::operator+= (const Vector& v) {
    a_ += v.a_;
    b_ += v.b_;
    return *this;
  };

  Vector& Vector::operator-= (const Vector& v) {
    a_ -= v.a_;
    b_ -= v.b_;
    return *this;
  };

};

