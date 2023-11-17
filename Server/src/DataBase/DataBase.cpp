#include "DataBase.hpp"
#include <string>

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
            int ret = createTables();;
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
        //std::cout << "closed the db connection succsefully\n";
        //sqlite3_close(db);  TODO this destructor calls close DB too soon, investigate this
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
            std::cout << "error at addressTableCreation \n";
        }

        const char* createRoomsTableSQL = "CREATE TABLE IF NOT EXISTS RoomsTable ("
            "ID INTEGER PRIMARY KEY ,"
            "name TEXT,"
            "floor INTEGER"
            ");";

        int result2 = sqlite3_exec(db, createRoomsTableSQL, 0, 0, 0);
        if (result2 != SQLITE_OK) {
            std::cout << "error at roomsTableCreation \n";
            return SQLITE_ERROR;
        }

        const char* createEntrancesTableSQL = "CREATE TABLE IF NOT EXISTS EntrancesTable (ID INTEGER PRIMARY KEY,roomId INTEGER,type INTEGER,position INTEGER,status INTEGER,CONSTRAINT RoomsTable FOREIGN KEY(roomId) REFERENCES RoomsTable(ID));";
        int result3 = sqlite3_exec(db, createEntrancesTableSQL, 0, 0, 0);
        if (result3 != SQLITE_OK) {
           std::cout << "error at entranceTableCreation \n";
           std::cout << result3 << '\n';
           std::cout << sqlite3_errmsg(db)<< '\n';
            return SQLITE_ERROR;
            
        }
        return SQLITE_OK; 
    }


        void DataBase::switchStateForEntrance(unsigned int id){}
        int DataBase::addEntrance(int roomId, int type, int position)
        {
            sqlite3_stmt* stmt;
            const char* messageError;
            std::string sql ("INSERT INTO EntrancesTable (roomId,type,position,status) VALUES ("
            + std::to_string(roomId)   + ","
            + std::to_string(type)     + ","
            + std::to_string(position) + ","
            +           "0"                 + ");" // default state of Entrances is closed which coresponds to 0
           );
            sqlite3_prepare_v2( db, sql.c_str(), -1, &stmt,  &messageError );//preparing the statement
            int result3 = sqlite3_step( stmt );
        
            std::cout << "[DEBUG] : query for add entrance : " << sql << '\n';
            if (result3 != SQLITE_OK && result3!= SQLITE_DONE)  
            {
                std::cout << "error at add entrance , error : " << result3 << '\n'; 
                std::cout <<'|'<< messageError <<'|'<< '\n';  
                return SQLITE_ERROR;
            }
            sqlite3_stmt* stmtForRooms;
            std::string sqlForRoom{"UPDATE RoomsTable SET NrOfEntrances = NrOfEntrances + 1 WHERE id = "
            + std::to_string(roomId) + ";"};
            sqlite3_prepare_v2( db, sql.c_str(), -1, &stmt,  &messageError );//preparing the statement
            result3 = sqlite3_step( stmt );
            if (result3 != SQLITE_OK && result3!= SQLITE_DONE)  
            {
                std::cout << "error at increaseNrOfEntrances , error : " << result3 << '\n'; 
                std::cout <<'|'<< messageError <<'|'<< '\n';  
                return SQLITE_ERROR;
            }
            return SQLITE_OK;
        }
        int DataBase::deleteEntrance(int entranceId)
        {   
            //TODO : You need to get the roomId from the row that you need to delete so you can decrease the NROfEntrances 
            sqlite3_stmt* stmt;
            const char* messageError;
            std::string sql {"DELETE FROM EntrancesTable WHERE ID = " + std::to_string(entranceId) + ";"};
            sqlite3_prepare_v2( db, sql.c_str(), -1, &stmt,  &messageError );//preparing the statement
            int result3 = sqlite3_step( stmt );
        
            std::cout << "[DEBUG] : query for delete entrance : " << sql << '\n';
            if (result3 != SQLITE_OK && result3!= SQLITE_DONE) 
            {
                std::cout << "error at delete entrance , error : " << result3 << '\n'; 
                std::cout <<'|'<< messageError <<'|'<< '\n';  
                return SQLITE_ERROR;
                
            }
            return SQLITE_OK;
        }
        int DataBase::changeEntrance(int entranceId, int newType, int newPosition)
        {
            sqlite3_stmt* stmt;
            const char* messageError;
            std::string sql {"UPDATE EntrancesTable SET type = " + 
            std::to_string(newType) + ", position = " + std::to_string(newPosition) +
            ", status = 0 WHERE ID = " + std::to_string(entranceId) +  ";"};
            sqlite3_prepare_v2( db, sql.c_str(), -1, &stmt,  &messageError );//preparing the statement
            int result3 = sqlite3_step( stmt );
        
            std::cout << "[DEBUG] : query for change entrance : " << sql << '\n';
            if (result3 != SQLITE_OK && result3!= SQLITE_DONE)  
            {
                std::cout << "error at change entrance , error : " << result3 << '\n'; 
                std::cout <<'|'<< messageError <<'|'<< '\n';  
                return SQLITE_ERROR;
                
            }
            return SQLITE_OK;
        }
        int DataBase::addRoom(int id,std::string name, int level)
        {
            sqlite3_stmt* stmt;
            const char* messageError;
            std::string sql ("INSERT INTO RoomsTable (id,name,floor) VALUES ("
            + std::to_string(id)   + ","
            + "\'" + name  + "\'" + ","
            + std::to_string(level)
            + ");" 
           );
            sqlite3_prepare_v2( db, sql.c_str(), -1, &stmt,  &messageError );//preparing the statement
            int result3 = sqlite3_step( stmt );
        
            std::cout << "[DEBUG] : query for add room : " << sql << '\n';
            if (result3 != SQLITE_OK && result3!= SQLITE_DONE)  
            {
                std::cout << "error at add room , error : " << result3 << '\n'; 
                std::cout <<'|'<< messageError <<'|'<< '\n';  
                return SQLITE_ERROR;
                
            }
            return SQLITE_OK;
        }
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