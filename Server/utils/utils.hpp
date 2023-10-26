#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>

namespace logging
{
    std::string getErrorAsString(int errorCode);

}

enum class EntranceType
{
    Window,
    RabatableWindow,
    Door,
    RabatableDoor
};

enum class Position
{
    East,
    West,
    South,
    North
};

enum stringHash : int
{
    switchStatusEnum,   //0
    addEntranceEnum,    //1
    deleteEntranceEnum, //2
    changeEntranceEnum, //3
    addRoomEnum,        //4
    changeRoomEnum,     //5
    deleteRoomEnum,     //6
    changeCountryEnum,  //7
    changeCityEnum,     //8
    changeStreetEnum,   //9
    changeNrEnum        //10
};

class Test{
    public:
static stringHash convertStringToCommand(std::string cmd);
};

EntranceType convertStringToEntranceType(std::string type);

Position convertStringToPosition(std::string pos);


std::string toString(EntranceType type);

std::string toString(Position position);