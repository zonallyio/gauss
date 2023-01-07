#pragma once
#ifndef GAUSS_POINT_BASE_H_
#define GAUSS_POINT_BASE_H_

#include "class.hpp"

namespace gauss {
namespace geometry {

inline point::point() noexcept
{
    this->data = { 0.0, 0.0 };
}

inline point::point(double x, double y) noexcept
{
    this->data = { x, y };
}

inline double point::X() const noexcept
{
    return this->data[0].x;
}

inline double point::Y() const noexcept
{
    return this->data[0].y;
}

inline constexpr double point::Z() const noexcept
{
    return __builtin_nan("0"); // not implemented
}

inline constexpr double point::M() const noexcept
{
    return __builtin_nan("0"); // not implemented
}

inline size_t point::dimension() const noexcept
{
    return 0;
}

inline size_t point::coordinateDimension() const noexcept
{
    return 2;
}

inline size_t point::spatialDimension() const noexcept
{
    return 2;
}

inline string point::geometryType() const noexcept
{
    return "POINT";
}

inline size_t point::SRID() const noexcept
{
    return 0;
}

inline bool point::isEmpty() const noexcept
{
    return false;
}
inline bool point::isSimple() const noexcept
{
    return true;
}

inline bool point::is3D() const noexcept
{
    return false;
}

inline bool point::isMeasured() const noexcept
{
    return false;
}

inline geometry point::boundary() const noexcept
{
    // empty set
}

} // namespace geometry
} // namespace gauss
#endif