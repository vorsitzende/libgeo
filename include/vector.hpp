
#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include "segment.hpp"

namespace geo {

  class Vector {
    double_t a_, b_;
  public:
    inline Vector (void) noexcept = default;
    inline ~Vector (void) noexcept = default;
    inline Vector (const Vector& v) noexcept : a_ (v.a_), b_ (v.b_) {};
    inline Vector (double_t a, double_t b) noexcept : a_ (a), b_ (b) {};
    inline Vector (const Segment& s) noexcept : a_ (s.b ().x () - s.a ().x ()),
      b_ (s.b ().y () - s.a ().y ()) {};
    inline bool operator== (const Vector& v) const {
      return a_ == v.a_ && b_ == v.b_;
    };
    inline bool operator!= (const Vector& v) const {
      return !this->operator== (v);
    };
    inline double_t x (void) const { return a_; };
    inline double_t y (void) const { return b_; };
    friend Vector operator+ (const Vector& lhs, const Vector& rhs) {
      return Vector (lhs.a_ + rhs.a_, lhs.b_ + rhs.b_);
    };
    friend Vector operator- (Vector lhs, const Vector& rhs) {
      return Vector (lhs.a_ - rhs.a_, lhs.b_ - rhs.b_);
    };
    friend Vector operator* (const Vector& lhs, double_t scaler) {
      return Vector (lhs.a_ * scaler, lhs.b_ * scaler);
    };
    friend Vector operator/ (const Vector& lhs, double_t scaler) {
      if (!scaler)
        throw "Division by zero.";
      return Vector (lhs.a_ / scaler, lhs.b_ / scaler);
    };
    friend std::ostream& operator<< (std::ostream&, const Vector&);
    double_t length (void) const;
    Vector& operator= (const Vector&);
    Vector& operator+= (const Vector&);
    Vector& operator-= (const Vector&);
  };

};

#endif /* _VECTOR_HPP_ */

