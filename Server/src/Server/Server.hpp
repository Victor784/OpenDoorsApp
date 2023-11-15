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
        : connection(conn){ DataBase db;  database = db;}
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
        //Methods needed to populate the client repo at client start up
        void getAddress();
        //-------
        void getNrOfRooms();
        void getRoomAtRow(int row);
        //-------
        void getNrOfEntrances();
        void getEntranceAtRow(int row);


        ~Server() = default;
};
