#include "mpel/core/interpolator.hpp"

#include <algorithm>

namespace mpel
{
Path Interpolator::interpolate_segment(Point begin, Point end)
{
    Path p;
    append(p, begin);
    return p;
}

Path Interpolator::interpolate(const Path& p)
{
    Path interpolated;
    for (size_t i = 0; i < p.size() - 1; ++i)
    {
        auto interpolated_segment = interpolate_segment(p[i], p[i + 1]);
        std::move(interpolated_segment.begin(),
                  interpolated_segment.end(),
                  std::back_inserter(interpolated));
    }
    interpolated.push_back(p.back());
    return interpolated;
}
}