/*Copyright Written by Juan De Filippis */
/* Copyright 2018
 * Written by Juan De Filippis
 */
#include "point2d.h" // NOLINT
#include "vector2d.h" //NOLINT
const Point2d Point2d::operator +(const Vector2d& rhs) const {
  /* Returns the result of the operation where the calling object
   *  is the left-hand side of the operation
   */
    double xS = x_ + rhs.x();
    double yS = y_ + rhs.y();
    Point2d point(xS, yS);
    return point;
}
const Vector2d Point2d::operator -(const Point2d& rhs) const {
  /* returns the result of the operation where the calling object
   * is the left-hand side of the operation
   */
    double xS = x_ - rhs.x_;
    double yS = y_ - rhs.y_;
    Vector2d point (xS, yS);
    return point;
}
bool Point2d::operator ==(const Point2d& rhs) const {
    // True if approximately equal, false if not
    bool iseque;
    iseque = true;
    if(rhs.x_ != rhs.y_){
        return false;
    }
    return iseque;
}
bool Point2d::operator !=(const Point2d& rhs) const {
    // True if approximately equal, false if not
   bool iseque;
    iseque = true;
    if(rhs.x_ == rhs.y_){
        return false;
    }
    return iseque;
}
ostream& Point2d::Extract(ostream& lhs) const {
lhs << "(" << x_ << ", " << y_ << ")";
    return lhs;
}
ostream& operator <<(ostream& lhs, const Point2d& rhs) {
  return rhs.Extract(lhs);
}
istream& Point2d::Insert(istream& lhs) {
   double value1;
   lhs >> value1;
   double value2;
   lhs >> value2;
   x_ = value1;
   y_ = value2;
   return lhs;
}
istream& operator >>(istream& lhs, Point2d& rhs) {
 return rhs.Insert(lhs);
}
double Point2d::DistanceTo(const Point2d& rhs) const {
    double add_x = (x_ + rhs.x());  // object oriented addition
    double add_y = (y_ + rhs.y());
    double distance = sqrt(pow(add_x, 2) + pow(add_y, 2));
    return distance;
}
bool CompareLeftToRight::operator()(Point2d lhs, Point2d rhs) {
    if (lhs.x() < rhs.x())
        return true;
    else if (lhs.x() == rhs.x())
        return lhs.y() < rhs.y();
    else
        return false;
}
CompareDistanceFrom::CompareDistanceFrom(Point2d from) {
    from_ = from;
}
bool CompareDistanceFrom::operator()(Point2d lhs, Point2d rhs) {
    if (lhs.DistanceTo(from_) < rhs.DistanceTo(from_))
        return true;
    else
        return false;
}
