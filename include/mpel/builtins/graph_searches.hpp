#ifndef MPEL_BUILTIN_GRAPH_SEARCHES
#define MPEL_BUILTIN_GRAPH_SEARCHES

#include "mpel/core/graph_search.hpp"

namespace mpel
{
namespace builtins
{
namespace graph_search
{
class None : public GraphSearch
{
public:
    Path find_path(const Graph& g, Point begin, Point end) override;
};

class Dijkstra : public GraphSearch
{
public:
    Path find_path(const Graph& g, Point begin, Point end) override;
};

class BreadthFirst : public GraphSearch
{
public:
    Path find_path(const Graph& g, Point begin, Point end) override;
};

class BidirectionalBreadthFirst : public GraphSearch
{
public:
    Path find_path(const Graph& g, Point begin, Point end) override;
};

class AStar : public GraphSearch
{
public:
    Path find_path(const Graph& g, Point begin, Point end) override;
};
}  // namespace graph_search
}  // namespace builtins
}  // namespace mpel

#endif  // MPEL_BUILTIN_GRAPH_SEARCHES