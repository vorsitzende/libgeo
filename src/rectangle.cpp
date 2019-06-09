
#include <rectangle.hpp>

namespace geo {

  Rectangle& Rectangle::operator= (const Rectangle& rect) {
    origin_ = rect.origin_;
    width_ = rect.width_;
    height_ = rect.height_;
    return *this;
  };

  const Point Rectangle::getCorner (CORNER corner) const {
    Point retval;
    switch (corner) {
      default:
      case TOP_LEFT:
        retval = origin_;
        break;
      case TOP_RIGHT:
        retval = Point (origin_.x () + width_, origin_.y ());
        break;
      case BOTTOM_LEFT:
        retval = Point (origin_.x (), origin_.y () - height_);
        break;
      case BOTTOM_RIGHT:
        retval = Point (origin_.x () + width_, origin_.y () - height_);
    };
    return retval;
  };

  const Point Rectangle::center (void) const {
    return Point (
      origin_.x () + (width_ / 2),
      origin_.y () - (height_ / 2)
    );
  };

  double_t Rectangle::area (void) const {
    return width_ * height_;
  };

  double_t Rectangle::perimeter (void) const {
    return width_ + height_;
  };

};

