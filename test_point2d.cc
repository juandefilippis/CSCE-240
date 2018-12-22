/* Copyright 2018 */
#include "test_point2d.h"  //NOLINT


int main(int argc, char** argv) {
  if (!TestPointSubtractOperator())
    return 1;

  if (!TestPointAddOperator())
    return 1;

  if (!TestPointEqualToOperator())
    return 1;

  if (!TestPointNotEqualToOperator())
    return 1;

  if (!TestPointExtractOperator())
    return 1;

  if (!TestPointInsertOperator())
    return 1;

  if (!TestCompareLeftToRight())
    return 1;

  if (!TestCompareDistanceFrom())
    return 1;

  return 0;
}

bool TestPointSubtractOperator() {
  Point2d p1(1.0, -3.0), p2(0.5, 1.5);
  Vector2d v1;
  v1 = p1 - p2;
  bool pass = v1.x() == 0.5 && v1.y() == -4.5;

  cout << "TestPointSubtractOperator: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: 0.5, -4.5 Actual: "
      << v1.x() << ", " << v1.y() << endl;

  return pass;
}

bool TestPointAddOperator() {
  Point2d p1(0.0, 0.0), p2;
  Vector2d v1(4.0, 6.0);
  p2 = p1 + v1;
  bool pass = p2.x() == 4.0 && p2.y() == 6.0;

  cout << "TestPointAddOperator: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: 4, 6 Actual: "
      << p2.x() << ", " << p2.y() << endl;

  return pass;
}

bool TestPointEqualToOperator() {
  double x=1.0, y=1.0;
  Point2d p1(1.0, 1.0), p2(x, y);
  bool pass = p1 == p2;

  cout << "TestPointEqualToOperator: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected (1.0, 1.0) == (" << x << ", " << y << "): true Actual: "
      << (pass ? "true" : "false") << endl;

  if (!pass)
    return pass;

  x = 2.0;
  p2 = Point2d(x, y);
  pass = p1 == p2;
  cout << "TestPointEqualToOperator: "
      << (!pass ? "PASSED" : "FAILED") << endl
      << "  Expected (1.0, 1.0) == (" << x << ", " << y << "): false Actual: "
      << (!pass ? "false" : "true") << endl;


  return !pass;
}

bool TestPointNotEqualToOperator() {
  double x=2.0, y=1.0;
  Point2d p1(1.0, 1.0), p2(x, y);
  bool pass = p1 != p2;

  cout << "TestPointNotEqualToOperator: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected (1.0, 1.0) != (" << x << ", " << y << "): true Actual: "
      << (pass ? "true" : "false") << endl;

  if (!pass)
    return pass;

  x = 1.0;
  p2 = Point2d(x, y);
  pass = p1 != p2;
  cout << "TestPointEqualToOperator: "
      << (!pass ? "PASSED" : "FAILED") << endl
      << "  Expected (1.0, 1.0) != (" << x << ", " << y << "): false Actual: "
      << (!pass ? "false" : "true") << endl;


  return !pass;
}

bool TestPointExtractOperator() {
  Point2d p(34.8, 23.9);
  stringstream sout;
  sout << p;
  bool pass = sout.str() == "(34.8, 23.9)";

  cout << "TestPointExtractOperator: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: (34.8, 23.9) Actual: " << sout.str() << endl;

  return true;
}

bool TestPointInsertOperator() {
  Point2d p;
  stringstream sin("3.0 4.0");
  sin >> p;
  bool pass = 3.0 == p.x() && 4.0 == p.y();

  cout << "TestPointInsertOperator: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: (3, 4) Actual: ("
      << p.x() << ", " << p.y() << ")" << endl;

  return pass;
}

ostream& operator<<(ostream& lhs, const std::vector<Point2d>& rhs) {
  for (size_t i = 0; i < rhs.size(); ++i) {
    lhs << rhs.at(i);
    if (i < rhs.size() - 1)
      lhs << ", ";
  }

  return lhs;
}

bool operator==(const std::vector<Point2d>& lhs,
    const std::vector<Point2d>& rhs) {
  if (lhs.size() != rhs.size())
    return false;

  for (size_t i = 0; i < lhs.size(); ++i) {
    if (lhs.at(i).x() != rhs.at(i).x() || lhs.at(i).y() != rhs.at(i).y())
      return false;
  }
  return true;
}

bool TestCompareLeftToRight() {
  std::vector<Point2d> expected = {
      Point2d(0.0, 0.0), Point2d(0.0, 1.0), Point2d(1.0, 1.0),
      Point2d(1.0, 2.0)
  };
  std::vector<Point2d> actual = {
      Point2d(1.0, 2.0), Point2d(0.0, 0.0), Point2d(0.0, 1.0),
      Point2d(1.0, 1.0)
  };
  CompareLeftToRight comparator;
  sort(actual.begin(), actual.end(), comparator);
  bool pass = actual == expected;

  cout << "TestCompareMagnitude: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: " << expected << endl
      << "  Actual: " << actual << endl;

  return pass;
}

bool TestCompareDistanceFrom() {
  std::vector<Point2d> expected = {
      Point2d(1.0, 1.0), Point2d(1.0, 2.0), Point2d(2.0, 2.0),
      Point2d(2.0, 3.0)
  };
  std::vector<Point2d> actual = {
      Point2d(2.0, 3.0), Point2d(1.0, 1.0), Point2d(1.0, 2.0),
      Point2d(2.0, 2.0)
  };
  Point2d origin(1.0, 1.0);
  CompareDistanceFrom comparator(origin);
  sort(actual.begin(), actual.end(), comparator);
  bool pass = actual == expected;

  cout << "TestCompareDistanceFrom: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: " << expected << endl
      << "  Actual: " << actual << endl;

  return pass;
}
