#pragma once
#ifndef GAUSS_POINT_CLASS_H_
#define GAUSS_POINT_CLASS_H_

#include "../geometry.hpp"

namespace gauss {
namespace geometry {

class point : geometry
{
  public:
    point() noexcept;
    point(double, double) noexcept;
    double           X() const noexcept;
    double           Y() const noexcept;
    constexpr double Z() const noexcept;
    constexpr double M() const noexcept;

    // inherited from geometry
    virtual size_t   dimension() const noexcept;
    virtual size_t   coordinateDimension() const noexcept;
    virtual size_t   spatialDimension() const noexcept;
    virtual string   geometryType() const noexcept;
    virtual size_t   SRID() const noexcept;
    virtual geometry envelope() const noexcept;
    virtual string   asText() const noexcept;
    virtual bytes    asBinary() const noexcept;
    virtual bool     isEmpty() const noexcept;
    virtual bool     isSimple() const noexcept;
    virtual bool     is3D() const noexcept;
    virtual bool     isMeasured() const noexcept;
    virtual geometry boundary() const noexcept;
};

} // namespace geometry
} // namespace gauss

#endif