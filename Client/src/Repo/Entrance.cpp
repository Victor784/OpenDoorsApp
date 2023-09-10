#include "Entrance.hpp"


unsigned int Entrance::idGenerator = 0;

Entrance::Entrance(EntranceType typeVal , Position positionVal , Status statusVal)
{

            id = ++idGenerator;
            type = typeVal;
            position = positionVal;
            status = statusVal;
        
}

unsigned int Entrance::getId() const
{
    return id;
}

EntranceType Entrance::getType() const
{
    return type;
}

Position Entrance::getPosition() const
{
    return position;
}
        
Status Entrance::getStatus() const
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

void Entrance::switchStatus()
{
    std::cout << "[DEBUG]Entrance before change" << utils::toString(status)<< '\n';
    if(type == EntranceType::RabatableDoor || type == EntranceType::RabatableWindow)
    {
        switch (status) 
        {
            case Status::Closed:
                status = Status::Folded;
                break;
            case Status::Folded:
                status = Status::Open;
                break;
            case Status::Open:
                status = Status::Closed;
                break;
            default:
                status = Status::Open;
        }
    }
    else // Entrance type is door or window
    {
         switch (status) 
        {
            case Status::Closed:
                status = Status::Open;
                break;
            case Status::Open:
                status = Status::Closed;
                break; 
            default:
                status = Status::Open;
        }
    }
    std::cout << "[DEBUG]Entrance after change" << utils::toString(status)<< '\n';
}

// TODO: template function toString would be a good idea

std::string utils::toString(EntranceType type)
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

std::string utils::toString(Position position)
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
std::string utils::toString(Status status)
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
    os << "Id: " << en.id << " | " << "Type: "<< utils::toString(en.type) << " | " << "Orientation: " << utils::toString(en.position) << " | " << "Status: "<< utils::toString(en.status); 
    return os;
}