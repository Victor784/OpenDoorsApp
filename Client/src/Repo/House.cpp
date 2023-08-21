#include "House.hpp"

unsigned int House::houseIdGenerator = 0;

House::House()
{
    id = ++houseIdGenerator;
}

House::House(Address addresVal)
{
    id = ++houseIdGenerator;
    addres = addresVal;
}

House::House(Address addresVal, std::vector<Room> roomsVect)
{
    id = ++houseIdGenerator;
    addres = addresVal;
    rooms = roomsVect;
}

House::House(std::vector<Room> roomsVect)
{
    id = ++houseIdGenerator;
    rooms = roomsVect;
}

unsigned int House::getId()
{
    return id;
}
        
Address House::getAddress()
{
    return addres;
}
        
std::vector<Room> House::getRooms()
{
    std::cout << "here from getRooms\n";
    return rooms;
}

void House::setAddress(Address newAddress)
{
    addres = newAddress;
}

void House::setRooms(std::vector<Room> newRoomVect)
{
    rooms = newRoomVect;
}

void House::addRoom(Room newRoom)
{
    rooms.push_back(newRoom);
}

void House::removeRoom(unsigned int roomId)
{
    int position = 0;
    bool found = false;
    while (position < rooms.size() && !found )
    {
        if(rooms[position].getId() == roomId)
            found = true;
        else
            position = position + 1;
    }

    if(position < rooms.size() && found)
    {
        rooms.erase(rooms.begin() + position);
    }
}

std::ostream& operator<<(std::ostream& os, const Address& adr)
{
    os<<"Country: " << adr.coutry << " | " << "City: " << " | " << 
    "Street Name: " << adr.streetName << " | " << "Nr. " << adr.nr 
    << " | " << "Floor: " << adr.floor;
    return os;
}