cmake_minimum_required(VERSION 3.10)
add_definitions(-DOS_LINUX)
project(software_engineering)
set(CMAKE_CXX_STANDARD 11)


include_directories("${PROJECT_SOURCE_DIR}")
include_directories(src/support)
include_directories(src/support/handy)
include_directories(src/tools)
include_directories(src)

#add ArduinoJson
aux_source_directory(src/support/ArduinoJson ArduinoJson_lib)
set(ArduinoJson ${ArduinoJson_lib})

#add MD5
aux_source_directory(src/support/MD5_coding MD5_lib)
set(MD5 ${MD5_lib})

#add message
aux_source_directory(src/message message_lib)
set(Message ${message_lib})

#add handy
aux_source_directory(${CMAKE_SOURCE_DIR}/src/support/handy/handy HANDY_SRCS)
add_library(handy
        ${HANDY_SRCS}
        )

add_executable(test_main test/random_test.cpp)
add_executable(test_json test/tools/json/test_json.cpp
        ${ArduinoJson}
        )
add_executable(test_message test/message/test_message.cpp
        ${ArduinoJson}
        ${Message}
        ${MD5}
        )
#####handy module
set(handy_path src/support/handy)

add_executable(codec-cli
        ${handy_path}/examples/codec-cli.cc)
target_link_libraries(codec-cli handy pthread)

add_executable(codec-svr
        ${handy_path}/examples/codec-svr.cc)
target_link_libraries(codec-svr handy pthread)

add_executable(daemon
        ${handy_path}/examples/daemon.cc)
target_link_libraries(daemon handy)

add_executable(echo
        ${handy_path}/examples/echo.cc)
target_link_libraries(echo handy)

add_executable(hsha
        ${handy_path}/examples/hsha.cc)
target_link_libraries(hsha handy)

add_executable(http-hello
        ${handy_path}/examples/http-hello.cc)
target_link_libraries(http-hello handy pthread)

add_executable(idle-close
        ${handy_path}/examples/idle-close.cc)
target_link_libraries(idle-close handy)

add_executable(reconnect
        ${handy_path}/examples/reconnect.cc)
target_link_libraries(reconnect handy)

add_executable(safe-close
        ${handy_path}/examples/safe-close.cc)
target_link_libraries(safe-close handy)

add_executable(stat
        ${handy_path}/examples/stat.cc)
target_link_libraries(stat handy)

add_executable(timer
        ${handy_path}/examples/timer.cc)
target_link_libraries(timer handy)

add_executable(udp-cli
        ${handy_path}/examples/udp-cli.cc)
target_link_libraries(udp-cli handy pthread)

add_executable(udp-hsha
        ${handy_path}/examples/udp-hsha.cc)
target_link_libraries(udp-hsha handy pthread)

add_executable(udp-svr
        ${handy_path}/examples/udp-svr.cc)
target_link_libraries(udp-svr handy pthread)

add_executable(write-on-empty
        ${handy_path}/examples/write-on-empty.cc)
target_link_libraries(write-on-empty handy)

add_executable(10m-cli
        ${handy_path}/10m/10m-cli.cc)
target_link_libraries(10m-cli handy)

add_executable(10m-svr
        ${handy_path}/10m/10m-svr.cc)
target_link_libraries(10m-svr handy)

add_executable(kqueue
        ${handy_path}/raw-examples/kqueue.cc)
target_link_libraries(kqueue handy)
