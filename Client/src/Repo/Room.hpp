#pragma once
#include "Entrance.hpp"
#include <ostream>
#include <vector>

class Room 
{
    public:
        Room() = delete;
        Room(const std::string &nameVal, unsigned int levelVal, const std::vector<Entrance>& entranceVect);
        Room(const std::string &nameVal, unsigned int levelVal);
        ~Room() = default;

        unsigned int getId()const ;
        std::string getName() const;
        int getLevel()const ;
        std::vector<Entrance> getEntrances() const;

        void setName(const std::string &nameVal);
        void setLevel(unsigned int levelVal);
        void setEntrances(const std::vector<Entrance> &entranceVect);

        void addEntrance(const Entrance &newEntrance);
        void removeEntrance(unsigned int entranceId);
        void changeEntrance(unsigned int id, const EntranceType &newType, const Position &newPos );

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
