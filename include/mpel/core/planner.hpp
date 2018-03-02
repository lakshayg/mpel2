#ifndef MPEL_PLANNER
#define MPEL_PLANNER

#include "mpel/core/graph_builder.hpp"
#include "mpel/core/graph_search.hpp"
#include "mpel/core/interpolator.hpp"
#include "mpel/core/primitives/graph.hpp"
#include "mpel/core/primitives/path.hpp"
#include "mpel/core/primitives/problem_definition.hpp"
#include "mpel/core/primitives/workspace.hpp"

#include <boost/shared_ptr.hpp>

namespace mpel
{
class Planner
{
public:
    Planner(GraphBuilder* graph_builder,
            GraphSearch* graph_search,
            Interpolator* interpolator);

    void set_workspace(Workspace& ws);

    Path solve(const ProblemDefinition& pdef);

    Graph const& graph() const;
    Path const& geometric_path() const;

private:
    boost::shared_ptr<GraphBuilder> graph_builder_;
    boost::shared_ptr<GraphSearch> graph_search_;
    boost::shared_ptr<Interpolator> interpolator_;

    Workspace ws_;
    Graph graph_;
    Path geometric_path_;
    Path interpolated_path_;
};
}  // namespace mpel

#endif  // MPEL_PLANNER