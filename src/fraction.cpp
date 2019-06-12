
#include <fraction.hpp>

namespace geo {

  int64_t Fraction::gcd (int64_t a, int64_t b) {
    if (!a)
      return b;
    else if (!b)
      return a;

    if (a < b)
      return gcd (a, b % a);
    else
      return gcd (b, a % b);
  };

  Fraction::Fraction (double_t num, double_t den) : num_ (num), den_ (den) {
    if (!den_)
      throw "Division by zero.";
  };

  Fraction::Fraction (double_t num) noexcept {
    if (!num) {
      num_ = 0;
      den_ = 1;
    } else {
      static const int64_t PRECISION = 1000000000;
      double_t integral = std::floor (num);
      double_t frac = num - integral;
      int64_t gcd_ = gcd (round (frac * PRECISION), PRECISION);

      den_ = PRECISION / gcd_;
      num_ = round (frac * PRECISION) / gcd_;
      if (!num_)
        num_ = num;
    };
  };

  Fraction& Fraction::operator= (const Fraction& f) {
    num_ = f.num_;
    den_ = f.den_;
    return *this;
  };

  void Fraction::reduce (Fraction& f) {
    int gcd__=gcd(f->num_,f->den_)
      f->num = (f->num)/gcd__
      f->den_ = (f->den_)/gcd___
  };

  std::ostream& operator<< (std::ostream& os, const Fraction& f) {
    os << f.num_ << "/" << f.den_;
    return os;
  };

};

bool Fraction::operator== (const Fraction &f){
  Fraction::reduce(this)
  Fraction::reduce(f)
  if(this->num_==f->num_ && this->den_==f->den_){
    return true;
  }
  return false;
};
