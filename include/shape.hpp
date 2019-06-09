
#ifndef _SHAPE_HPP_
#define _SHAPE_HPP_

#include "point.hpp"

namespace geo {

  class Shape {
  public:
    virtual const Point center (void) const = 0;
    virtual double_t area (void) const = 0;
    virtual double_t perimeter (void) const = 0;
  };

};

#endif /* _SHAPE_HPP_ */
