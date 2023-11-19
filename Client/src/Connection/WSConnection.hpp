#pragma once

#include<iostream>
#include<string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "IConnection.hpp"

namespace connection
{
class WSConnection : public IConnection{
    private:
        SOCKET clientScoket;
    public:
        WSConnection();

        ~WSConnection() = default;

        void connect_() override;
        void disconnect_() override ;
        std::string read_() override;
        void write_(const std::string &message) override;
        
    
};
}