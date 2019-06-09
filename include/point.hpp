
#ifndef _POINT_HPP_
#define _POINT_HPP_

#include <cmath>
#include <ostream>

namespace geo {

  class Point {
    double_t x_, y_;
  public:
    inline Point (void) noexcept = default;
    inline ~Point (void) noexcept = default;
    Point (const Point&) noexcept;
    Point (double_t, double_t) noexcept;
    Point& operator= (const Point&);
    inline double_t x (void) const { return x_; };
    inline double_t y (void) const { return y_; };
    inline bool operator== (const Point& p) const {
      return x_ == p.x_ && y_ == p.y_;
    };
    inline bool operator!= (const Point& p) const {
      return !this->operator== (p);
    };
    friend std::ostream& operator<< (std::ostream&, const Point&);
  };

};

#endif /* _POINT_HPP_ */

