#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>

namespace logging
{
    std::string getErrorAsString(int errorCode);

}

enum stringHash
{
    switchStatus,
    addEntrance,
    deleteEntrance,
    changeEntrance,
    addRoom,
    changeRoom,
    deleteRoom,
    changeCountry,
    changeCity,
    changeStreet,
    changeNr
};

stringHash convertStringToEnum(std::string str);