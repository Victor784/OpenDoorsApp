cmake_minimum_required(VERSION "3.25.1")

project(SERVER
    VERSION 1.0
    DESCRIPTION "MiniServer"
    LANGUAGES CXX)

add_executable(Server WIN32
    src/Server/Server.hpp
    src/Server/Server.cpp
    utils/utils.hpp
    utils/utils.cpp
    src/Logger/logger.hpp
    src/Logger/logger.cpp
    src/Connection/WSConnection.hpp
    src/Connection/WSConnection.cpp
    src/main.cpp
    )

if(WIN32)
    target_link_libraries(Server wsock32 ws2_32)
endif()

set_target_properties(Server PROPERTIES WIN32_EXECUTABLE FALSE)


target_compile_features(Server PRIVATE cxx_std_20)