#pragma once

#include<iostream>
#include<string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "IConnection.hpp"

class WSConnection : public IConnection{
    private:
        SOCKET serverSocket;
    public:
        WSConnection();
        ~WSConnection() = default;
        void createSocket() override;
        void bindSocket() override;
        void listenOnSocket() override;
        std::string acceptNewClientSocketAndRecieve() override;
        // void sendResponse(std::string reply);
};
