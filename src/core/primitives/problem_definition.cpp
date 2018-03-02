#include "mpel/core/primitives/problem_definition.hpp"

namespace mpel
{
ProblemDefinition::ProblemDefinition(Point begin, Point end)
    : begin_(begin), end_(end)
{
}
}  // namespace mpel