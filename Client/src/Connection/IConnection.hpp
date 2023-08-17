#pragma once

#include <string>
class IConnection{
    public:
        virtual void connect() = 0;
        virtual void disconnect() = 0;
        virtual std::string read() = 0;
        virtual void write(std::string message) = 0;
};