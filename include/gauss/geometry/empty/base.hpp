#pragma once
#include <vector>
#ifndef GAUSS_EMPTY_BASE_H_
#define GAUSS_EMPTY_BASE_H_
#include "class.hpp"

namespace gauss {
namespace geometry {

inline empty::empty() noexcept
{
    this->data = coordinates();
}

inline size_t empty::dimension() const noexcept
{
    return -1;
}

inline size_t empty::coordinateDimension() const noexcept
{
    return -1;
}

inline size_t empty::spatialDimension() const noexcept
{
    return -1;
}

inline string empty::geometryType() const noexcept
{
    return "EMPTY";
}

inline size_t empty::SRID() const noexcept
{
    return -1;
}

inline geometry empty::envelope() const noexcept
{
    return *this;
}

inline string empty::asText() const noexcept
{
    return "EMPTY ()";
}

inline bytes empty::asBinary() const noexcept
{
    return vector<uint8_t>();
}

inline bool empty::isEmpty() const noexcept
{
    return true;
}

inline bool empty::isSimple() const noexcept
{
    return true;
}

inline bool empty::is3D() const noexcept
{
    return false;
}

inline bool empty::isMeasured() const noexcept
{
    return false;
}

inline geometry empty::boundary() const noexcept
{
    return *this;
}

} // namespace geometry
} // namespace gauss
#endif