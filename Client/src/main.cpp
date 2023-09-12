#include"../src/Connection/Connection.hpp"
#include "../src/Client/Client.hpp"

#include <chrono>
#include <memory>
#include <thread>
#include <vcruntime_typeinfo.h>
#include <vector>

int main()
{   
    Pipe p1("../../../test.txt" , "");
    Connection conn(p1);
    House house;

    Client client (conn, house);

    client.run();
    return 0;

}
