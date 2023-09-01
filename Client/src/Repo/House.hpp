#pragma  once

#include"Room.hpp"
#include <ostream>
#include <string>
#include <vector>

struct Address
{
    unsigned int nr = 0;
    int floor = 0;
    std::string streetName = "NOT SET";
    std::string city = "NOT SET";
    std::string coutry = "NOT SET";

    friend std::ostream& operator<<(std::ostream& os, const Address& adr);
};



class House
{
    public:
        House();
        House(Address addresVal);
        House(Address addresVal, std::vector<Room> roomsVect);
        House(std::vector<Room> roomsVect);
        ~House() = default;

        unsigned int getId();
        Address getAddress();
        std::vector<Room> getRooms();

        void setAddress(Address newAddress);

        void setAddressCountry(std::string newCountry);
        void setAddressCity(std::string newCity);
        void setAddressStreet(std::string NewStreetName);
        void setAddressNr(unsigned int newNr);

        void setRooms(std::vector<Room> newRoomVect);

        void addRoom(Room newRoom); //TODO: if you add rooms this way, you need to create them first, meaning that the lifetime of the objects is dependent on the exec() method
        void removeRoom(unsigned int roomId);        
        void changeRoom(unsigned int roomId, std::string newName = "", std::string newLevel = "", std::vector<Entrance*> newEntrances = {});

        void addEntrance(unsigned int roomId, Entrance newEntrance);
        void changeEntrance(unsigned int entranceId , EntranceType newType, Position newPosition);
        void removeEntrance(unsigned int entranceId);

        std::string toString();

    public:
        static unsigned int houseIdGenerator ; 
    private:
        unsigned int id;
        Address addres;
        std::vector<Room> rooms;
};

