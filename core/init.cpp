#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/async_logger.h>
#include <spdlog/async.h>


#include "init.h"
#include "binary.h"

namespace core {


void init(std::string binary_name){
    binary::setName(binary_name);
    initSpdLog(binary_name);
}


void initSpdLog(std::string binary_name) 
{
    // 设置日志格式
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e][%^%l%$] %v");

    spdlog::init_thread_pool(8192, 1);

    auto stdout_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt >();

    std::vector<spdlog::sink_ptr> sinks {stdout_sink};

    if (binary_name.empty()){
        auto rotating_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("log/" + binary_name, LOG_FILE_SIZE, LOG_FILE);
        sinks.push_back(rotating_sink);
    }

    auto logger = std::make_shared<spdlog::async_logger>("logger", sinks.begin(), sinks.end(), spdlog::thread_pool(), spdlog::async_overflow_policy::block);
    spdlog::register_logger(logger);
}


}

