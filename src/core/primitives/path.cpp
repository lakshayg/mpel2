#include "mpel/core/primitives/path.hpp"

namespace std
{
std::ostream& operator<<(std::ostream& os, const mpel::Path& path)
{
    os << '{';
    for (size_t i = 0; i < path.size(); ++i)
    {
        if (i)
        {
            os << ", ";
        }
        os << path[i];
    }
    os << '}';
    return os;
}
}  // namespace mpel