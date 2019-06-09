
#ifndef _SEGMENT_HPP_
#define _SEGMENT_HPP_

#include "point.hpp"
#include "fraction.hpp"

namespace geo {

  class Segment {
    Point a_, b_;
  public:
    inline Segment (void) noexcept = default;
    inline ~Segment (void) noexcept = default;
    Segment (const Segment&);
    Segment (const Point&, const Point&);
    Segment& operator= (const Segment&);
    double_t length (void) const;
    inline const Point mid (void) const {
      return Point ((b_.x () - a_.x ()) / 2, (b_.y () - a_.y ()) / 2);
    };
    const Fraction slope (void) const;
    inline const Point& a (void) const { return a_; };
    inline const Point& b (void) const { return b_; };
    inline bool operator== (const Segment& s) const {
      return a_ == s.a_ && b_ == s.b_;
    };
    inline bool operator!= (const Segment& s) const {
      return !this->operator== (s);
    };
    inline operator double_t (void) const { return this->length (); };
  };

};

#endif /* _SEGMENT_HPP_ */
