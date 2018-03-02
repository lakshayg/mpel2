#ifndef MPEL_CANVAS
#define MPEL_CANVAS

#include "mpel/core/primitives/graph.hpp"
#include "mpel/core/primitives/path.hpp"
#include "mpel/core/primitives/point.hpp"
#include "mpel/core/primitives/problem_definition.hpp"
#include "mpel/core/primitives/workspace.hpp"

namespace mpel
{
class Canvas
{
public:
    Canvas(const Workspace& ws);

    Canvas& add_layer(const Point& pt);
    Canvas& add_layer(const Path& pt);
    Canvas& add_layer(const ProblemDefinition& pd);
    Canvas& add_layer(const Graph& g);

    void show();

private:
    cv::Mat image_;
};
}  // namespace mpel
#endif  // MPEL_CANVAS