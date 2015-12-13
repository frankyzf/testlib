//
// Created by feng on 12/13/15.
//

#include "easylog.h"

INITIALIZE_EASYLOGGINGPP

void config_init(const string& config_file){
    LOG(INFO) << "My first info log using default logger";

    // Load configuration from file
    el::Configurations conf(config_file);
    // Reconfigure single logger
    el::Loggers::reconfigureLogger("default", conf);
    LOG(INFO) << __FUNCTION__ << " reconfigure default";
    LOG(DEBUG) << __FUNCTION__ << " reconfigure default";

    // Actually reconfigure all loggers instead
    el::Loggers::reconfigureAllLoggers(conf);
    LOG(INFO) << __func__ <<  " reconfigure all";
    LOG(DEBUG) << __FUNCTION__<<  " reconfigure all";
    // Now all the loggers will use configuration from file

}



int config_easylog() {
    el::Configurations defaultConf;
    defaultConf.setToDefault();
    // Values are always std::string
    defaultConf.set(el::Level::Info,
                    el::ConfigurationType::Format, "%datetime %level %msg");
    // default logger uses default configurations
    el::Loggers::reconfigureLogger("default", defaultConf);
    LOG(INFO) << "Log using default file";
    // To set GLOBAL configurations you may use
    defaultConf.setGlobally(
            el::ConfigurationType::Format, "%datetime %msg");
    el::Loggers::reconfigureLogger("default", defaultConf);
    LOG(INFO) << "Log using logging default file";
    return 0;
}