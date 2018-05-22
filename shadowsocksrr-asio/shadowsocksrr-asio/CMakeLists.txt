# CMakeList.txt: shadowsocksrr-asio 的 CMake 项目，包括源和定义
# 此处特定于项目的逻辑。
#
cmake_minimum_required (VERSION 3.11)

set(THREADS_PREFER_PTHREAD_FLAG ON)
if(STATIC)
    set(Boost_USE_STATIC_LIBS ON)
endif()

if(MSVC)
	# _WIN32_WINNT version constants
	#define _WIN32_WINNT_NT4                    0x0400 // Windows NT 4.0  
	#define _WIN32_WINNT_WIN2K                  0x0500 // Windows 2000  
	#define _WIN32_WINNT_WINXP                  0x0501 // Windows XP  
	#define _WIN32_WINNT_WS03                   0x0502 // Windows Server 2003  
	#define _WIN32_WINNT_WIN6                   0x0600 // Windows Vista  
	#define _WIN32_WINNT_VISTA                  0x0600 // Windows Vista  
	#define _WIN32_WINNT_WS08                   0x0600 // Windows Server 2008  
	#define _WIN32_WINNT_LONGHORN               0x0600 // Windows Vista  
	#define _WIN32_WINNT_WIN7                   0x0601 // Windows 7  
	#define _WIN32_WINNT_WIN8                   0x0602 // Windows 8  
	#define _WIN32_WINNT_WINBLUE                0x0603 // Windows 8.1  
	#define _WIN32_WINNT_WINTHRESHOLD           0x0A00 // Windows 10  
	#define _WIN32_WINNT_WIN10                  0x0A00 // Windows 10  
	add_definitions(-D_WIN32_WINNT=0x0A00)	 # Windows 10
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
	"resource-manager/udp-port-manager.cpp" "resource-manager/udp-port-manager.h"
)

set (src_SSR_ARCHITECT_TCP 
	"ssr/ssr-session-base.cpp" "ssr/ssr-session-base.h"
	"ssr/ssr-session-server.cpp" "ssr/ssr-session-server.h"
	"ssr/ssr-session-client.cpp" "ssr/ssr-session-client.h"
)

set (src_SSR_ARCHITECT_UDP 
	"ssr/ssr-udp-base.cpp" "ssr/ssr-udp-base.h"
	"ssr/ssr-udp-server.cpp" "ssr/ssr-udp-server.h"
	"ssr/ssr-udp-client.cpp" "ssr/ssr-udp-client.h"
)

set (src_SSR_ARCHITECT 
	"ssr/ssr-config.cpp" "ssr/ssr-config.h"
	"ssr/ssr-server.cpp" "ssr/ssr-server.h"
	"ssr/ssr-dns-resolver.cpp" "ssr/ssr-dns-resolver.h"
)

set (src_SSR_ALL 
	${src_SSR_ARCHITECT}
	${src_SSR_ARCHITECT_TCP}
	${src_SSR_ARCHITECT_UDP}
)
set (src_SOCKS5 
	"socks5/socks5-protocol.cpp" "socks5/socks5-protocol.h"
)

set (src_MAIN "main.cpp")

# 将源添加到此项目的可执行文件。
add_executable (shadowsocksrrasio 
	${src_MAIN}
	${src_ARCHITECT}
	${src_VERSION}
	${src_LOG}
	${src_SOCKS5}
	${src_SSR_ALL}
)

target_link_libraries(shadowsocksrrasio ${Boost_LIBRARIES})

# TODO: 如有需要，请添加测试并安装目标。
