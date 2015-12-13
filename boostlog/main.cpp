#include <iostream>
#include <boost/log/trivial.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

using namespace std;

namespace logging = boost::log;
namespace sinks = boost::log::sinks;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;

void init() {
//    logging::add_file_log(
//            keywords::file_name = "sample_%N.log",
//            keywords::rotation_size = 10 * 1024 * 1024,
//            keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
//            keywords::format = "[%TimeStamp%]: %Message%"
//    );
    logging::add_file_log("sample.log");
    logging::core::get()->set_filter(logging::trivial::severity >= logging::trivial::info);
}


void log() {


}


int main() {
    init();
    logging::add_common_attributes();
    using namespace logging::trivial;
    src::severity_logger< logging::trivial::severity_level > lg;
    BOOST_LOG_SEV(lg, trace) << "A trace severity message";
    BOOST_LOG_SEV(lg, debug) << "A debug severity message";
    BOOST_LOG_SEV(lg, info) << "An informational severity message";
    BOOST_LOG_SEV(lg, warning) << "A warning severity message";
    BOOST_LOG_SEV(lg, error) << "An error severity message";
    BOOST_LOG_SEV(lg, fatal) << "A fatal severity message";

    cout << "Hello, World!" << endl;
    return 0;
}