/* Copyright 2018 */
#include "test_vector2d.h"  //NOLINT


int main(int argc, char** argv) {
  if (!TestVectorAdd())
    return 1;

  if (!TestVectorSubtract())
    return 1;

  if (!TestVectorReverse())
    return 1;

 if (!TestVectorScale())
    return 1;

  if (!TestVectorEqualTo())
    return 1;

  if (!TestVectorNotEqualTo())
    return 1;

  if (!TestVectorExtractOperator())
    return 1;

  if (!TestVectorInsertOperator())
    return 1;

  if (!TestCompareMagnitude())
    return 1;

  if (!TestCompareDirection())
    return 1;
  return 0;
}

bool TestVectorAdd() {
  Vector2d v1(1.7, -3.0), v2(2.1, 1.5);
  Vector2d t1 = v1 + v2;
  bool pass = t1.x() == 3.8 && t1.y() == -1.5;

  cout << "TestVectorAddOperator: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: 3.8, -1.5 Actual: "
      << t1.x() << ", " << t1.y() << endl;

  return pass;
}

bool TestVectorSubtract() {
  Vector2d v1(1.0, -3.0), v2(0.5, 1.5);
  Vector2d t1 = v1 - v2;
  bool pass = t1.x() == 0.5 && t1.y() == -4.5;

  cout << "TestVectorSubtractOperator: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: 0.5, -4.5 Actual: "
      << t1.x() << ", " << t1.y() << endl;

  return pass;
}

bool TestVectorReverse() {
  Vector2d v(-1.0, 2.0);

  Vector2d nv1 = -v;
  bool pass = nv1.x() == 1.0 && nv1.y() == -2.0;

  cout << "TestVectorReverseOperator: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: 1, -2 Actual: "
      << nv1.x() << ", " << nv1.y() << endl;
  return pass;
}

bool TestVectorScale() {
  Vector2d v1(2.0, 4.0);
  Vector2d v2 = 2.0*v1;
  bool pass = v2.x() == 4.0 && v2.y() == 8.0;

  cout << "TestVectorScaleOperator: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected 4, 8 Actual: "
      << v2.x() << ", " << v2.y() << endl;

  return pass;
}

bool TestVectorEqualTo() {
  Vector2d v1(1.0, 1.0), v2(1.0, 1.0);
  bool pass = v1 == v2;

  cout << "TestVectorEqualToOperator: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected (1.0, 1.0) == (1.0, 1.0): true Actual: "
      << (pass ? "true" : "false") << endl;

  if (!pass)
    return false;

  v2 = Vector2d(2.0, 1.0);
  pass = v1 == v2;

  cout << "TestVectorEqualToOperator: "
      << (!pass ? "PASSED" : "FAILED") << endl
      << "  Expected (1.0, 1.0) == (2.0, 1.0): false Actual: "
      << (!pass ? "false" : "true") << endl;

  return !pass;
}

bool TestVectorNotEqualTo() {
  Vector2d v1(1.0, 1.0), v2(2.0, 1.0);
  bool pass = v1 != v2;

  cout << "TestVectorNotEqualToOperator: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected (1.0, 1.0) != (2.0, 1.0): true Actual: "
      << (v1 != v2 ? "true" : "false") << endl;

  if (!pass)
    return false;

  v2 = Vector2d(1.0, 1.0);
  pass = v1 != v2;

  cout << "TestVectorNotEqualToOperator: "
      << (!pass ? "PASSED" : "FAILED") << endl
      << "  Expected (1.0, 1.0) != (1.0, 1.0): false Actual: "
      << (!pass ? "false" : "true") << endl;

  return !pass;
}

bool TestVectorExtractOperator() {
  stringstream ostr;
  Vector2d v(1.0, 2.0);
  ostr << v;
  bool pass = ostr.str() == "(1, 2)";

  cout << "TestVectorExtractOperator: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: (1, 2) Actual: " << ostr.str() << endl;

  return pass;
}

bool TestVectorInsertOperator() {
  stringstream ostr("1.0 2.0");
  Vector2d v;
  ostr >> v;
  double x = 1.0, y = 2.0;
  bool pass = v.x() == x && v.y() == y;

  cout << "TestVectorInsertOperator: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: (" << x << ", " << y << ") Actual: ("
      << v.x() << ", " << v.y() << ")" << endl;

  return pass;
}

ostream& operator<<(ostream& lhs, const std::vector<Vector2d>& rhs) {
  for (size_t i = 0; i < rhs.size(); ++i) {
    lhs << rhs.at(i);
    if (i < rhs.size() - 1)
      lhs << ", ";
  }

  return lhs;
}

bool operator==(const std::vector<Vector2d>& lhs,
    const std::vector<Vector2d>& rhs) {
  if (lhs.size() != rhs.size())
    return false;

  for (size_t i = 0; i < lhs.size(); ++i) {
    if (lhs.at(i).x() != rhs.at(i).x() || lhs.at(i).y() != rhs.at(i).y())
      return false;
  }
  return true;
}

bool TestCompareMagnitude() {
  std::vector<Vector2d> expected = {
      Vector2d(1.0, 2.0), Vector2d(5.0, 2.0), Vector2d(3.0, 8.0),
      Vector2d(12.0, 5.0)
  };
  std::vector<Vector2d> actual = {
      Vector2d(3.0, 8.0), Vector2d(12.0, 5.0), Vector2d(5.0, 2.0),
      Vector2d(1.0, 2.0)
  };
  CompareMagnitude comparator;
  sort(actual.begin(), actual.end(), comparator);
  bool pass = actual == expected;

  cout << "TestCompareMagnitude: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: " << expected << endl
      << "  Actual: " << actual << endl;

  return pass;
}

bool TestCompareDirection() {
  std::vector<Vector2d> expected = {
      Vector2d(10.0, 0.0), Vector2d(0.0, 10.0), Vector2d(-10.0, -0.0),
      Vector2d(0.0, -10.0)
  };
  std::vector<Vector2d> actual = {
      Vector2d(-10.0, 0.0), Vector2d(0.0, 10.0), Vector2d(0.0, -10.0),
      Vector2d(10.0, 0.0)
  };
  CompareDirection comparator;
  sort(actual.begin(), actual.end(), comparator);
  bool pass = actual == expected;

  cout << "TestCompareDirection: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: " << expected << endl
      << "  Actual: " << actual << endl;

  return pass;
}
