#ifndef LOG_H
#define LOG_H

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <sstream>
#include <string>

#include "core/binary.h"

// 定义函数式日志宏
#include <spdlog/spdlog.h>

#define LOG_INFO(fmt, ...)    SPDLOG_LOGGER_CALL(spdlog::default_logger_raw(), spdlog::level::info,    fmt, ##__VA_ARGS__)
#define LOG_WARN(fmt, ...)    SPDLOG_LOGGER_CALL(spdlog::default_logger_raw(), spdlog::level::warn,    fmt, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...)   SPDLOG_LOGGER_CALL(spdlog::default_logger_raw(), spdlog::level::err,     fmt, ##__VA_ARGS__)
#define LOG_DEBUG(fmt, ...)   SPDLOG_LOGGER_CALL(spdlog::default_logger_raw(), spdlog::level::debug,   fmt, ##__VA_ARGS__)


//基于流的形式的log
#define SLOG_INFO_IF(cond) LOG_IF(INFO, cond, MODULE_NAME)
#define SLOG_WARN_IF(cond) LOG_IF(WARN, cond, MODULE_NAME)
#define SLOG_ERROR_IF(cond) LOG_IF(ERROR, cond, MODULE_NAME)
#define SLOG_DEBUG_IF(cond) LOG_IF(DEBUG, cond, MODULE_NAME)

#define SLOG_INFO LOG_MODULE(MODULE_NAME,INFO)
#define SLOG_ERROR LOG_MODULE(MODULE_NAME,ERROR)
#define SLOG_WARNING LOG_MODULE(MODULE_NAME,WARN)
#define SLOG_DEBUG LOG_MODULE(MODULE_NAME,DEBUG)

#ifndef MODULE_NAME
#define MODULE_NAME core::binary::getName()
#endif // !MODULE_NAME


#ifndef LOG_MODULE
#define LOG_MODULE(module, log_severity) \
  LOG_MODULE_STREAM(log_severity)(module)
#endif

#ifndef LOG_MODULE_STREAM
#define LOG_MODULE_STREAM(log_severity) LOG_MODULE_STREAM_##log_severity
#endif

#define LEFT_BRACKET "["
#define RIGHT_BRACKET "] "

// Modified logging macros
#define LOG_MODULE_STREAM_INFO(module) SpdLogMessage(__FILE__, __LINE__, spdlog::level::info).stream() << LEFT_BRACKET  << module << RIGHT_BRACKET
#define LOG_MODULE_STREAM_WARN(module) SpdLogMessage(__FILE__, __LINE__, spdlog::level::warn).stream() << LEFT_BRACKET << module << RIGHT_BRACKET
#define LOG_MODULE_STREAM_ERROR(module) SpdLogMessage(__FILE__, __LINE__, spdlog::level::err).stream() << LEFT_BRACKET << module << RIGHT_BRACKET
#define LOG_MODULE_STREAM_DEBUG(module) SpdLogMessage(__FILE__, __LINE__, spdlog::level::debug).stream() << LEFT_BRACKET << module << RIGHT_BRACKET


#define LOG_IF(severity, cond, module) \
  !(cond) ? (void)(0)                     \
          : LogMessageVoidify() & LOG_MODULE(module, severity)

class SpdLogMessage {
public:
    SpdLogMessage(const char* file, int line, spdlog::level::level_enum level)
    : file_(ExtractFileName(file)), line_(line), level_(level) {}

    ~SpdLogMessage() {
        std::ostringstream oss;
        oss << "["<<file_ << ":" << line_ << "] " << stream_.str();
        auto message = oss.str();
        switch (level_) {
            case spdlog::level::info:
                spdlog::info(message);
                break;
            case spdlog::level::warn:
                spdlog::warn(message);
                break;
            case spdlog::level::err:
                spdlog::error(message);
                break;
            case spdlog::level::debug:
                spdlog::debug(message);
                break;
            // 其他日志级别可以根据需要添加
            default:
                spdlog::info(message); // 默认情况下使用 info 级别
        }
    }

    std::ostringstream& stream() { return stream_; }

    // Helper function to extract the filename from a path
    inline const char* ExtractFileName(const char* path) {
        const char* file = strrchr(path, '/');
        if (file) {
            return file + 1; // Skip past the last '/'
        }
        return path;
    }

private:
    const char* file_;
    int line_;
    spdlog::level::level_enum level_;
    std::ostringstream stream_;
};

class LogMessageVoidify {
 public:
  LogMessageVoidify() { }
  // This has to be an operator with a precedence lower than << but
  // higher than ?:
  void operator&(std::ostream&) { }
};

#endif // !LOG_H
