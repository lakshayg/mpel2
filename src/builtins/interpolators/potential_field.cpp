#include "mpel/builtins/interpolators.hpp"
#include "mpel/core/primitives/workspace.hpp"
#include "mpel/logger.hpp"

namespace mpel
{
namespace builtins
{
namespace interpolator
{
namespace detail
{
double repulsive_potential(double distance, double d, double c)
{
    // compute the repulsive potential
    //              /  1      1 \ 2
    // f(x) =  c * | ----- - --- |   for r(x) < d0
    //              \ r(x)    d /

    if (distance >= d)
        return 0;
    double p = (1.0 / distance - 1.0 / d);
    return c * p * p;
}
}  // namespace detail

PotentialField::PotentialField(const Workspace& ws, double d, double c)
{
    // compute the distance transform of workspace bitmap
    // we can precompute this because the repulsive potential is
    // independent of the motion planning problem and depends only
    // on the workspace
    cv::Mat dt;
    cv::distanceTransform(
        ws.get_bitmap(), dt, CV_DIST_L2, CV_DIST_MASK_PRECISE);
    dt.convertTo(dt, CV_64F);

    repulsive_potential_ = cv::Mat::zeros(dt.rows, dt.cols, CV_64FC1);
    for (auto i = 0; i < dt.rows; ++i)
    {
        for (auto j = 0; j < dt.cols; ++j)
        {
            auto pt       = cv::Point(j, i);
            auto distance = dt.at<double>(pt);
            repulsive_potential_.at<double>(pt)
                = detail::repulsive_potential(distance, d, c);
        }
    }
}

Path PotentialField::interpolate(const Path& p)
{
    if (p.size() < 2)
    {
        LOG(warning) << "Path contains fewer than two points (" << p.size()
                     << "), Skipping interpolation.";
        return p;
    }

    Point curr = p.front();
    return Path();
}
}  // namespace interpolator
}  // namespace builtins
}  // namespace mpel