#pragma once
#ifndef GAUSS_GEOMETRY_H_
#define GAUSS_GEOMETRY_H_

#include <string>
#include <vector>
#include <cstdint>

#include "coordinates.hpp"

using std::string;
using std::vector;
using bytes = vector<uint8_t>;

namespace gauss {
namespace geometry {

// Implements the OGC Simple Feature Access standard.
// See: https://www.ogc.org/standards/sfa
class geometry
{
  protected:
    coordinates data;

  public:
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

    // query
    virtual bool equals(geometry) const;
    virtual bool disjoint(geometry) const;
    virtual bool intersects(geometry) const;
    virtual bool touches(geometry) const;
    virtual bool crosses(geometry) const;
    virtual bool within(geometry) const;
    virtual bool contains(geometry) const;
    virtual bool overlaps(geometry) const;
    virtual bool relate(geometry, string) const;

    // analysis
    virtual double   distance(geometry) const;
    virtual geometry buffer(double) const;
    virtual geometry convexHull() const;
    virtual geometry intersection(geometry) const;
    virtual geometry unionWith(geometry) const;
    virtual geometry difference(geometry) const;
    virtual geometry symDifference(geometry) const;
};

} // namespace geometry
} // namespace gauss

#endif