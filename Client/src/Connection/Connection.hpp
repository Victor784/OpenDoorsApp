#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include "IConnection.hpp"

struct Pipe{
    
        Pipe() = default;
        Pipe(std::string initOutgoingPipe, std::string initIncomingPipe) :
        outgoingPipe(initOutgoingPipe), incomingPipe(initIncomingPipe){}
        
        
        Pipe(const Pipe& other)
        {
            outgoingPipe=other.outgoingPipe;
            incomingPipe=other.incomingPipe;
        }

        Pipe& operator=(const Pipe& other)
        {
            outgoingPipe = other.outgoingPipe;
            incomingPipe = other.incomingPipe;
            return *this;
        }
        ~Pipe() = default;

        std::string getOutgoingPipe()
        {
            return outgoingPipe;
        }

        std::string getIncomingPipe()
        {
            return incomingPipe;
        }
    private:
    std::string outgoingPipe;
    std::string incomingPipe;
};

class Connection : public IConnection{
    private:
        Pipe pipeName;
    public:
        Connection(Pipe p) :
        pipeName(p){}

        Connection() = default;
        ~Connection() = default;

        void connect() override;
        void disconnect() override ;
        std::string read() override;
        void write(std::string message) override;
        
    
};