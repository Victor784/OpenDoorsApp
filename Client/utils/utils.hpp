#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include <iostream>
#include <vector>

namespace logging
{
    std::string getErrorAsString(int errorCode);

}

namespace utils
{
     template <typename in_type>
     void readInput(in_type &input , std::vector<in_type> acceptedInputs = {})
      {
          bool answerIsOk = false ; 
          while (!answerIsOk)
          {
            std::cin >> input ;
            if(!acceptedInputs.empty())
            {
                for(auto elem : acceptedInputs)
                {
                    if(input == elem)
                        answerIsOk = true;
                }
            }
            answerIsOk = true;
          }
          
      }
}