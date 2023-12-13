
#include <mutex>
#include <string>

#include "binary.h"

namespace {
std::mutex m;
std::string binary_name; // NOLINT
}  // namespace

namespace core {
namespace binary {
    std::string getName()
    {
        std::lock_guard<std::mutex> lock(m);
        return binary_name;
    }
    void setName(const std::string &name)
    {
        std::lock_guard<std::mutex> lock(m);
        binary_name = name;
    }
}
}

