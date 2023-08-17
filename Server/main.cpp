#include<iostream>
#include<fstream>
#include<string>
#include <chrono>
#include <thread>

void write(std::string message)
{
    std::ofstream ofs("../ServerClientPipe.txt");
    ofs << message;
    ofs.close();
}

std::string read()
{
    std::string messageFromClient;
    std::ifstream ifs ("../ClientServerPipe.txt");

    if(ifs.is_open()) 
    {
         while(std::getline(ifs, messageFromClient)) 
         {
            ifs >> messageFromClient;
         }
    }
    return messageFromClient;
}

int main()
{
    while(true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        write("ServertInput");
        std::cout << "from pipe  "<< read();
    }
}