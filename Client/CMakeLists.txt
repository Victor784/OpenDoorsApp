cmake_minimum_required(VERSION "3.25.1")

project(CLIENT
    VERSION 1.0
    DESCRIPTION "MiniClient"
    LANGUAGES CXX)

add_executable(Client WIN32
    src/Connection/Connection.hpp
    src/Connection/Connection.cpp
    src/Client/Client.hpp
    src/Client/Client.cpp
    src/UI/Panel.hpp
    src/UI/Ui.hpp
    src/UI/Ui.cpp
    src/UI/ConcretePanels.hpp
    src/UI/ConcretePanels.cpp
    src/Repo/Entrance.hpp
    src/Repo/Entrance.cpp
    src/Repo/Room.hpp
    src/Repo/Room.cpp
    src/Repo/House.hpp
    src/Repo/House.cpp
    utils/utils.hpp
    utils/utils.cpp
    src/Logger/logger.hpp
    src/Logger/logger.cpp
    src/Connection/WSConnection.hpp
    src/Connection/WSConnection.cpp
    src/main.cpp
    
    )

if(WIN32)
    target_link_libraries(Client wsock32 ws2_32)
endif()

set_target_properties(Client PROPERTIES WIN32_EXECUTABLE FALSE)


target_compile_features(Client PRIVATE cxx_std_20)