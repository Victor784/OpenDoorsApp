#include "../src/Server/Server.hpp"
#include "../src/Connection/WSConnection.hpp"
#include "../src/Logger/Logger.hpp"



#include <chrono>
#include <memory>
#include <thread>
#include <vcruntime_typeinfo.h>
#include <vector>
 
#include <sqlite3.h> // this works no fixes needed

int main()
{   
    WSConnection conn;
    //DataBase db;
    Server server(conn);
    server.run();
    return 0;
}

