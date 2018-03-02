#ifndef MPEL_LOGGING
#define MPEL_LOGGING

#include <boost/log/trivial.hpp>
#include <iostream>

namespace logging = boost::log;
namespace kw      = logging::keywords;
namespace expr    = logging::expressions;
namespace sinks   = logging::sinks;
static class Logger
{
public:
    Logger()
    {
    }
} __mpel_logger;

#define LOG(lvl) BOOST_LOG_TRIVIAL(lvl)

#endif  // MPEL_LOGGING