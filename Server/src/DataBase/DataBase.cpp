#include "DataBase.hpp"

DataBase::DataBase()
{
        char *zErrMsg = 0;
        int rc;

        rc = sqlite3_open("test.db", &db);
        if( rc ) {
            fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
            db = NULL;
        } else 
        {
            fprintf(stderr, "Opened database successfully\n");
            int ret = createTables();
            if(ret != SQLITE_OK)
            {
                fprintf(stderr, "Some issues while creating the DB tables\n");
            }
        }

        
}   

DataBase::~DataBase()
{
     if(db != NULL)
     {
        std::cout << "closed the db connection succsefully\n";
        sqlite3_close(db);
     }
     else {
        std::cout << "db could not be closed as the creation step had some error\n";
     }
     
}

 int DataBase::createTables() {
     const char* createAddressTableSQL = "CREATE TABLE IF NOT EXISTS AddressTable ("
            "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
            "country TEXT,"
            "city TEXT,"
            "street TEXT,"
            "nr INTEGER,"
            "subNr INTEGER,"
            "floor INTEGER"
            ");";

        int result1 = sqlite3_exec(db, createAddressTableSQL, 0, 0, 0);
        if (result1 != SQLITE_OK) {
            return SQLITE_ERROR;
            std::cout << "error at address \n";
        }
        const char* createEntrancesTableSQL = "CREATE TABLE IF NOT EXISTS EntrancesTable ("
            "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
            "roomId INTEGER,"
            "type INTEGER,"
            "position INTEGER,"
            "status INTEGER,"
            "subNr INTEGER,"
            "floor INTEGER"
            ");";

        int result3 = sqlite3_exec(db, createEntrancesTableSQL, 0, 0, 0);
        if (result3 != SQLITE_OK) {
            return SQLITE_ERROR;
            std::cout << "error at entrance \n";
        }

        const char* createRoomsTableSQL = "CREATE TABLE IF NOT EXISTS RoomsTable ("
            "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
            "name TEXT,"
            "floor INTEGER,"
            "nrOfEntrances INTEGER"
            ");";

        int result2 = sqlite3_exec(db, createRoomsTableSQL, 0, 0, 0);
        if (result2 != SQLITE_OK) {
            std::cout << "error at rooms \n";
            return SQLITE_ERROR;
        }
         
        return SQLITE_OK; 
    }


        void DataBase::switchStateForEntrance(unsigned int id){}
        int DataBase::addEntrance(int roomId, int type, int position){return {};}
        void DataBase::deleteEntrance(int entranceId){}
        void DataBase::changeEntrance(int entranceId, int newType, int newPosition){}
        void DataBase::addRoom(int id,std::string name, int level){}
        void DataBase::changeRoom(int roomId, std::string newName, int newLevel){}
        void DataBase::deleteRoom(int roomId){}
        void DataBase::changeAddressCountry(std::string newCountryName){}
        void DataBase::changeAddressCity(std::string newCityName){}
        void DataBase::changeAddressStreet(std::string newStreetName){}
        void DataBase::changeAddressNr(int newNr){}

        std::string DataBase::getAddress(){return {};}
        int DataBase::getNrOfRooms(){return {};}
        std::string DataBase::getRoomAtRow(int row){return {};}
        int DataBase::getNrOfEntrances(){return {};}
        std::string DataBase::getEntranceAtRow(int row){return {};}