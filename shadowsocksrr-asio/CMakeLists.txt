# CMakeList.txt : 顶级 CMake 项目文件，执行全局配置
# 和此处的包含子项目。
#
cmake_minimum_required (VERSION 3.11)

project ("shadowsocksrr-asio")

# The version number.
set (SSRR_ASIO_VERSION_MAJOR 0)
set (SSRR_ASIO_VERSION_MINOR 0)
set (SSRR_ASIO_VERSION_PATCH 1)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_SOURCE_DIR}/config.h"
)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/3thLib/libsodium/")
find_package(sodium)

# 包含子项目。
add_subdirectory ("shadowsocksrr-asio")
