#ifndef INIT_H
#define INIT_H

#include <string>

#define LOG_FILE_SIZE 1024*1024*10
#define LOG_FILE 3

namespace core {

void init(std::string binary_name);

void initSpdLog(std::string binary_name);

}   // namespace core
#endif // !INIT_H