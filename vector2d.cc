/*Copyright Written by Juan De Filippis */
/* Copyright 2018
 * Written by Juan De Filippis
 */
#include "vector2d.h"  //  NOLINT
const Vector2d Vector2d::operator +(const Vector2d& rhs) const {
    /* Returns the result of the operation where the calling object
     *  is the left-hand side of the operation
     */
    Vector2d sum;
    sum.x_ = (x_ + rhs.x_);
    sum.y_ = (y_ + rhs.y_);
    return sum;
}
const Vector2d Vector2d::operator -(const Vector2d& rhs) const {
    /* returns the result of the operation where the calling object
     * is the left-hand side of the operation
     */
    Vector2d subs;
    subs.x_ = (x_ - rhs.x_);
    subs.y_ = (y_ - rhs.y_);
    return subs;
}
const Vector2d Vector2d::operator -() const {
    // Returns a vector with the opposite direction of calling object
    Vector2d rev;
    rev.x_ = x_ * -1;
    rev.y_ = y_ * -1;
    return rev;
}
  const Vector2d Vector2d::operator *(double scalar) const {
  // Returns the result of scaling the calling object by the given scaler
  Vector2d scal;
  scal.x_ = (x_ * scalar);
  scal.y_ = (y_ * scalar);
  return scal;
}
  Vector2d operator *(double lhs,const Vector2d& rhs) {
    return Vector2d(lhs * rhs.x(), lhs * rhs.y());
}
bool Vector2d::operator ==(const Vector2d& rhs) const {
    // True if approximately equal, false if not
    bool eque;
    eque = true;
    if (rhs.x_ != rhs.y_) {
        return false;
    }
    return eque;
}
bool Vector2d::operator !=(const Vector2d& rhs) const {
    // True if approximately equal, false if not
    bool eque;
    eque = true;
    if (rhs.x_ == rhs.y_) {
        return false;
    }
    return eque;
}
ostream& Vector2d::Extract(ostream& lhs) const {
lhs << "(" << x_ << ", " << y_ << ")";
    return lhs;
}
ostream& operator <<(ostream& lhs, const Vector2d& rhs) {
  return rhs.Extract(lhs);
}
istream& Vector2d::Insert(istream& lhs) {
   double value1;
   lhs >> value1;
   double value2;
   lhs >> value2;
   x_ = value1;
   y_ = value2;
   return lhs;
}
istream& operator >>(istream& lhs, Vector2d& rhs) {
 return rhs.Insert(lhs);
}
double Vector2d::GetLength() const {
    double length = sqrt(pow(x_, 2) + pow(y_, 2));
    return length;
}
const Vector2d Vector2d::GetUnit() const {
    Vector2d unit;
    double hyp = sqrt(pow(x_, 2) + pow(y_, 2));
    unit.x_ = x_ / hyp;
    unit.y_ = y_ / hyp;
    return unit;
}
bool CompareMagnitude::operator()(Vector2d& lhs, Vector2d& rhs) {
    if (lhs.GetLength() < rhs.GetLength())
        return true;
    else
        return false;
}
bool CompareDirection::operator()(Vector2d& lhs, Vector2d& rhs) {
    const double kPi = 3.14159;
    const double kRad = kPi / 180;
    Vector2d l = lhs.GetUnit();
    Vector2d r = rhs.GetUnit();
    double left_direction = (atan2(l.y(), l.x()) * kRad);
    double right_direction = (atan2(r.y(), r.x()) * kRad);
    if (left_direction < 0)
        left_direction += kPi;
    if (right_direction < 0)
        right_direction += kPi;
    if (left_direction < right_direction)
        return true;
    else
        return false;
}
