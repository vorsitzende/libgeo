
#ifndef _LIBGEO_H_
#define _LIBGEO_H_

#ifndef __cplusplus
#error LibGeo Requires C++
#endif /* __cplusplus */

#include "point.hpp"
#include "shape.hpp"
#include "fraction.hpp"
#include "segment.hpp"
#include "line.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "vector.hpp"
#include "field.hpp"
#include "matrix.hpp"

namespace geo {

  typedef std::function<const Vector(double_t, double_t)> FieldEquation;

  inline double_t dist (const Point& a, const Point& b) {
    return Segment (a, b).length ();
  };

  inline double_t dist (const Shape& a, const Shape& b) {
    return Segment (a.center (), b.center ()).length ();
  };
  
  inline Triangle right_triangle (const Point& a, const Point& b) {
    return Triangle (a, b, Point (b.x (), a.y ()));
  };
  
  inline Triangle right_triangle (const Segment& s) {
    return right_triangle (s.a (), s.b ());
  };

};

#endif /* _LIBGEO_H_ */

