#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>

namespace logging
{
    std::string getErrorAsString(int errorCode);

}