#pragma once

#include "../Connection/Iconnection.hpp"
#include "../UI/Ui.hpp"
#include<iostream>

class Client{
    private:
        IConnection& connection;
        Ui& ui;
    public:
        Client(IConnection& conn, Ui& userInterface) 
        : connection(conn) , ui(userInterface) {}

        IConnection& getConnection() { return connection;}
        Ui& getUi() {return ui;}
        
         ~Client() = default;
        

};