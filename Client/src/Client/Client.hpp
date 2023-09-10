#pragma once

#include "../Connection/Iconnection.hpp"
#include "../UI/Ui.hpp"
#include "../Repo/House.hpp"
#include<iostream>

class Client{
    private:
        IConnection& connection;
        UI ui;
        House house;
    public:
        //  Client(IConnection& conn, UI& userInterface, House houseVal) 
        //  : connection(conn) , ui(userInterface), house(houseVal) {}
        
        Client(IConnection& conn , House houseVal) 
        : connection(conn) ,house(houseVal) {}
        IConnection& getConnection() { return connection;}
        // Ui& getUi() {return ui;}
        House& getHouse(){
            return  house;}
        void run();
         ~Client() = default;
        

};