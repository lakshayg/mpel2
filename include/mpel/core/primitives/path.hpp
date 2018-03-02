#ifndef MPEL_PRIMITIVES_PATH
#define MPEL_PRIMITIVES_PATH

#include <boost/geometry.hpp>
#include "mpel/core/primitives/point.hpp"

namespace mpel
{
using Path = boost::geometry::model::linestring<Point>;
using boost::geometry::append;               // append a point to Path
using boost::geometry::comparable_distance;  // comparable_distance is not the
                                             // same as actual distance but such
                                             // that distance_1 < distance_2
                                             // implies comp_distance_1 <
                                             // comp_distance_2 and is faster to
                                             // compute
using boost::geometry::distance;  // compute distance between any 2 geometries
using boost::geometry::length;    // compute total length of Path
}  // namespace mpel

namespace std
{
std::ostream& operator<<(std::ostream& os, const mpel::Path& pt);
}  // namespace std

#endif  // MPEL_PRIMITIVES_PATH