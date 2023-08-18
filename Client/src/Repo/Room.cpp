#include "Room.hpp"

unsigned int Room::roomIdGenerator = 0;

Room::Room(std::string name_val, unsigned int level_val, std::vector<Entrance> entrance_vect)
{
    id = ++roomIdGenerator;
    name = name_val;
    level = level_val;
    entrances = entrance_vect;  
}

Room::Room(std::string name_val, unsigned int level_val)
{
    id = ++roomIdGenerator;
    name = name_val;
    level = level_val;
    std::vector<Entrance> entrances;  //TODO : ask Alex if this is needed or not
}

unsigned int Room::getId()
{
    return id;
}

std::string Room::getName()
{
    return name;
}

unsigned int Room::getLevel()
{
    return level;
}

std::vector<Entrance> Room::getEntrances()
{
    return entrances;
}

void Room::setName(std::string name_val)
{
    name = name_val;
}

void Room::setLevel(unsigned int level_val)
{
    level = level_val;
}

void Room::setEntrances(std::vector<Entrance> entranceVect)
{
    entrances = entranceVect;
}

void Room::addEntrance(Entrance newEntrance)
{
    entrances.push_back(newEntrance);
}

void Room::removeEntrance(unsigned int entranceId)
{
    int position = 0;
    bool found = false;
    while (position < entrances.size() && !found )
    {
        if(entrances[position].getId() == entranceId)
            found = true;
        else
            position = position + 1;
    }

    if(position < entrances.size() && found)
    {
        entrances.erase(entrances.begin() + position);
    }
}