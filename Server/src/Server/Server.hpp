#pragma once

#include <iostream>
#include <vector>
#include "../Connection/IConnection.hpp"
#include "../../utils/utils.hpp"
#include "../../lib/sqlite3/sqlite3.h"


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
        std::vector<std::string> decodeMessage(std::string message);
        bool executeCommand(std::vector<std::string> command);
        void createDataBase();
        std::string getValFromCommand(std::string partOfCommand);
        //DB elem control
        void switchStateForEntrance(unsigned int id);
        void addEntrance(int roomId, EntranceType type, Position position);
        void deleteEntrance(int entranceId);
        void changeEntrance(int entranceId, EntranceType newType, Position newPosition);
        void addRoom(int id,std::string name, int level);
        void changeRoom(int roomId, std::string newName, int newLevel);
        void deleteRoom(int roomId);
        void changeAddressCountry(std::string newCountryName);
        void changeAddressCity(std::string newCityName);
        void changeAddressStreet(std::string newStreetName);
        void changeAddressNr(int newNr);
        ~Server() = default;
};
