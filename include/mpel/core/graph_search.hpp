#ifndef MPEL_GRAPH_SEARCH
#define MPEL_GRAPH_SEARCH

#include "mpel/core/primitives/graph.hpp"
#include "mpel/core/primitives/path.hpp"
#include "mpel/core/primitives/point.hpp"

namespace mpel
{
class GraphSearch
{
public:
    virtual Path find_path(const Graph& g, Point begin, Point end) = 0;
};
}  // namespace mpel

#endif  // MPEL_GRAPH_SEARCH