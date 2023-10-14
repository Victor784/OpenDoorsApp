#include "Server.hpp"
#include <sstream>
#include <string>
#include <vector>

enum stringHash
{
    switchStatus,
    addEntrance,
    deleteEntrance,
    changeEntrance,
    addRoom,
    changeRoom,
    deleteRoom,

};

void Server::run()
{
    connection.createSocket();
    connection.bindSocket();
    connection.listenOnSocket();
    while(true)
    {
        std::string message = connection.acceptNewClientSocketAndRecieve();
        process(message);
        //result from process will be a bool, send OK to client if return = true and NOT OK else
    }
}

void Server::process(std::string message)
{
    std::string trimmedMessage = trim(message);
    if(trimmedMessage.size() != 0)
    {
        std::vector<std::string> command = decodeMessage(trimmedMessage);
        bool responseFromServer = executeCommand(command);
        std::cout << "Decoded message: \n";
        for(std::string token : command)
        {
            std::cout << token << '\n';
        } 
    }
    
}

std::string Server::trim(std::string message)
{
    std::string trimmedMessage;
    for(int i = 0; i < message.length(); i++)
    {
        if(     message[i] != 'a' &&  message[i] != 'b' &&  message[i] != 'c' &&  message[i] != 'd' &&  message[i] != 'e' &&  message[i] != 'f' &&  message[i] != 'g' &&  message[i] != 'h' &&  message[i] != 'i' &&  message[i] != 'j' &&  message[i] != 'k'
            &&  message[i] != 'l' &&  message[i] != 'm' &&  message[i] != 'n' &&  message[i] != 'o' &&  message[i] != 'p' &&  message[i] != 'q' &&  message[i] != 'r' &&  message[i] != 's' &&  message[i] != 't' &&  message[i] != 'u' &&  message[i] != 'v'
            &&  message[i] != 'w' &&  message[i] != 'x' &&  message[i] != 'y' &&  message[i] != 'z' &&  message[i] != ',' &&  message[i] != '-' &&  message[i] != '1' &&  message[i] != '2' &&  message[i] != '3' &&  message[i] != '4' &&  message[i] != '5'
            &&  message[i] != '6' &&  message[i] != '7' &&  message[i] != '8' &&  message[i] != '9' &&  message[i] != '0' &&  message[i] != ':' &&  message[i] != ';' &&  message[i] != 'A' &&  message[i] != 'B' &&  message[i] != 'C' &&  message[i] != 'D' 
            &&  message[i] != 'E' &&  message[i] != 'F' &&  message[i] != 'G' &&  message[i] != 'H' &&  message[i] != 'I' &&  message[i] != 'J' &&  message[i] != 'K' &&  message[i] != 'L' &&  message[i] != 'M' &&  message[i] != 'N' &&  message[i] != 'O' 
            &&  message[i] != 'P' &&  message[i] != 'Q' &&  message[i] != 'R' &&  message[i] != 'S' &&  message[i] != 'T' &&  message[i] != 'U' &&  message[i] != 'V' &&  message[i] != 'W' &&  message[i] != 'X' &&  message[i] != 'Y' &&  message[i] != 'Z')
            {
            }
        else 
        {
            trimmedMessage.push_back(message[i]);
        }
    }
    return trimmedMessage;
}

std::vector<std::string> Server::decodeMessage(std::string message)
{
    std::string token;
    std::vector<std::string> decodedMessage;
    std::stringstream ss(message);
    while (getline(ss, token, ',')) {
        decodedMessage.push_back(token);
    }
    return decodedMessage;
}

bool Server::executeCommand(std::vector<std::string> command)
{
    //std::string switch_status= "switch-status";
    //switch(command[0])
    //{
     //   case switch_status:

    //}
    return false;

}
