#include "Server.hpp"

void Server::run()
{
    connection.createSocket();
    connection.bindSocket();
    connection.listenOnSocket();
    while(true)
    {
        std::string message = connection.acceptNewClientSocketAndRecieve();
        process(message);
    }
}

void Server::process(std::string message)
{
    std::string trimmedMessage = trim(message);
    std::cout <<"message from client: |"<< trimmedMessage<<'|';
}

std::string Server::trim(std::string message)
{
    std::string trimmedMessage;
    for(int i = 0; i < message.length(); i++)
    {
        if(     message[i] != 'a' &&  message[i] != 'b' &&  message[i] != 'c' &&  message[i] != 'd' &&  message[i] != 'e' &&  message[i] != 'f' &&  message[i] != 'g' &&  message[i] != 'h' &&  message[i] != 'i' &&  message[i] != 'j' &&  message[i] != 'k'
            &&  message[i] != 'l' &&  message[i] != 'm' &&  message[i] != 'n' &&  message[i] != 'o' &&  message[i] != 'p' &&  message[i] != 'q' &&  message[i] != 'r' &&  message[i] != 's' &&  message[i] != 't' &&  message[i] != 'u' &&  message[i] != 'v'
            &&  message[i] != 'w' &&  message[i] != 'x' &&  message[i] != 'y' &&  message[i] != 'z' &&  message[i] != ',' &&  message[i] != '-' &&  message[i] != '1' &&  message[i] != '2' &&  message[i] != '3' &&  message[i] != '4' &&  message[i] != '5'
            &&  message[i] != '6' &&  message[i] != '7' &&  message[i] != '8' &&  message[i] != '9' &&  message[i] != '0' &&  message[i] != ':' &&  message[i] != ';' &&  message[i] != '{' &&  message[i] != '}')
            {
            }
        else 
        {
            trimmedMessage.push_back(message[i]);
        }
    }
    return trimmedMessage;
}
