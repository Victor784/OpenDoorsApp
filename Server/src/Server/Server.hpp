#pragma once

#include <iostream>
#include "../Connection/IConnection.hpp"
#include "../Connection/WSConnection.hpp"


enum class EntranceType
{
    Window,
    RabatableWindow,
    Door,
    RabatableDoor
};

enum class Position
{
    East,
    West,
    South,
    North
};

class Server{
    private:
        IConnection& connection;
    public:
        Server(IConnection& conn) 
        : connection(conn){}
        IConnection& getConnection() { return connection;}
        void run();
        void process (std::string message);
        std::string trim(std::string message);
        void createDataBase();
        void executeCommand(std::string message);

        //DB elem control
        void switchStateForEntrance(int id);
        void addEntrance(int roomId, EntranceType type, Position position);
        void deleteEntrance(int entranceId);
        void changeEntrance(int entranceId, EntranceType newType, Position newPosition);
        void addRoom(std::string name, int level);
        void changeRoom(int roomId, std::string newName, int newLevel);
        void deleteRoom(int roomId);
        void changeAddressCountry(std::string newCountryName);
        void changeAddressCity(std::string newCityName);
        void changeAddressStreet(std::string newStreetName);
        void changeAddressNr(int newNr);
        ~Server() = default;
};
