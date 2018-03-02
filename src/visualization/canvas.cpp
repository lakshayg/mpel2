#include "mpel/visualization/canvas.hpp"
#include "mpel/visualization/opencv_support.hpp"
#include "opencv2/opencv.hpp"

namespace mpel
{
namespace color
{
const auto RED   = cv::Scalar(0, 0, 255);
const auto GREEN = cv::Scalar(0, 255, 0);
const auto BLUE  = cv::Scalar(255, 0, 0);
}  // namespace color

Canvas::Canvas(const Workspace& ws)
{
    auto img = ws.get_bitmap();
    cv::cvtColor(img, image_, cv::COLOR_GRAY2BGR);
}

Canvas& Canvas::add_layer(const Point& pt)
{
    constexpr auto radius    = 3;
    constexpr auto thickness = radius;
    cv::circle(image_, to_opencv(pt), radius, color::RED, thickness);
    return *this;
}

Canvas& Canvas::add_layer(const Path& p)
{
    constexpr auto thickness = 3;
    auto path                = to_opencv(p);
    for (size_t i = 0; i < p.size() - 1; ++i)
    {
        cv::line(image_, path[i], path[i + 1], color::BLUE, thickness);
    }
    return *this;
}

Canvas& Canvas::add_layer(const ProblemDefinition& pd)
{
    add_layer(pd.begin_);
    add_layer(pd.end_);
    return *this;
}

Canvas& Canvas::add_layer(const Graph& g)
{
    constexpr auto thickness = 3;
    auto segments            = to_opencv(g);
    for (auto& segment : segments)
    {
        cv::line(
            image_, segment.first, segment.second, color::GREEN, thickness);
    }
    return *this;
}

void Canvas::show()
{
    cv::imshow("Canvas", image_);
    cv::waitKey();
}
}