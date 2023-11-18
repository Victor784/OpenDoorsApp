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
        int changeRoom(int roomId, std::string newName, int newLevel);
        int deleteRoom(int roomId);
        int changeAddressCountry(std::string newCountryName);
        int  changeAddressCity(std::string newCityName);
        int changeAddressStreet(std::string newStreetName);
        int changeAddressNr(int newNr);

        //Client needed operations (getting the data from the DB to the Client at startup)

        std::string getAddress();
        //-------
        int getNrOfRooms();
        std::string getRoomAtRow(int row);
        //-------
        int getNrOfEntrances();
        std::string getEntranceAtRow(int row);

        private:
            std::string getDataFromRow(const std::string& tableName, int rowID);

};
