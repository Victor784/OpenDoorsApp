#pragma once

#include "../Connection/Iconnection.hpp"
#include "../UI/Ui.hpp"
#include "../Repo/House.hpp"
#include<iostream>

namespace connection
{

class Client{
    private:
        IConnection& connection;
        UI ui;
        House house;
    public:
        Client(IConnection& conn , House houseVal) 
        : connection(conn) ,house(houseVal) {}
        IConnection& getConnection() { return connection;}
        House& getHouse(){
            return  house;}
        void run();
        void sendCmd(std::string cmd)
        {
        // std::cout << "From sendCmd of Client : " << cmd << '\n';
        connection.connect_();
        connection.write_(cmd);
        connection.disconnect_();
        }
        // Client should have a func that uses the connection to receive all house data from server on start up
         ~Client() = default;
        

};
}