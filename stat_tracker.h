/* Copyright 2018 Written by Juan De Filippis*/
#ifndef _DESKTOP_HW7_STAT_TRACKER_H_  // NOLINT
#define _DESKTOP_HW7_STAT_TRACKER_H_  // NOLINT
#include <ostream>
#include <vector>
#include <cstddef>
// using size_t
// using toupper
#include <iostream>
#include <utility>
#include <map>
#include <algorithm>
#include <cctype>
#include <cctype>
using std::for_each;
using std::vector;
using std::ostream;
using std::iostream;
using std::transform;
using std::make_pair;
using std::map;
using std::sort;
using std::cout;
using std::endl;

namespace csce240 {
template <class T>
class StatTracker : public vector<T> {
 public:
  inline StatTracker() {}
  StatTracker(const vector<T>&);
  inline ~StatTracker() {}
  void Add(T val);
  size_t Count();
  ostream& Extract(ostream&) const;
  const T Mean() const;  // T = T + T and T = T / int must be defined
  const T Median() const;  // T = T / int must be defined
  const vector<T> Mode() const;  // T == T and T < T must be defined
};
}  // namespace csce240
#include "stat_tracker.cc"
#endif  // NOLINT
