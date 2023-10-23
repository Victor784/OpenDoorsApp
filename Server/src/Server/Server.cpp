#include "Server.hpp"
#include <sstream>
#include <string>
#include <vcruntime.h>
#include <vector>
#include "../../utils/utils.hpp"



void Server::run()
{
    connection.createSocket();
    connection.bindSocket();
    connection.listenOnSocket();
    while(true)
    {
        std::string message = connection.acceptNewClientSocketAndRecieve();
        std::cout << "[DEBUG] From Server::run() : " << message << '\n';
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
            &&  message[i] != 'P' &&  message[i] != 'Q' &&  message[i] != 'R' &&  message[i] != 'S' &&  message[i] != 'T' &&  message[i] != 'U' &&  message[i] != 'V' &&  message[i] != 'W' &&  message[i] != 'X' &&  message[i] != 'Y' &&  message[i] != 'Z'
           )
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
    std::cout << "[DEBUG] executeCommand()\n"; 
    switch(convertStringToCommand(command[0]))
    {
        std::cout << "[DEBUG] convertStringToCommand()\n"; 
        case switchStatusEnum:
        {
            switchStateForEntrance(std::stoul(command[1])); // TODO: implicit convertion from unsigned long to unsigned int data loss risk, does it matter?
            break;
        }
        case addEntranceEnum:
        {
            addEntrance(std::stoi(command[1]), convertStringToEntranceType(command[2]), convertStringToPosition(command[3]));
            break;
        }
        case deleteEntranceEnum:
        {
            deleteEntrance(std::stoi(command[1]));
            break;
        }
        case changeEntranceEnum:
        {
            changeEntrance(std::stoi(command[1]), convertStringToEntranceType(command[2]), convertStringToPosition(command[3]));
            break;
        }
        case addRoomEnum:
        {
            addRoom(std::stoi(command[1]),command[2], std::stoi(command[3]));
            break;
        }
        case deleteRoomEnum:
        {
            deleteRoom(std::stoi(command[1]));
            break;
        }
        case changeRoomEnum:
        {
            changeRoom(std::stoi(command[0]), command[1], std::stoi(command[2]));
            break;
        }
        case changeCountryEnum:
        {
            changeAddressCountry(command[1]);
            break;
        }
        case changeCityEnum:
        {
            changeAddressCity(command[1]);
            break;
        }
        case changeStreetEnum:
        {
            changeAddressStreet(command[1]);
            break;
        }
        case changeNrEnum:
        {
            changeAddressNr(std::stoi(command[1]));
            break;
        }
    }
    return false;
}

void Server::switchStateForEntrance(unsigned int id)
{
    std::cout << "[DEBUG] processing switchStateForEntrance() for entrance id : " << id << '\n';
}
void Server::addEntrance(int roomId, EntranceType type, Position position)
{
    std::cout << "[DEBUG] processing addEntrance() for room id : " << roomId << " type : " << toString(type) << " position : " << toString(position) << '\n' ;
}

void Server::deleteEntrance(int entranceId)
{
    std::cout << "[DEBUG] processing deleteEntrance() for entrance id : " << entranceId << '\n' ;
}
void Server::changeEntrance(int entranceId, EntranceType newType, Position newPosition)
{
    std::cout << "[DEBUG] processing changeEntrance() for entrance id : " << entranceId << " type : " << toString(newType) << " position : " << toString(newPosition) << '\n' ;
}
void Server::addRoom(int id,std::string name, int level)
{
    std::cout << "[DEBUG] processing addRoom() with room id : " << id << " name : " << name << " level : " << level << '\n' ;
}
void Server::changeRoom(int roomId, std::string newName, int newLevel)
{
    std::cout << "[DEBUG] processing changeRoom() with room id : " << roomId << " name : " << newName << " level : " << newLevel << '\n' ;
}
void Server::deleteRoom(int roomId)
{
    std::cout << "[DEBUG] processing deleteRoom() with room id : " << roomId << '\n';
}
void Server::changeAddressCountry(std::string newCountryName)
{
     std::cout << "[DEBUG] processing changeAddressCountry() with newCountryName : " << newCountryName << '\n';
}
void Server::changeAddressCity(std::string newCityName)
{
    std::cout << "[DEBUG] processing changeAddressCity() with newCityName : " << newCityName << '\n';
}
void Server::changeAddressStreet(std::string newStreetName)
{
    std::cout << "[DEBUG] processing changeAddressStreet() with newStreetName : " << newStreetName << '\n';
}
void Server::changeAddressNr(int newNr)
{
    std::cout << "[DEBUG] processing changeAddressNr() with newNr : " << newNr << '\n';
}