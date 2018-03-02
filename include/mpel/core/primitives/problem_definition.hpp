#ifndef MPEL_PRIMITIVES_PROBLEM_DEFINITION
#define MPEL_PRIMITIVES_PROBLEM_DEFINITION

#include "mpel/core/primitives/point.hpp"

namespace mpel
{
class ProblemDefinition
{
public:
    ProblemDefinition(Point begin, Point end);
    Point begin_, end_;
};
}  // namespace mpel

#endif  // MPEL_PRIMITIVES_PROBLEM_DEFINITION