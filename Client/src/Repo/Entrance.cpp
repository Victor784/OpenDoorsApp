#include "Entrance.hpp"


unsigned int Entrance::idGenerator = 0;

Entrance::Entrance(EntranceType type_val , Position position_val , Status status_val)
{
     
            id = ++idGenerator;
            type = type_val;
            position = position_val;
            status = status_val;
        
}

unsigned int Entrance::getId()
{
    return id;
}

EntranceType Entrance::getType()
{
    return type;
}

Position Entrance::getPosition()
{
    return position;
}
        
Status Entrance::getStatus()
{
    return status;
}

void Entrance::setType(EntranceType newType)
{
    type = newType;
}
        
void Entrance::setPosition(Position newPosition)
{
    position = newPosition;
}

void Entrance::setStatus(Status newStatus)
{
    status = newStatus;
}


std::string toString(EntranceType type)
{
    switch (type) {
        case EntranceType::Door:
            return "Door";
        case EntranceType::Rabatable_Door:
            return "Rabatable door";
        case EntranceType::Window:
            return "Window";
        case EntranceType::Rabatable_Window:
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
std::string toString(Status status)
{
    switch (status) {
        case Status::Closed:
            return "Closed";
        case Status::Folded:
            return "Folded";
        case Status::Open:
            return "Open";
        default:
            return "";
    }
}