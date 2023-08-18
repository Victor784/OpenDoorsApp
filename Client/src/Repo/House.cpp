#include "House.hpp"

unsigned int House::houseIdGenerator = 0;

House::House()
{
    id = ++houseIdGenerator;
}

House::House(Address address_val)
{
    id = ++houseIdGenerator;
    addres = address_val;
}

House::House(Address address_val, std::vector<Room> rooms_vect)
{
    id = ++houseIdGenerator;
    addres = address_val;
    rooms = rooms_vect;
}

House::House(std::vector<Room> rooms_vect)
{
    id = ++houseIdGenerator;
    rooms = rooms_vect;
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