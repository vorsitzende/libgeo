
#ifndef _RECTANGLE_HPP_
#define _RECTANGLE_HPP_

#include "shape.hpp"

namespace geo {

  class Rectangle : Shape {
    Point origin_;
    double_t width_, height_;
  public:
    enum CORNER : uint8_t { TOP_LEFT, TOP_RIGHT, BOTTOM_LEFT, BOTTOM_RIGHT };
    inline Rectangle (void) noexcept = default;
    inline ~Rectangle (void) noexcept = default;
    inline Rectangle (const Rectangle& r) : origin_ (r.origin_),
      width_ (r.width_), height_ (r.height_) {};
    inline explicit Rectangle (const Point& p, double_t w, double_t h)
      : origin_ (p), width_ (w), height_ (h) {};
    inline double_t width (void) const { return width_; };
    inline double_t height (void) const { return height_; };
    inline bool isSquare (void) const { return width_ == height_; };
    Rectangle& operator= (const Rectangle&);
    const Point getCorner (CORNER) const;
    const Point center (void) const;
    double_t area (void) const;
    double_t perimeter (void) const;
  };

};

#endif /* _RECTANGLE_HPP_ */

