#ifndef MPEL_INTERPOLATOR
#define MPEL_INTERPOLATOR

#include "mpel/core/primitives/path.hpp"

namespace mpel
{
// The Interpolate interface must be implemented in a user
// class for it to be a component in the motion planner. The
// planner calls only the interpolate method of this class
// therefore the user can choose to override only the interpolate
// method and leave the interpolate_segment method.
//
// In the case when interpolate_segment is overridden, the call
// to interpolate applies interpolate_segment to each segment in
// the path provided as input.
class Interpolator
{
public:
    // interpolate_segment takes [begin, end] and returns a path
    // [begin, x1, x2, ..., xn]. The returned path must NOT contain
    // the end point.
    virtual Path interpolate_segment(Point begin, Point end);

    // interpolates a path by calling interpolate_segment on
    // pairs of points in the path. This fuction is virtual
    // therefore this behaviour can be changed.
    virtual Path interpolate(const Path& p);

protected:
    // We do not want the user to create an instance of this class.
    Interpolator() = default;
};
}  // namespace mpel

#endif  // MPEL_INTERPOLATOR