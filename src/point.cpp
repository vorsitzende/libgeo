
#include <point.hpp>

namespace geo {

  Point::Point (const Point& p) noexcept : x_ (p.x_), y_ (p.y_) {};
  Point::Point (double_t x, double_t y) noexcept : x_ (x), y_ (y) {};
  Point& Point::operator= (const Point& p) {
    x_ = p.x_;
    y_ = p.y_;
    return *this;
  };

  std::ostream& operator<< (std::ostream& os, const Point& f) {
    os << "(" << f.x_ << "," << f.y_ << ")";
    return os;
  };

};

