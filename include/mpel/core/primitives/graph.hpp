#ifndef MPEL_PRIMITIVES_GRAPH
#define MPEL_PRIMITIVES_GRAPH

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/undirected_graph.hpp>
#include "mpel/core/primitives/point.hpp"

namespace mpel
{
struct EdgeProperty
{
    double weight;
};

struct VertexProperty
{
    Point pt;
};

using Graph      = boost::adjacency_list<boost::vecS,
                                    boost::vecS,
                                    boost::undirectedS,
                                    VertexProperty,
                                    EdgeProperty>;
using Vertex     = boost::graph_traits<Graph>::vertex_descriptor;
using Edge       = boost::graph_traits<Graph>::edge_descriptor;
using VertexIter = boost::graph_traits<Graph>::vertex_iterator;
using EdgeIter   = boost::graph_traits<Graph>::edge_iterator;
using boost::add_edge;
using boost::add_vertex;
using boost::edges;
using boost::num_edges;
using boost::source;
using boost::target;
}  // namespace mpel

namespace std
{
mpel::EdgeIter begin(const std::pair<mpel::EdgeIter, mpel::EdgeIter>&);
mpel::EdgeIter end(const std::pair<mpel::EdgeIter, mpel::EdgeIter>&);
mpel::VertexIter begin(const std::pair<mpel::VertexIter, mpel::VertexIter>&);
mpel::VertexIter end(const std::pair<mpel::VertexIter, mpel::VertexIter>&);
}  // namespace std

#endif  // MPEL_PRIMITIVES_GRAPH