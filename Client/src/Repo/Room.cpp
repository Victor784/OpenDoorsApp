#include "Room.hpp"

unsigned int Room::roomIdGenerator = 0;

Room::Room(const std::string &nameVal, unsigned int levelVal, const std::vector<Entrance>& entranceVal)
{
    id = ++roomIdGenerator;
    name = nameVal;
    level = levelVal;
    entrances = entranceVal;  
}

Room::Room(const std::string &nameVal, unsigned int levelVal)
{
    id = ++roomIdGenerator;
    name = nameVal;
    level = levelVal;
    std::vector<Entrance> entrances; 
}

unsigned int Room::getId() const
{
    return id;
}

std::string Room::getName() const
{
    return name;
}

int Room::getLevel() const
{
    return level;
}

std::vector<Entrance> Room::getEntrances() const
{
    return entrances;
}

void Room::setName(const std::string &nameVal)
{
    name = nameVal;
}

void Room::setLevel(unsigned int levelVal)
{
    level = levelVal;
}

void Room::setEntrances(const std::vector<Entrance> &entranceVect)
{
    entrances = entranceVect;
}

void Room::addEntrance(const Entrance& newEntrance)
{
    entrances.push_back(newEntrance);
}

void Room::removeEntrance(unsigned int entranceId)
{
    int position = 0;
    bool found = false;
    while (position < entrances.size() && !found )
    {
        if((entrances[position]).getId() == entranceId)
            found = true;
        else
            position = position + 1;
    }

    if(position < entrances.size() && found)
    {
        entrances.erase(entrances.begin() + position);
    }
}

void Room::changeEntrance(unsigned int id, const EntranceType &newType, const Position &newPos )
{
    for (int i = 0; i< entrances.size(); i++)
    {
        if((entrances[i]).getId() == id)
        {
            entrances[i].setType(newType);
            entrances[i].setPosition(newPos);
            entrances[i].setStatus(Status::Open); // when changing an entrance details , auto change the status to open
        }
    }
}

void Room::changeEntranceStatus(int entranceId)
{
     for(Entrance& entrance : entrances)
     {
        if(entrance.getId() == entranceId)
        {
            entrance.switchStatus();
        }
     }
}

std::ostream& operator<< (std::ostream &os, const  Room &room)
{
    os << "Room ID: " << room.id << " | " << "Room name: " << room.name << " | " 
    << "Room level: " << room.level<< "Entrances: ";

    for(const auto& elem : room.entrances)
    {
        os<<elem<<'\n';
    }
    return os;
}

void Room::operator=(const Room& other)
{
    id = other.id;
    name = other.name;
    level = other.level;
    entrances = other.entrances;
}

