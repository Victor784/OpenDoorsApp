#pragma once
#include<string>
#include<iostream>

enum class EntranceType
{
    Window,
    RabatableWindow,
    Door,
    RabatableDoor
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
        Entrance(EntranceType typeVal , Position positionVal , Status statusVal);
        ~Entrance() = default;

        unsigned int getId() const;
        EntranceType getType() const;
        Position getPosition() const;
        Status getStatus() const;

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

namespace utils{
std::string toString(EntranceType type);
std::string toString(Position position);
std::string toString(Status status);
}
