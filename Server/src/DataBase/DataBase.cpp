#include "DataBase.hpp"
#include <iterator>
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
            "nr INTEGER"
            ");";
        
        int result1 = sqlite3_exec(db, createAddressTableSQL, 0, 0, 0);
        if (result1 != SQLITE_OK) {
            std::cout << "error at addressTableCreation \n";
            return SQLITE_ERROR;
        }

        const char* insertAddressRow = "INSERT INTO AddressTable (ID, country, city, street, nr) VALUES (1,'NOT SET','NOT SET','NOT SET',0);";
        int res = sqlite3_exec(db, insertAddressRow, 0, 0, 0);
        //THIS statement will fail when the server starts 2nd time or any time after that, as inserting the same values (the same id) twice is not allowed as it is a primary key
        // if (res != SQLITE_OK) {
        //     std::cout << "error at Insertion of row in addressTableCreation \n";
        //     return SQLITE_ERROR;
        // }
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
            //This is no longer needed as rooms no longer hold the nr of Entrances they have
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
        int DataBase::addRoom(int id,const std::string &name, int level)
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
        int DataBase::changeRoom(int roomId, const std::string &newName, int newLevel)
        {
            sqlite3_stmt* stmt;
            const char* messageError;
            std::string sql {"UPDATE RoomsTable SET name = \'"
            + newName + "\'"+ ", floor = " + std::to_string(newLevel) +
            " WHERE ID = " + std::to_string(roomId) +  ";"};
            sqlite3_prepare_v2( db, sql.c_str(), -1, &stmt,  &messageError );//preparing the statement
            int result3 = sqlite3_step( stmt );
        
            std::cout << "[DEBUG] : query for change room : " << sql << '\n';
            if (result3 != SQLITE_OK && result3!= SQLITE_DONE)  
            {
                std::cout << "error at change room , error : " << result3 << '\n'; 
                std::cout <<'|'<< messageError <<'|'<< '\n';  
                return SQLITE_ERROR;
                
            }
            return SQLITE_OK;
        }
        int DataBase::deleteRoom(int roomId)
        {
            sqlite3_stmt* stmt;
            const char* messageError;
            std::string sql {"DELETE FROM RoomsTable WHERE ID = " + std::to_string(roomId) + ";"};
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
        int DataBase::changeAddressCountry(const std::string &newCountryName)
        {
            sqlite3_stmt* stmt;
            const char* messageError;
            std::string sql {"UPDATE AddressTable SET country = \'" + 
            newCountryName  + "\'" + "WHERE ID = 1;"};
            sqlite3_prepare_v2( db, sql.c_str(), -1, &stmt,  &messageError );//preparing the statement
            int result3 = sqlite3_step( stmt );
        
            std::cout << "[DEBUG] : query for change address country : " << sql << '\n';
            if (result3 != SQLITE_OK && result3!= SQLITE_DONE)  
            {
                std::cout << "error at change address country , error : " << result3 << '\n'; 
                std::cout <<'|'<< messageError <<'|'<< '\n';  
                return SQLITE_ERROR;
                
            }
            return SQLITE_OK;
        }
        int DataBase::changeAddressCity(const std::string &newCityName)
        {
            sqlite3_stmt* stmt;
            const char* messageError;
            std::string sql {"UPDATE AddressTable SET city = \'" + 
            newCityName  + "\'" + "WHERE ID = 1;"};
            sqlite3_prepare_v2( db, sql.c_str(), -1, &stmt,  &messageError );//preparing the statement
            int result3 = sqlite3_step( stmt );
        
            std::cout << "[DEBUG] : query for change address country : " << sql << '\n';
            if (result3 != SQLITE_OK && result3!= SQLITE_DONE)  
            {
                std::cout << "error at change address country , error : " << result3 << '\n'; 
                std::cout <<'|'<< messageError <<'|'<< '\n';  
                return SQLITE_ERROR;
                
            }
            return SQLITE_OK;
        }
        int DataBase::changeAddressStreet(const std::string &newStreetName)
        {
            sqlite3_stmt* stmt;
            const char* messageError;
            std::string sql {"UPDATE AddressTable SET street = \'" + 
            newStreetName  + "\'" + "WHERE ID = 1;"};
            sqlite3_prepare_v2( db, sql.c_str(), -1, &stmt,  &messageError );//preparing the statement
            int result3 = sqlite3_step( stmt );
        
            std::cout << "[DEBUG] : query for change street country : " << sql << '\n';
            if (result3 != SQLITE_OK && result3!= SQLITE_DONE)  
            {
                std::cout << "error at change address street , error : " << result3 << '\n'; 
                std::cout <<'|'<< messageError <<'|'<< '\n';  
                return SQLITE_ERROR;
                
            }
            return SQLITE_OK;
        }
        int DataBase::changeAddressNr(int newNr)
        {
            sqlite3_stmt* stmt;
            const char* messageError;
            std::string sql {"UPDATE AddressTable SET nr = \'" + 
            std::to_string(newNr)  + "\'" + "WHERE ID = 1;"};
            sqlite3_prepare_v2( db, sql.c_str(), -1, &stmt,  &messageError );//preparing the statement
            int result3 = sqlite3_step( stmt );
        
            std::cout << "[DEBUG] : query for change address nr : " << sql << '\n';
            if (result3 != SQLITE_OK && result3!= SQLITE_DONE)  
            {
                std::cout << "error at change address nr , error : " << result3 << '\n'; 
                std::cout <<'|'<< messageError <<'|'<< '\n';  
                return SQLITE_ERROR;
                
            }
            return SQLITE_OK;
        }

        
        int DataBase::getNrOfRooms()
        {
            int rc;
            sqlite3_stmt* stmt;
            const char* query = "SELECT COUNT(1) FROM RoomsTable;";
            rc = sqlite3_prepare_v2(db, query, -1, &stmt, nullptr);

            if (rc != SQLITE_OK) {
                std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
                sqlite3_close(db);
                return SQLITE_ERROR;
            }

            // Execute the query
            rc = sqlite3_step(stmt);

            if (rc == SQLITE_ROW) {
                // Get the count value as a 64-bit integer
                int count = static_cast<int>(sqlite3_column_int64(stmt, 0));
                // Use the count value as needed
                return count;
            } else {
                std::cerr << "Error executing query: " << sqlite3_errmsg(db) << std::endl;
                return SQLITE_ERROR;
            }
        }
        
        int DataBase::getNrOfEntrances()
        {
            int rc;
            sqlite3_stmt* stmt;
            const char* query = "SELECT COUNT(1) FROM EntrancesTable;";
            rc = sqlite3_prepare_v2(db, query, -1, &stmt, nullptr);

            if (rc != SQLITE_OK) {
                std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
                sqlite3_close(db);
                return SQLITE_ERROR;
            }

            // Execute the query
            rc = sqlite3_step(stmt);

            if (rc == SQLITE_ROW) {
                // Get the count value as a 64-bit integer
                int count = static_cast<int>(sqlite3_column_int64(stmt, 0));
                // Use the count value as needed
                return count;
            } else {
                std::cerr << "Error executing query: " << sqlite3_errmsg(db) << std::endl;
                return SQLITE_ERROR;
            }
        }
        std::string DataBase::getAddress()
        {
            return getDataFromRow("AddressTable", 1);
        }
        std::string DataBase::getEntranceAtRow(int row)
        {
            return getDataFromRow("EntrancesTable", row);
        }
        std::string DataBase::getRoomAtRow(int row)
        {
            return getDataFromRow("RoomsTable", row);
        }
        
        std::string DataBase::getDataFromRow(const std::string& tableName, int rowID) {
            int rc;
            // Construct the SELECT query with a WHERE clause
            std::string query = "SELECT * FROM " + tableName + " WHERE ID = " + std::to_string(rowID) + ";";

            sqlite3_stmt* stmt;
            rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);

            if (rc != SQLITE_OK) {
                std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
                sqlite3_close(db);
                return "";
            }

            // Execute the query
            rc = sqlite3_step(stmt);

            if (rc == SQLITE_ROW) {
                // Get data from the columns in the result set
                std::string result;

                for (int i = 0; i < sqlite3_column_count(stmt); ++i) {
                    const char* columnName = sqlite3_column_name(stmt, i);
                    const char* value = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));

                    result += columnName + std::string(": ") + (value ? value : "NULL") + "\n";
                }

                sqlite3_finalize(stmt);
                sqlite3_close(db);

                return result;
            } else {
                std::cerr << "Error executing query: " << sqlite3_errmsg(db) << std::endl;
                sqlite3_finalize(stmt);
                sqlite3_close(db);
                return "";
            }
}