
#include "core/common/log.h"
#include "core/common/init.h"


int main(int argc, const char **argv)
{
	if(argc > 2){
		return 0;
	}

    int x = 120;
    InitSpdLog();
    
    SLOG_ERROR << "This is an info message " << 0.5f;
    SLOG_INFO << "This is a warning message";
    SLOG_WARNING << "This is an error message";
    SLOG_INFO << "This is a debug message";

    SLOG_INFO_IF(x > 10) << "this";

    LOG_INFO("HELLO WORLD: {}",42);

	return 0;
}


