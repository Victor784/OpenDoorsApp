cmake_minimum_required(VERSION "3.25.1")

project(SERVER
    VERSION 1.0
    DESCRIPTION "MiniServer"
    LANGUAGES CXX)
add_executable(Server
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

set_source_files_properties(lib/sqlite3/sqlite3.c PROPERTIES LANGUAGE C)

add_library(sqlite3 STATIC lib/sqlite3/sqlite3.c)

target_link_libraries(Server sqlite3)
target_include_directories(Server PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/sqlite3/)


#target_include_directories(Server PUBLIC C:/users/victo/Desktop/ProjectsCPP/MiniClientServer/Server/lib/sqlite3/sqlite3.h)