# CMakeList.txt: shadowsocksrr-asio 的 CMake 项目，包括源和定义
# 此处特定于项目的逻辑。
#
cmake_minimum_required (VERSION 3.11)

set(THREADS_PREFER_PTHREAD_FLAG ON)
if(STATIC)
    set(Boost_USE_STATIC_LIBS ON)
endif()

find_package(Boost 1.54.0 REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})


set (src_VERSION "version.cpp" "version.h")
set (src_LOG "log.cpp" "log.h")

set (src_ARCHITECT 
	"service.cpp" "service.h" 
	"server-manager.cpp" "server-manager.h"
	"main-config.cpp" "main-config.h"
	"base-server.cpp" "base-server.h"
)

set (src_SSR 
	"ssr/ssr-config.cpp" "ssr/ssr-config.h"
	"ssr/ssr-server.cpp" "ssr/ssr-server.h"
)

set (src_MAIN "main.cpp")

# 将源添加到此项目的可执行文件。
add_executable (shadowsocksrrasio ${src_MAIN} ${src_ARCHITECT} ${src_VERSION} ${src_LOG} ${src_SSR})

target_link_libraries(shadowsocksrrasio ${Boost_LIBRARIES})

# TODO: 如有需要，请添加测试并安装目标。
