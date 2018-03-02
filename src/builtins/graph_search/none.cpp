#include "mpel/builtins/graph_searches.hpp"

namespace mpel
{
namespace builtins
{
namespace graph_search
{
Path None::find_path(const Graph& g, Point begin, Point end)
{
    Path p;
    append(p, begin);
    append(p, end);
    return p;
}
}  // namespace graph_search
}  // namespace builtins
}  // namespace mpel