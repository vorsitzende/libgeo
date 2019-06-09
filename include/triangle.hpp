
#ifndef _TRIANGLE_HPP_
#define _TRIANGLE_HPP_

#include "shape.hpp"

namespace geo {

  class Triangle : Shape {
    Point a_, b_, c_;
    const Point& highest (void) const;
    const Point& lowest (void) const;
    const Point& leftest (void) const;
    const Point& rightest (void) const;
  public:
    inline Triangle (void) noexcept = default;
    inline ~Triangle (void) noexcept = default;
    inline Triangle (const Triangle& tri) noexcept = default;
    inline explicit Triangle (const Point& a, const Point& b, const Point& c)
      noexcept : a_ (a), b_ (b), c_ (c) {};
    inline const Point& a (void) const { return a_; };
    inline const Point& b (void) const { return b_; };
    inline const Point& c (void) const { return c_; };
    inline bool operator== (const Triangle& tri) {
      return a_ == tri.a_ && b_ == tri.b_ && c_ == tri.c_;
    };
    inline bool operator!= (const Triangle& tri) {
      return !this->operator== (tri);
    };
    Triangle& operator= (const Triangle&);
    const Point center (void) const;
    double_t area (void) const;
    double_t perimeter (void) const;
  };

};

#endif /* _TRIANGLE_HPP_ */

