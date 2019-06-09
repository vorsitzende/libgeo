
#ifndef _FRACTION_HPP_
#define _FRACTION_HPP_

#include <ostream>
#include <cmath>

namespace geo {

  class Fraction {
    double_t num_, den_;
    static int64_t gcd (int64_t, int64_t);
  public:
    inline Fraction (void) noexcept : num_ (0) , den_ (1) {};
    inline Fraction (const Fraction& f) noexcept
      : num_ (f.num_), den_ (f.den_) {};
    Fraction (double_t, double_t);
    Fraction (double_t num) noexcept;
    inline ~Fraction (void) noexcept = default;
    Fraction& operator= (const Fraction&);
    inline double_t numerator (void) const { return num_; };
    inline double_t denominator (void) const { return den_; };
    Fraction& reduce (void);
    inline operator double_t (void) const { return num_ / den_; };
    inline bool operator== (const Fraction& f) const {
      return (num_ / den_) == (f.num_ / f.den_);
    };
    inline bool operator!= (const Fraction& f) const {
      return !this->operator== (f);
    };
    friend std::ostream& operator<< (std::ostream&, const Fraction&);
  };

};

#endif /* _FRACTION_HPP_ */
