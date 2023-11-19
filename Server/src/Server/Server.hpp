#pragma once

#include <iostream>
#include <vector>
#include "../Connection/IConnection.hpp"
#include "../../utils/utils.hpp"
#include "../DataBase/DataBase.hpp"

class Server{
    private:
        IConnection& connection;
        DataBase database;
        std::string reply = "";
    public:
        Server(IConnection& conn) 
        : connection(conn){ /*DataBase db;  database = db;*/}
        IConnection& getConnection() { return connection;}
        void run();
        void process (const std::string &message);
        std::string trim(const std::string &message);
        std::vector<std::string> decodeMessage(const std::string &message);
        bool executeCommand(const std::vector<std::string> &command);
        void createDataBase();
        std::string getValFromCommand(const std::string &partOfCommand);
        //DB elem control
        void switchStateForEntrance(unsigned int id);
        void addEntrance(int roomId, const EntranceType &type, const Position &position);
        void deleteEntrance(int entranceId);
        void changeEntrance(int entranceId, const EntranceType &newType, const Position &newPosition);
        void addRoom(int id,const std::string &name, int level);
        void changeRoom(int roomId, const std::string &newName, int newLevel);
        void deleteRoom(int roomId);
        void changeAddressCountry(const std::string &newCountryName);
        void changeAddressCity(const std::string &newCityName);
        void changeAddressStreet(const std::string &newStreetName);
        void changeAddressNr(int newNr);
        //Methods needed to populate the client repo at client start up
        void getAddress();
        //-------
        void getNrOfRooms();
        void getRoomAtRow(int id);
        //-------
        void getNrOfEntrances();
        void getEntranceAtRow(int id);

        void debugServer();

        ~Server() = default;
};
