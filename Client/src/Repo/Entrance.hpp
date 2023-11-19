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

        void setType(const EntranceType &newType);
        void setPosition(const Position &newPosition);
        void setStatus(const Status &newStatus); // initially used for everything , now used only for when a room is changed
        void switchStatus(); // using for switching between the statuses of an entrance
        
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
std::string toString(const EntranceType &type);
std::string toString(const Position &position);
std::string toString(const Status &status);
}
