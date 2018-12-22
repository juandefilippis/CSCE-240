// Copyright Written by Juan De Filippis
#ifndef _240_HW5_POINT2D_H_  // NOLINT
#define _240_HW5_POINT2D_H_  // NOLINT
#include <iostream>
#include <string>
using std::istream;
using std::ostream;
using std::string;

#include "vector2d.h"
class Point2d {
 public:
  Point2d() : x_(0.0), y_(0.0) {}
  Point2d(double x, double y) : x_(x), y_(y) {}
  const Point2d operator +(const Vector2d&) const;
  const Vector2d operator -(const Point2d&) const;
  const Point2d operator -() const;
  bool operator ==(const Point2d&) const;
  bool operator !=(const Point2d&) const;
  inline double x() const { return x_; }
  inline double y() const { return y_; }
  ostream& Extract(ostream& lhs) const;
  istream& Insert(istream& lhs);
  double DistanceTo(const Point2d& rhs) const;
 private:
  double x_;
  double y_;
};
 ostream& operator << (ostream& lhs, const Point2d& rhs);
 istream& operator >> (istream& lhs, Point2d& rhs);
class CompareLeftToRight {
 public:
  bool operator()(Point2d lhs, Point2d rhs);
};
class CompareDistanceFrom {
  public:
  CompareDistanceFrom(Point2d from);  // NOLINT
  bool operator()(Point2d lhs, Point2d rhs);
 private:
  Point2d from_;
};

#endif  //NOLINT
