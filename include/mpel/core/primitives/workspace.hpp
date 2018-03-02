#ifndef MPEL_PRIMITIVES_WORKSPACE
#define MPEL_PRIMITIVES_WORKSPACE

#include "opencv2/opencv.hpp"

namespace mpel
{
class Workspace
{
public:
    static Workspace load_from_file(const char* filename);
    explicit Workspace() = default;
    cv::Mat const& get_bitmap() const;

private:
    Workspace(cv::Mat map);
    cv::Mat map_;
};
}  // namespace mpel

#endif  // MPEL_PRIMITIVES_WORKSPACE