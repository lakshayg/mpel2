#include "mpel/core/primitives/workspace.hpp"
#include <opencv2/opencv.hpp>
#include <stdexcept>

namespace mpel
{
Workspace Workspace::load_from_file(const char* filename)
{
    auto bitmap = cv::imread(filename, 0);  // read image in grayscale
    if (!bitmap.data)
    {
        throw std::runtime_error("Workspace file could not be loaded");
    }
    return Workspace(cv::imread(filename, 0));  // load as a grayscale image
}

Workspace::Workspace(cv::Mat map) : map_(map)
{
}

cv::Mat const& Workspace::get_bitmap() const
{
    return map_;
}

}  // namespace mpel