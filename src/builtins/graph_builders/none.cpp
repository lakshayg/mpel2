#include "mpel/builtins/graph_builders.hpp"

namespace mpel
{
namespace builtins
{
namespace graph_builder
{
Graph None::construct_graph(const Workspace& ws)
{
    return Graph();
}
}  // namespace graph_builders
}  // namespace builtins
}  // namespace mpel