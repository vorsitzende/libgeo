
#include <line.hpp>

namespace geo {

  double_t Line::operator() (double_t x) const {
    double_t retval;
    func_ ? retval = func_ (x) : retval = 0;
    return retval;
  };

};

