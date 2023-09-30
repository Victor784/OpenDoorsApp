#pragma once

#include <iostream>
#include "../Connection/IConnection.hpp"
#include "../Connection/WSConnection.hpp"

class Server{
    private:
        IConnection& connection;
    public:
        Server(IConnection& conn) 
        : connection(conn){}
        IConnection& getConnection() { return connection;}
        void run();
        void process (std::string message);
        std::string trim(std::string message);
        ~Server() = default;
};
