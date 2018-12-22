// Copyright Jeremy Lewis edited by Juan De Filippis
#include <iostream>
using std::cout;
using std::endl;

#include "comp_geo.h"//NOLINT

bool TestGetCircumference() {
  const double expected = 6.28318;
  double actual = GetCircumference(0.0, 0.0, 1.0, 0.0);
  if (actual != expected) {
    cout << "Expected: " << expected << ", Actual: " << actual << endl;
    return false;
    }
  return true;
}

bool TestGetPerimeter() {
  const double expected = 4.0;
  double actual = GetPerimeter(2.0, 2.0, 2.0, 4.0);
  if (actual != expected) {
    cout << "Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }
  return true;
}

bool TestGetDistanceSquared() {
  const double expected = 4.0;
  double actual = GetDistanceSquared(2.0, 0.0, 4.0, 0.0);
  if (actual != expected) {
    cout << "Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }
  return true;
}

bool TestGetDistance() {
  const double expected = 2.0;
  double actual = GetDistance(2.0, 0.0, 4.0, 0.0);
  if (actual != expected) {
    cout << "Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}
bool TestGetVolume() {
    const double expected = 25.12;
    double actual = GetVolume(2.0, 2.0, 4.0, 4.0);
    if (actual != expected) {
        cout << "Expected: " << expected << ", Actual:" << actual << endl;
        return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
  cout << "TestGetCircumference" << endl;
  if (!TestGetCircumference())
    return 1;
  cout << "TestGetPerimeter" << endl;
  if (!TestGetPerimeter())
    return 1;
  cout << "TestGetDistanceSquared" << endl;
  if (!TestGetDistanceSquared())
    return 1;
  cout << "TestGetDistance" << endl;
  if (!TestGetDistance())
    return 1;

  return 0;
}
