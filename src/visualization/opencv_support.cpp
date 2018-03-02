#include "mpel/visualization/opencv_support.hpp"

#include <algorithm>

namespace mpel
{
opencv_point to_opencv(const Point& pt)
{
    return opencv_point(pt.x(), pt.y());
}

opencv_path to_opencv(const Path& path)
{
    opencv_path cv_path(path.size());
    std::transform(
        path.begin(), path.end(), cv_path.begin(), [](const Point& e) {
            return to_opencv(e);
        });
    return cv_path;
}

opencv_workspace to_opencv(const Workspace& ws)
{
    return ws.get_bitmap();
}

opencv_problem_definition to_opencv(const ProblemDefinition& pd)
{
    return std::make_pair(to_opencv(pd.begin_), to_opencv(pd.end_));
}

opencv_graph to_opencv(const Graph& g)
{
    opencv_graph segments(num_edges(g));
    auto points = get(&VertexProperty::pt, g);
    for (auto edge : edges(g))
    {
        Vertex v1 = source(edge, g);
        Vertex v2 = target(edge, g);
        segments.emplace_back(to_opencv(points[v1]), to_opencv(points[v2]));
    }
    return segments;
}
}