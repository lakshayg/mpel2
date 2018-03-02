#ifndef MPEL_PRIMITIVES_POINT
#define MPEL_PRIMITIVES_POINT

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <ostream>

namespace mpel
{
using Point = boost::geometry::model::d2::point_xy<double>;
using boost::geometry::comparable_distance;  // comparable_distance is not the
                                             // same as actual distance but such
                                             // that distance_1 < distance_2
                                             // implies comp_distance_1 <
                                             // comp_distance_2 and is faster to
                                             // compute
using boost::geometry::distance;  // compute distance between any two geometries
}  // namespace mpel

namespace std
{
std::ostream& operator<<(std::ostream& os, const mpel::Point& pt);
}  // namespace std

#endif  // MPEL_PRIMITIVES_POINT