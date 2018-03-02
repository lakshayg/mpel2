#include "mpel/builtins/interpolators.hpp"

namespace mpel
{
namespace builtins
{
namespace interpolator
{
Path None::interpolate_segment(Point begin, Point end)
{
    Path p;
    append(p, begin);
    return p;
}
}  // namespace interpolator
}  // namespace builtins
}  // namespace mpel