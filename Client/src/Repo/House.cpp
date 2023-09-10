#include "House.hpp"
#include <string>

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

House::House(Address addresVal, std::vector<Room>& roomsVect)
{
    id = ++houseIdGenerator;
    addres = addresVal;
    rooms = roomsVect;
}

House::House(std::vector<Room>& roomsVect)
{
    id = ++houseIdGenerator;
    rooms = roomsVect;
}

unsigned int House::getId() const
{
    return id;
}
        
Address House::getAddress() const
{
    return addres;
}
        
std::vector<Room> House::getRooms() const
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

void House::changeRoom(unsigned int roomId, std::string newName, std::string newLevel, std::vector<Entrance> newEntrances)
{
    bool found = false;
    for(auto &room : rooms)
    {
        if(roomId == room.getId())
        {
            found = true;
            if(newName != "")
            {
                room.setName(newName);
            }
            if(newLevel != "")
            {
                room.setLevel(std::stoul(newLevel));
            }
            if(!newEntrances.empty())
            {
                room.setEntrances(newEntrances);
            }
        }
    }
    if(found == false)
        std::cout << "Cannot find room with the provided Id\n";
}

void House::addEntrance(unsigned int roomId, Entrance newEntrance)
{
    for(auto& room : rooms)
    {
        if(roomId == room.getId())
        {
            room.addEntrance(newEntrance);
        }
    }
}

void House::changeEntrance(unsigned int entranceId , EntranceType newType, Position newPosition)
{
    for(auto& room : rooms)
    {
        for(auto& entrance : room.getEntrances())
        {
            if(entranceId == entrance.getId())
            {
               room.changeEntrance(entranceId,newType, newPosition);
            }
        }
    }
}

void House::removeEntrance(unsigned int entranceId)
{
    for(auto& room : rooms)
    {
        for(auto& entrance : room.getEntrances())
        {
            if(entranceId == entrance.getId())
            {
                room.removeEntrance(entranceId);
            }
        }
    }
}

void House::changeEntranceStatus(unsigned int entranceId)
{
    for(auto& room : rooms)
    {
        for(auto& entrance : room.getEntrances())
        {
            if(entranceId == entrance.getId())
            {
                std::cout << "[DEBUG] House Entrance in change entrance func before  " << entrance << '\n';
                // entrance.switchStatus();
                room.changeEntranceStatus(entranceId);
                std::cout << "[DEBUG] House Entrance in change entrance func after " << entrance << '\n';
            }
        }
    }
}


std::ostream& operator<<(std::ostream& os, const Address& adr)
{
    os<<"Country: " << adr.coutry << " | " << "City: " << " | " << 
    "Street Name: " << adr.streetName << " | " << "Nr. " << adr.nr 
    << " | " << "Floor: " << adr.floor;
    return os;
}

std::string House::toString()
{
    std::string outPut("\n Address ----- \n"
   "  Country: " + addres.coutry  + 
    " City: " + addres.city + 
    " Street: " + addres.streetName + 
    " Nr: " + std::to_string(addres.nr) + 
    (addres.floor == 0 ? "" : "Floor: " + std::to_string(addres.floor))
    + "\n----------------" + 
    "\nRoom layout: -----\n"
    ); 

    for(const auto room : rooms)
    {
        outPut.append("-->" + room.getName() + '\n');
            for(const auto entrance : room.getEntrances())
            {
                outPut.append("   Id: " + std::to_string(entrance.getId())
                + " | " + "Type: " + utils::toString(entrance.getType()) +
                " | " + "Position: " + utils::toString(entrance.getPosition()) +
                " | " + "Status: " + utils::toString(entrance.getStatus()) + '\n'
                );

            }
    }
    outPut.append( "\n-----------------\n");
    return outPut;
}

void House::setAddressCountry(std::string newCountry)
{
    addres.coutry = newCountry;
}
void House::setAddressCity(std::string newCity)
{
    addres.city = newCity;
}
void House::setAddressStreet(std::string NewStreetName)
{
    addres.streetName = NewStreetName;
}

void House::setAddressNr(unsigned int newNr)
{
    addres.nr = newNr;
}
