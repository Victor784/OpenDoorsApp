#pragma once
#include "Entrance.hpp"
#include <vector>

class Room 
{
    public:
        Room() = delete;
        Room(std::string name_val, unsigned int level_val, std::vector<Entrance> entrance_vect);
        Room(std::string name_val, unsigned int level_val);
        ~Room() = default;

        unsigned int getId();
        std::string getName();
        int getLevel();
        std::vector<Entrance> getEntrances();

        void setName(std::string name_val);
        void setLevel(unsigned int level_val);
        void setEntrances(std::vector<Entrance> entranceVect);

        void addEntrance(Entrance newEntrance);
        void removeEntrance(unsigned int entranceId);

    public:
        static unsigned int roomIdGenerator;
    private:
        unsigned int id;
        std::string name;
        int level = 0;
        std::vector<Entrance> entrances; 

};
