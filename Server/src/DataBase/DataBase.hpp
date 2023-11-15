#include "../../lib/sqlite3/sqlite3.h"
#include <stdio.h>
#include <iostream>
#pragma once

class DataBase 
{
    private:
        sqlite3 *db;

    public:
        DataBase();
        ~DataBase();
    private:
        int createTables();
        
    public:
        //Server operations
        void switchStateForEntrance(unsigned int id);
        int addEntrance(int entranceId, int type, int position);
        int deleteEntrance(int entranceId);
        int changeEntrance(int entranceId, int newType, int newPosition);
        int addRoom(int id,std::string name, int level);
        void changeRoom(int roomId, std::string newName, int newLevel);
        void deleteRoom(int roomId);
        void changeAddressCountry(std::string newCountryName);
        void changeAddressCity(std::string newCityName);
        void changeAddressStreet(std::string newStreetName);
        void changeAddressNr(int newNr);

        //Client needed operations (getting the data from the DB to the Client at startup)

        std::string getAddress();
        //-------
        int getNrOfRooms();
        std::string getRoomAtRow(int row);
        //-------
        int getNrOfEntrances();
        std::string getEntranceAtRow(int row);

};
