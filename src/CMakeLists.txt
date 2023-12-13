
set (SRC_LISTS
    main.cpp
)
set (LIB_LISTS
    pthread
    core
)

add_executable(hello_world ${SRC_LISTS})

target_link_libraries(hello_world
    ${LIB_LISTS}
)
