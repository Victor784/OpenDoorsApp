#include "utils.hpp"
#include <string>
#include <iostream>

namespace logging {
     std::string getErrorAsString(int errorCode)
     {
        char msgbuf [256];   // for a message up to 255 bytes.


        msgbuf [0] = '\0';    // Microsoft doesn't guarantee this on man page.


        FormatMessage (FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,   // flags
                    NULL,                // lpsource
                    errorCode,                 // message id
                    MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),    // languageid
                    msgbuf,              // output buffer
                    sizeof (msgbuf),     // size of msgbuf, bytes
                    NULL);               // va_list of arguments

            return msgbuf;
     }

}


stringHash convertStringToCommand(std::string cmd)
{
     std::cout << "[DEBUG] convertStringToCommand\n";
     if(cmd == "switch-status")
     {    
          std::cout << "[DEBUG] stringHash::switchStatusEnum\n";
          return stringHash::switchStatusEnum;
         
     }
          
     if(cmd == "add-entrance")
          return stringHash::addEntranceEnum;
     if(cmd == "delete-entrance")
          return stringHash::deleteEntranceEnum;
     if(cmd == "change-entrance")
          return stringHash::changeEntranceEnum;
     if(cmd == "add-room")
          return stringHash::addRoomEnum;
     if(cmd == "change-room")
          return stringHash::changeRoomEnum;
     if(cmd == "delete-room")
          return stringHash::deleteRoomEnum;
     if(cmd == "change-country")
          return stringHash::changeCountryEnum;
     if(cmd == "change-city")
          return stringHash::changeCityEnum;
     if(cmd == "change-street")
          return stringHash::changeStreetEnum;
     if(cmd == "change-nr")
          return stringHash::changeNrEnum; 
     std::cout << "[DEBUG] EXIT convertStringToCommand\n";
}

EntranceType convertStringToEntranceType(std::string type)
{
     if(type =="Window")
          return EntranceType::Window;
     if(type == "Rabatablewindow")
          return EntranceType::RabatableWindow;
     if(type == "Door")
          return EntranceType::Door;
     if(type == "Rabatabledoor")
          return EntranceType::RabatableDoor;
}

Position convertStringToPosition(std::string pos)
{
      if(pos =="North")
          return Position::North;
     if(pos == "South")
          return Position::South;
     if(pos == "East")
          return Position::East;
     if(pos == "West")
          return Position::West;
}

std::string toString(EntranceType type)
{
    switch (type) {
        case EntranceType::Door:
            return "Door";
        case EntranceType::RabatableDoor:
            return "Rabatable door";
        case EntranceType::Window:
            return "Window";
        case EntranceType::RabatableWindow:
            return "Rabatable window";
        default:
            return "";
    }
}

std::string toString(Position position)
{
    switch (position) {
        case Position::East:
            return "East";
        case Position::North:
            return "North";
        case Position::South:
            return "South";
        case Position::West:
            return "West";
        default:
            return "";
    }
}
