cmake_minimum_required(VERSION 3.13)

##=====================公共变量=====================
# 设置项目根目录
set(ROOT_DIR                 ${CMAKE_CURRENT_SOURCE_DIR})
# 3rd library 搜索路径
set(MAIN_PRJ_SRC_DIR         ${ROOT_DIR})
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
set(RELEASE_DIR ${CMAKE_CURRENT_LIST_DIR}/release)


# 项目名称
project(core)

##=====================统一编译输出路径=====================
set(LIBRARY_OUTPUT_PATH ${RELEASE_DIR}/${BUILD_TARGET}/lib)
set(EXECUTABLE_OUTPUT_PATH ${RELEASE_DIR}/${BUILD_TARGET}/bin)
set(TEST_EXECUTABLE_OUTPUT_PATH ${RELEASE_DIR}/${BUILD_TARGET}/test)
set(INCLUDE_OUTPUT_PATH ${RELEASE_DIR}/include)
link_directories(${RELEASE_DIR}/${BUILD_TARGET}/lib)

include_directories(${ROOT_DIR}/)


add_subdirectory(${ROOT_DIR}/src)
add_subdirectory(${ROOT_DIR}/core)




