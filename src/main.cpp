
#include "core/common/log.h"
#include "core/init.h"

int main(int argc, const char **argv)
{
	if(argc > 2){
		return 0;
	}
    
    core::init("hello world");
    LOG_INFO("HELLO WORLD");

	return 0;
}


