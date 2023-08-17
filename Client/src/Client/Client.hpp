#pragma once

#include "../Connection/Iconnection.hpp"
#include<iostream>

class Client{
    public:
        IConnection& connection;
    public:
        Client(IConnection& conn) : connection(conn) {}
        
        //  Client(Connection conn){
        //     connection = std::make_shared<Connection>(conn);
        //  }
         ~Client() = default;
        

};