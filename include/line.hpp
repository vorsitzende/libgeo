
#ifndef _LINE_HPP_
#define _LINE_HPP_

#include "point.hpp"
#include <functional>

namespace geo {

  class Line {
    std::function<double_t(double_t)> func_;
  public:
    inline Line (void) noexcept = default;
    inline ~Line (void) noexcept = default;
    inline Line (const Line& l) noexcept : func_ (l.func_) {};
    inline Line (const std::function<double_t(double_t)>& f) noexcept
      : func_ (f) {};
    double_t operator() (double_t) const;
  };

};

#endif /* _LINE_HPP_ */

