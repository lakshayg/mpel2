#ifndef MPEL_BUILTIN_INTERPOLATORS
#define MPEL_BUILTIN_INTERPOLATORS

#include "mpel/core/interpolator.hpp"
#include "mpel/core/primitives/workspace.hpp"

#include <opencv2/opencv.hpp>

namespace mpel
{
namespace builtins
{
namespace interpolator
{
class None : public Interpolator
{
public:
    Path interpolate_segment(Point begin, Point end) override;
};

class Bug : public Interpolator
{
public:
    Path interpolate_segment(Point begin, Point end) override;
};

class Bug2 : public Interpolator
{
public:
    Path interpolate_segment(Point begin, Point end) override;
};

class PotentialField : public Interpolator
{
public:
    PotentialField(const Workspace& ws, double d = 25, double c = 250);
    Path interpolate(const Path& p) override;

private:
    cv::Mat repulsive_potential_;
};
}  // namespace interpolator
}  // namespace builtins
}  // namespace mpel

#endif  // MPEL_BUILTIN_INTERPOLATORS