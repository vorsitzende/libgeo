
#include <triangle.hpp>
#include <segment.hpp>
#include <vector>

namespace geo {

  const Point& Triangle::highest (void) const {
    const Point* retval;
    a_.y () > b_.y () ? retval = &a_ : retval = &b_;
    if (retval->y () < c_.y ())
      retval = &c_;
    return *retval;
  };

  const Point& Triangle::lowest (void) const {
    const Point* retval;
    a_.y () < b_.y () ? retval = &a_ : retval = &b_;
    if (retval->y () > c_.y ())
      retval = &c_;
    return *retval;
  };

  const Point& Triangle::leftest (void) const {
    const Point* retval;
    a_.x () < b_.x () ? retval = &a_ : retval = &b_;
    if (retval->x () > c_.x ())
      retval = &c_;
    return *retval;
  };

  const Point& Triangle::rightest (void) const {
    const Point* retval;
    a_.x () > b_.x () ? retval = &a_ : retval = &b_;
    if (retval->x () < c_.x ())
      retval = &c_;
    return *retval;
  };

  Triangle& Triangle::operator= (const Triangle& tri) {
    a_ = tri.a_;
    b_ = tri.b_;
    c_ = tri.c_;
    return *this;
  };

  const Point Triangle::center (void) const {
    return Point (Segment (Segment (a_, b_).mid (), c_).mid ());
  };

  double_t Triangle::area (void) const {
    return ((highest ().y () - lowest ().y ()) *
      (rightest ().x () - leftest ().x ())) / 2;
  };

  double_t Triangle::perimeter (void) const {
    return Segment (a_, b_).length () + Segment (a_, c_).length () +
      Segment (b_, c_).length ();
  };

};

