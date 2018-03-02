#ifndef MPEL_GRAPH_BUILDER
#define MPEL_GRAPH_BUILDER

#include "mpel/core/primitives/graph.hpp"
#include "mpel/core/primitives/workspace.hpp"

namespace mpel
{
class GraphBuilder
{
public:
    virtual Graph construct_graph(const Workspace& ws) = 0;
};
}  // namespace mpel

#endif  // MPEL_GRAPH_BUILDER