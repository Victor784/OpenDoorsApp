#include "Connection.hpp"

namespace connection
{
void Connection::write_(const std::string &message)
        {
            std::cout << "connection : " << message << '\n'; 
            std::ofstream outPipe(pipeName.getOutgoingPipe());
            outPipe << message;
            outPipe.close();
        }
std::string Connection::read_()
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
void Connection::connect_() {
    // nothing to do at the moment
} 

void Connection::disconnect_(){
    // nothing to do at the moment
}
}