#pragma once

#include <string>

class IConnection{
    public:
        virtual void createSocket() = 0;
        virtual void bindSocket() = 0;
        virtual void listenOnSocket() = 0;
        virtual std::string acceptNewClientSocketAndRecieve() = 0;
}; 
