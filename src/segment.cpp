
#include <segment.hpp>

namespace geo {

  Segment::Segment (const Segment& s) : a_ (s.a_), b_ (s.b_) {};

  Segment::Segment (const Point& a, const Point& b) : a_ (a), b_ (b) {};

  Segment& Segment::operator= (const Segment& s) {
    a_ = s.a_;
    b_ = s.b_;
    return *this;
  };

  double_t Segment::length (void) const {
    return std::sqrt (((b_.y () - a_.y ()) * (b_.y () - a_.y ())) +
      ((b_.x () - a_.x ()) * ((b_.x () - a_.x ()))));
  };

  const Fraction Segment::slope (void) const {
    return Fraction ((b_.y () - a_.y ()), (b_.x () - a_.x ()));
  };

};

