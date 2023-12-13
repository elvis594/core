

file(GLOB_RECURSE SOURCE_FILE 
    "protobuf/*.cpp"  
    "common/*.cpp"
    "log/*.cpp"
    "./*.cpp"
)


add_library(core ${SOURCE_FILE})
target_link_libraries(core ${LIB_SOURCE})
