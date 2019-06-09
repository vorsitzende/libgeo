
#ifndef _FIELD_HPP_
#define _FIELD_HPP_

#include "vector.hpp"
#include <functional>

namespace geo {

  class Field {
    std::function<const Vector(double_t, double_t)> field_equation_;
  public:
    inline Field (void) noexcept = default;
    inline ~Field (void) noexcept = default;
    inline Field (const Field& f) noexcept
      : field_equation_ (f.field_equation_) {};
    inline Field (const std::function<const Vector(double_t, double_t)>& f)
      noexcept : field_equation_ (f) {};
    inline const Vector operator() (double_t x, double_t y) {
      return field_equation_ ? field_equation_ (x, y) : Vector (0, 0);
    };
    inline const Vector operator() (const Point& p) {
      return this->operator() (p.x (), p.y ());
    };
    inline Field& operator= (const Field& f) {
      field_equation_ = f.field_equation_;
      return *this;
    };
  };

};

#endif /* _FIELD_HPP_ */

