
#ifndef _CIRCLE_HPP_
#define _CIRCLE_HPP_

#include "shape.hpp"

namespace geo {

  class Circle : Shape {
    Point origin_;
    double_t radius_;
    const double_t PI = 3.14159;
  public:
    inline Circle (void) noexcept = default;
    inline ~Circle (void) noexcept = default;
    inline Circle (const Circle& c) noexcept
      : origin_ (c.origin_), radius_ (c.radius_) {};
    inline explicit Circle (const Point& p, double_t r) noexcept
      : origin_ (p), radius_ (r) {};
    inline bool operator== (const Circle& c) {
      return origin_ == c.origin_ && radius_ == c.radius_;
    };
    inline bool operator!= (const Circle& c) {
      return !this->operator== (c);
    };
    inline double_t radius (void) const { return radius_; };
    Circle& operator= (const Circle&);
    const Point center (void) const;
    double_t area (void) const;
    double_t perimeter (void) const;
  };

};

#endif /* _CIRCLE_HPP_ */

