#include "Entrance.hpp"


unsigned int Entrance::idGenerator = 0;

Entrance::Entrance(EntranceType typeVal , Position positionVal , Status statusVal)
{
     
            id = ++idGenerator;
            type = typeVal;
            position = positionVal;
            status = statusVal;
        
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
        case EntranceType::RabatableDoor:
            return "Rabatable door";
        case EntranceType::Window:
            return "Window";
        case EntranceType::RabatableWindow:
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

std::ostream& operator<<(std::ostream& os, const Entrance& en)
{
    os << "Id: " << en.id << " | " << "Type: "<< toString(en.type) << " | " << "Orientation: " << toString(en.position) << " | " << "Status: "<< toString(en.status); 
    return os;
}