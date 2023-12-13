

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/log SOURCE_FILE)


add_library(core ${SOURCE_FILE})
target_link_libraries(core ${LIB_SOURCE})
