#pragma once
#include<string>
#include<iostream>

enum class EntranceType
{
    Window,
    Rabatable_Window,
    Door,
    Rabatable_Door
};

enum class Position
{
    East,
    West,
    South,
    North
};

enum class Status
{
    Open,
    Closed,
    Folded
};

class Entrance
{
    public:
        Entrance() = delete;
        Entrance(EntranceType type_val , Position position_val , Status status_val);
        ~Entrance() = default;

        unsigned int getId();
        EntranceType getType();
        Position getPosition();
        Status getStatus();

        void setType(EntranceType newType);
        void setPosition(Position newPosition);
        void setStatus(Status newStatus);
        
        friend std::ostream& operator<<(std::ostream& os, const Entrance& en);

    public:
        static unsigned int idGenerator;
    private:
        unsigned int id;
        EntranceType type;
        Position position;
        Status status;
};

std::string toString(EntranceType type);
std::string toString(Position position);
std::string toString(Status status);

