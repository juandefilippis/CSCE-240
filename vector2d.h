#ifndef _240_HW5_VECTOR2D_H_  //NOLINT
#define _240_HW5_VECTOR2D_H_  //NOLINT
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <istream>
typedef std::stringstream strm;
using std::iostream;
using std::ostream;
using std::istream;
using std::string;
using std::endl;

class Vector2d {
public:
    Vector2d() : x_(0.0), y_(0.0) {}
    Vector2d(double x, double y) : x_(x), y_(y) {}

    const Vector2d operator +(const Vector2d&) const;
    const Vector2d operator -(const Vector2d&) const;
    const Vector2d operator -() const;
    bool operator ==(const Vector2d&) const;
    bool operator !=(const Vector2d&) const;
    const Vector2d operator *(double lhs) const;
    inline double x() const { return x_; }
    inline double y() const { return y_; }
    ostream& Extract(ostream& lhs) const;
    istream& Insert(istream& lhs);
    double GetLength() const;
     const Vector2d GetUnit() const;
private:
    double x_;
    double y_;
};
ostream& operator << (ostream& lhs, const Vector2d& rhs);
istream& operator >> (istream& lhs, Vector2d& rhs);
Vector2d operator *(double lhs,const Vector2d& rhs);
class CompareMagnitude {
 public:
  bool operator()(Vector2d& lhs, Vector2d& rhs);  // NOLINT
};
class CompareDirection {
 public:
  bool operator()(Vector2d& lhs, Vector2d& rhs);  // NOLINT
};
#endif // NOLINT
