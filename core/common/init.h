#ifndef INIT_H
#define INIT_H

#include <string>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>


void InitSpdLog(std::string file,std::string level) {
    // 设置日志格式
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e][%^%l%$][thread %t] %v");

    // 设置日志级别
    spdlog::set_level(spdlog::level::debug); // 更改为你需要的级别

    // 创建彩色控制台日志器
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto logger = std::make_shared<spdlog::logger>("logger", console_sink);

    // 注册日志器
    spdlog::register_logger(logger);
}



#endif // !INIT_H