/* Copyright 2018 */
#ifndef _240_HW5_TEST_POINT2D_H_  //NOLINT
#define _240_HW5_TEST_POINT2D_H_  //NOLINT

#include <algorithm>
using std::sort;
#include <iostream>
using std::endl;
using std::cin;
using std::cout;
#include <sstream>
using std::stringstream;
#include <vector>

#include "point2d.h"  //NOLINT
#include "vector2d.h"  //NOLINT

bool TestPointSubtractOperator();
bool TestPointAddOperator();
bool TestPointEqualToOperator();
bool TestPointNotEqualToOperator();
bool TestPointExtractOperator();
bool TestPointInsertOperator();
bool TestCompareLeftToRight();
bool TestCompareDistanceFrom();
#endif  //NOLINT
