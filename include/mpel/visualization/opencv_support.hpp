#include "mpel/core/primitives/graph.hpp"
#include "mpel/core/primitives/path.hpp"
#include "mpel/core/primitives/point.hpp"
#include "mpel/core/primitives/problem_definition.hpp"
#include "mpel/core/primitives/workspace.hpp"

#include <utility>
#include <vector>
#include "opencv2/opencv.hpp"

namespace mpel
{
using opencv_point              = cv::Point2f;
using opencv_path               = std::vector<opencv_point>;
using opencv_workspace          = cv::Mat;
using opencv_segment            = std::pair<opencv_point, opencv_point>;
using opencv_problem_definition = std::pair<opencv_point, opencv_point>;
using opencv_graph              = std::vector<opencv_segment>;

opencv_point to_opencv(const Point& pt);
opencv_path to_opencv(const Path& path);
opencv_workspace to_opencv(const Workspace& ws);
opencv_problem_definition to_opencv(const ProblemDefinition& pd);
opencv_graph to_opencv(const Graph& g);
}