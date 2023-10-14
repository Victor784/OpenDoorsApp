#include "utils.hpp"
#include <string>

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

stringHash convertStringToEnum(std::string str)
{
     if(str == "switch-status")
          return switchStatus;
     if(str == "add-entrance")
          return addEntrance;
     if(str == "delete-entrance")
          return deleteEntrance;
     if(str == "change-entrance")
          return changeEntrance;
     if(str == "add-room")
          return addRoom;
     if(str == "change-room")
          return changeRoom;
     if(str == "delete-room")
          return deleteRoom;
     if(str == "change-country")
          return changeCountry;
     if(str == "change-city")
          return changeCity;
     if(str == "change-street")
          return changeStreet;
     if(str == "change-nr")
          return changeNr;
}