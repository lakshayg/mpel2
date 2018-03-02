#include "mpel/core/planner.hpp"
#include <boost/shared_ptr.hpp>

namespace mpel
{
Planner::Planner(GraphBuilder* graph_builder,
                 GraphSearch* graph_search,
                 Interpolator* interpolator)
    : graph_builder_(graph_builder)
    , graph_search_(graph_search)
    , interpolator_(interpolator)
{
}

void Planner::set_workspace(Workspace& ws)
{
    ws_    = ws;
    graph_ = graph_builder_->construct_graph(ws);
}

Path Planner::solve(const ProblemDefinition& pdef)
{
    geometric_path_ = graph_search_->find_path(graph_, pdef.begin_, pdef.end_);
    interpolated_path_ = interpolator_->interpolate(geometric_path_);
    return interpolated_path_;
}

Graph const& Planner::graph() const
{
    return graph_;
}

Path const& Planner::geometric_path() const
{
    return geometric_path_;
}

}  // namespace mpel