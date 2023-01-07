#pragma once
#ifndef GAUSS_UTILS_COMPARE_H_
#define GAUSS_UTILS_COMPARE_H_

#include <cmath>
#include <limits>
#include <type_traits>

namespace gauss {
namespace utils {

template<typename T>
using numeric_t =
  typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type;

template<typename T>
numeric_t<T> equals(T a, T b) noexcept
{
    return std::fabs(a - b) < std::numeric_limits<T>::epsilon();
}

} // namespace utils
} // namespace gauss

#endif