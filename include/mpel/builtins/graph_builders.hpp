#ifndef MPEL_BUILTIN_GRAPH_BUILDERS
#define MPEL_BUILTIN_GRAPH_BUILDERS

#include "mpel/core/graph_builder.hpp"

namespace mpel
{
namespace builtins
{
namespace graph_builder
{
class None : public GraphBuilder
{
public:
    Graph construct_graph(const Workspace& ws) override;
};

class ProbabilisticRoadmap : public GraphBuilder
{
public:
    Graph construct_graph(const Workspace& ws) override;
};

class VoronoiRoadmap : public GraphBuilder
{
public:
    Graph construct_graph(const Workspace& ws) override;
};

class RandomTrees : public GraphBuilder
{
public:
    Graph construct_graph(const Workspace& ws) override;
};
}  // namespace graph_builder
}  // namespace builtins
}  // namespace mpel

#endif  // MPEL_BUILTIN_GRAPH_BUILDERS