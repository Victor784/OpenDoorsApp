cmake_minimum_required(VERSION "3.25.1")

project(CLIENT
    VERSION 1.0
    DESCRIPTION "MiniClient"
    LANGUAGES CXX)

add_executable(Client
    src/Connection/Connection.hpp
    src/Connection/Connection.cpp
    src/Client/Client.hpp
    src/Client/Client.cpp
    src/UI/Panel.hpp
    src/UI/Ui.hpp
    src/UI/ConcretePanels.hpp
    src/UI/ConcretePanels.cpp
    src/Repo/Entrance.hpp
    src/Repo/Entrance.cpp
    src/Repo/Room.hpp
    src/Repo/Room.cpp
    src/Repo/House.hpp
    src/Repo/House.cpp
    src/main.cpp)

target_compile_features(Client PRIVATE cxx_std_20)