
#include <circle.hpp>

namespace geo {

  Circle& Circle::operator= (const Circle& c) {
    origin_ = c.origin_;
    radius_ = c.radius_;
    return *this;
  };

  const Point Circle::center (void) const {
    return origin_;
  };

  double_t Circle::area (void) const {
    return PI * (radius_ * radius_);
  };

  double_t Circle::perimeter (void) const {
    return radius_ * (2 * PI);
  };

};

