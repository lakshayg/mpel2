#include "mpel/core/primitives/graph.hpp"

namespace std
{
mpel::EdgeIter begin(
    const std::pair<mpel::EdgeIter, mpel::EdgeIter>& edge_iters)
{
    return edge_iters.first;
}

mpel::EdgeIter end(const std::pair<mpel::EdgeIter, mpel::EdgeIter>& edge_iters)
{
    return edge_iters.second;
}

mpel::VertexIter begin(
    const std::pair<mpel::VertexIter, mpel::VertexIter>& vertex_iters)
{
    return vertex_iters.first;
}

mpel::VertexIter end(
    const std::pair<mpel::VertexIter, mpel::VertexIter>& vertex_iters)
{
    return vertex_iters.second;
}
}  // namespace std