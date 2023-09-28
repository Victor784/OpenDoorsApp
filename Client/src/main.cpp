#include"../src/Connection/Connection.hpp"
#include "../src/Client/Client.hpp"
#include "../src/Connection/WSConnection.hpp"
#include "../src/Logger/Logger.hpp"




#include <chrono>
#include <memory>
#include <thread>
#include <vcruntime_typeinfo.h>
#include <vector>
 

int main()
{   

    //Pipe p1("../../../test.txt" , "");
    connection::WSConnection conn;
    House house;

    connection::Client client(conn, house);

    client.run();
    return 0;

}

