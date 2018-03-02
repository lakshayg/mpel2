#include "mpel/core/primitives/point.hpp"

namespace std
{
std::ostream& operator<<(std::ostream& os, const mpel::Point& pt)
{
    os << '(' << pt.x() << ", " << pt.y() << ')';
    return os;
}
}  // namespace mpel