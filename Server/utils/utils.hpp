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
    addEntranceEnum,
    switchStatusEnum,
    deleteEntranceEnum,
    changeEntranceEnum,
    addRoomEnum,
    changeRoomEnum,
    deleteRoomEnum,
    changeCountryEnum,
    changeCityEnum,
    changeStreetEnum,
    changeNrEnum
};


stringHash convertStringToCommand(std::string cmd);

EntranceType convertStringToEntranceType(std::string type);

Position convertStringToPosition(std::string pos);


std::string toString(EntranceType type);

std::string toString(Position position);