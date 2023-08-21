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
        void setRooms(std::vector<Room> newRoomVect);

        void addRoom(Room newRoom);
        void removeRoom(unsigned int roomId);

    public:
        static unsigned int houseIdGenerator ; 
    private:
        unsigned int id;
        Address addres;
        std::vector<Room> rooms;
};

