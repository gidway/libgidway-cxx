#ifndef __GIDWAY_MATH_HH__
#define __GIDWAY_MATH_HH__
#include <cmath>
#include <vector>
namespace gidway {
namespace math {

template <typename T> T sma (std::vector<T> & v, int _range) {
    T r = static_cast<T>(0.0), m = static_cast<T>(0.0);
    if (_range > v.size()) _range = v.size();
    for (auto it = v.begin() + _range -1; !!_range; --it, --_range) {
        r += (*it);
    }
    return r / _range;
}

template <typename T> T ema (std::vector<T> & v, int _range) {
    T r = static_cast<T>(0.0), m = static_cast<T>(0.0);
    if (_range > v.size()) _range = v.size();
    T a = static_cast<T>(2.0) / (_range + static_cast<T>(1.0));
    T _la = static_cast<T>(1.0) - _a;
    T _npow = static_cast<T>(0.0);
    for (auto it = v.begin() + _range -1; !!_range; --it, --_range, ++_npow) {
        r += std::pow(_la, _npow) * (*it);
        m += std::pow(_la, _npow);
    }
    return r / m;
}

template <typename T> T wma (std::vector<T> & v, int _range) {
    T r = static_cast<T>(0.0), m = static_cast<T>(0.0);
    T n = static_cast<T>(_range);
    T step = static_cast<T>(0.0);
    for (auto it = v.begin() + _range -1; !!_range; --it, --_range, ++n, ++step) {
        T _m = (n - step);
        r += _m * (*it);
        m += _m;
    }
    return r / m;
}

} // namespace math
} // namespace gidway
#endif // __GIDWAY_MATH_HH__
