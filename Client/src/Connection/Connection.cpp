#include "Connection.hpp"

void Connection::write(std::string message)
        {
            std::cout << "connection : " << message << '\n'; 
            std::ofstream outPipe(pipeName.getOutgoingPipe());
            outPipe << message;
            outPipe.close();
        }
std::string Connection::read()
        {
            std::string messageFromServer;
            std::ifstream inPipe(pipeName.getIncomingPipe());

            if(inPipe.is_open()) 
            {
                while(std::getline(inPipe, messageFromServer)) 
                {
                    inPipe >> messageFromServer;
                }
            }
        return messageFromServer;
        }
void Connection::connect() {
    // nothing to do at the moment
} 

void Connection::disconnect(){
    // nothing to do at the moment
}