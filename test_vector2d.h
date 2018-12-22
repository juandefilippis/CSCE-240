/* Copyright 2018 */
#ifndef _240_HW5_TEST_VECTOR2D_H_  //NOLINT
#define _240_HW5_TEST_VECTOR2D_H_  //NOLINT

#include <algorithm>
using std::sort;
#include <iostream>
using std::endl;
using std::cout;
#include <sstream>
using std::stringstream;
#include <vector>

#include "vector2d.h"  //NOLINT

bool TestVectorAdd();
bool TestVectorSubtract();
bool TestVectorReverse();
bool TestVectorScale();
bool TestVectorEqualTo();
bool TestVectorNotEqualTo();

bool TestVectorExtractOperator();
bool TestVectorInsertOperator();
bool TestCompareMagnitude();
bool TestCompareDirection();
#endif  //NOLINT
