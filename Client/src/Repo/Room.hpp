#pragma once
#include "Entrance.hpp"
#include <ostream>
#include <vector>

class Room 
{
    public:
        Room() = delete;
        Room(std::string nameVal, unsigned int levelVal, std::vector<Entrance>& entranceVect);
        Room(std::string nameVal, unsigned int levelVal);
        ~Room() = default;

        unsigned int getId()const ;
        std::string getName() const;
        int getLevel()const ;
        std::vector<Entrance> getEntrances() const;

        void setName(std::string nameVal);
        void setLevel(unsigned int levelVal);
        void setEntrances(std::vector<Entrance> entranceVect);

        void addEntrance(Entrance &newEntrance);
        void removeEntrance(unsigned int entranceId);
        void changeEntrance(unsigned int id, EntranceType newType, Position newPos );

        void changeEntranceStatus(int entranceId);

        friend std::ostream& operator<< (std::ostream& os, const Room& room);
        void operator=(const Room& other);
    public:
        static unsigned int roomIdGenerator;
    private:
        unsigned int id;
        std::string name;
        int level = 0;
        std::vector<Entrance> entrances;

};
