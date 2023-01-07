#pragma once
#ifndef GAUSS_COORDINATES_H_
#define GAUSS_COORDINATES_H_

#include <vector>
#include <stdexcept>

using std::initializer_list;
using std::vector;

namespace { // private
constexpr inline uint64_t as_integer_coordinate(double x) noexcept
{
    return static_cast<uint64_t>(x * 1e6);
}

constexpr inline double as_double_coordinate(uint64_t x) noexcept
{
    return static_cast<double>(x) / 1e6;
}

struct coordinate_point
{
    double x, y;
};
} // namespace

namespace gauss {
namespace geometry {

class coordinates
{
    vector<uint64_t> _data;

  public:
    coordinates();
    coordinates(size_t);
    coordinates(initializer_list<double>);
    coordinates(initializer_list<uint64_t>);

    size_t           size() const noexcept;
    size_t           data_size() const noexcept;
    coordinate_point at(size_t) const;
    coordinate_point operator[](size_t) const;
};

/** constructors **/

inline coordinates::coordinates()
  : _data(vector<uint64_t>())
{
}

// @param size number of points to allocate for. capacity of the internal object
// will be size*2.
inline coordinates::coordinates(size_t size)
  : _data(vector<uint64_t>(size * 2))
{
}

inline coordinates::coordinates(initializer_list<double> x)
{

    if (x.size() % 2 != 0) {
        throw std::runtime_error("[coordinates::default_constructor] complete "
                                 "pairs are not given in initializer list.");
    }

    this->_data.reserve(x.size());
    for (auto& c : x) {
        this->_data.push_back(as_integer_coordinate(c));
    }
}

inline coordinates::coordinates(initializer_list<uint64_t> x)
  : _data(x)
{
}

/** methods **/

inline size_t coordinates::size() const noexcept
{
    return this->data_size() / 2;
}

inline size_t coordinates::data_size() const noexcept
{
    return this->_data.size();
}

inline coordinate_point coordinates::at(size_t index) const
{
    if (index > this->size()) {
        char* errmsg = nullptr;
        std::sprintf(
          errmsg,
          "[coordinates::at] index %d is out of bounds. maximum index is %d.",
          index,
          this->size() - 1
        );

        throw std::out_of_range(errmsg);
    }

    return coordinate_point{
        as_double_coordinate(this->_data.at(index * 2)),
        as_double_coordinate(this->_data.at((index * 2) + 1))
    };
}

inline coordinate_point coordinates::operator[](size_t index) const
{
    return this->at(index);
}
} // namespace geometry
} // namespace gauss
#endif
