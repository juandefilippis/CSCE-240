/* Copyright 2018 Written by Juan De Filippis */
namespace csce240 {
template <class T>
StatTracker<T>::StatTracker(const vector<T>& elem) {
    StatTracker<T> stack;
    for (size_t i = 0; i < elem.size(); ++i) {
        stack.Add(elem.at(i));
    }
}
template <class T>
    // Adds a new element to the tracked elements
void StatTracker<T>::Add(T val) {
    vector<T>::push_back(val);
}
template <class T>
    // Number of tracked elements
size_t StatTracker<T>::Count() {
    return vector<T>::size;
}
template <class T>
    /* Copies the tracked elements to an std::ostream object delimited,
     * but not preceded or followed, by a single space.
     */
ostream& StatTracker<T>::Extract(ostream& out) const {
    for (size_t i = 0; i < vector<T>::size(); ++i) {
        out << vector<T>::at(i);
        if (i < vector<T>::size() - 1)
            out << ", ";
    }
    return out;
}
template <class T>
    // Calculates the average of the elements stored
const T StatTracker<T>::Mean() const {
    T sum = 0;
    for(size_t i = 0; i < vector<T>::size(); ++i)
        sum = sum + vector<T>::at(i);
    T avg = sum / vector<T>::size();
    return avg;
}
template <class T>
    // Calculates the median element
const T StatTracker<T>::Median() const {
    vector<T> temp;
    for (size_t i = 0; i < vector<T>::size(); ++i)
        temp.push_back(vector<T>::at(i));
    if (vector<T>::size() % 2 == 0) {
        sort(temp.begin(), temp.end());
        T memberA = temp.at(temp.size() / 2);
        T memberB = temp.at(temp.size() + 1);
        T median = (memberA + memberB) / 2;
        return median;
    } else {
        sort(temp.begin(), temp.end());
        return temp.at(temp.size() / 2);
    }
}
 template <class T>
    // Calculates the most commonly appearing element
 const vector<T> StatTracker<T>::Mode() const {
 vector<T> elem;
 vector<T> mod;
 int modeC = 0;
 int maxC = 1;
 int loop = 0;
 for (size_t i = 0; i < vector<T>::size(); ++i)
     elem.push_back(vector<T>::at(i));
     sort(elem.begin(), elem.end());
 for (size_t i = 0; i < elem.size(); ++i) {
     if (elem.at(i) == loop) {
         ++modeC;
 }
else {
    if (modeC > maxC) {
 mod.erase(mod.begin(), mod.end());
 mod.insert(mod.end(), loop);
 maxC = modeC;
 }
    else if (modeC == maxC) {
 mod.insert(mod.end(), loop);
 }
    else {
        modeC = maxC;
}
 modeC = 1;
 loop = elem.at(i);
  }
}
 return mod;
 }
}  // namespace csce240
