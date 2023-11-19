#pragma once

#include <string>

namespace connection
{
class IConnection{
    public:
        virtual void connect_() = 0;
        virtual void disconnect_() = 0;
        virtual std::string read_() = 0;
        virtual void write_(const std::string &message) = 0;
}; 
}