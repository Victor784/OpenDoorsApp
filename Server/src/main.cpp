#include "../src/Server/Server.hpp"
#include "../src/Connection/WSConnection.hpp"
#include "../src/Logger/Logger.hpp"




#include <chrono>
#include <memory>
#include <thread>
#include <vcruntime_typeinfo.h>
#include <vector>
 

int main()
{   
    WSConnection conn;
    Server server(conn);
    server.run();
    return 0;
}

