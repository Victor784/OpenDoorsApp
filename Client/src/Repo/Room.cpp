#include "Room.hpp"

unsigned int Room::roomIdGenerator = 0;

Room::Room(std::string nameVal, unsigned int levelVal, std::vector<Entrance> entranceVal)
{
    id = ++roomIdGenerator;
    name = nameVal;
    level = levelVal;
    entrances = entranceVal;  
}

Room::Room(std::string nameVal, unsigned int levelVal)
{
    id = ++roomIdGenerator;
    name = nameVal;
    level = levelVal;
    std::vector<Entrance> entrances; 
}

unsigned int Room::getId()
{
    return id;
}

std::string Room::getName() const
{
    return name;
}

int Room::getLevel()
{
    return level;
}

std::vector<Entrance> Room::getEntrances() const
{
    return entrances;
}

void Room::setName(std::string nameVal)
{
    name = nameVal;
}

void Room::setLevel(unsigned int levelVal)
{
    level = levelVal;
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
    std::cout << "here from =operator for Room\n";
    id = other.id;
    name = other.name;
    level = other.level;
    entrances = other.entrances;
}

