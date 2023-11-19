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
        House(const Address &addresVal);
        House(const Address &addresVal, const std::vector<Room>& roomsVect);
        House(const std::vector<Room>& roomsVect);
        ~House() = default;

        unsigned int getId() const;
        Address getAddress() const;
        std::vector<Room> getRooms() const;

        void setAddress(Address newAddress);

        void setAddressCountry(const std::string &newCountry);
        void setAddressCity(const std::string &newCity);
        void setAddressStreet(const std::string &NewStreetName);
        void setAddressNr(unsigned int newNr);

        void setRooms(const std::vector<Room> &newRoomVect);

        void addRoom(const Room &newRoom); //TODO: if you add rooms this way, you need to create them first, meaning that the lifetime of the objects is dependent on the exec() method, but there is copy made inside addRoom
        void removeRoom(unsigned int roomId);        
        void changeRoom(unsigned int roomId, std::string newName = "", std::string newLevel = "", std::vector<Entrance> newEntrances = {});

        void addEntrance(unsigned int roomId, const Entrance &newEntrance);
        void changeEntrance(unsigned int entranceId , const EntranceType &newType, const Position &newPosition);
        void removeEntrance(unsigned int entranceId);

        void changeEntranceStatus(unsigned int entranceId); 
        std::string toString();

    public:
        static unsigned int houseIdGenerator ; 
    private:
        unsigned int id;
        Address addres;
        std::vector<Room> rooms;
};

