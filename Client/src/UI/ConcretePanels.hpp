#pragma once

#include "BasePanel.hpp"
#include "../Repo/House.hpp"

class PanelForListAllEntrances : public BasePanel
{
    public:
        House* repoPtr;
    public:
        PanelForListAllEntrances(House* houseVal)
        {
             nameOfPanel = "All entrances" ;
             display = " 0.Back\n" ;
             isFinalPanelV = false ;
             cmd = "" ;
             repoPtr = std::move(houseVal);
        }
        ~PanelForListAllEntrances() = default;
        IPanel* exec() override;
        House * getRepoPtr() {return repoPtr;};
};



class PanelForOptionDisplay : public BasePanel
{
    public:
        PanelForOptionDisplay() = delete;
        PanelForOptionDisplay(const std::string &name , const std::string &outPut, bool finalPanel, const std::string &command) {
            nameOfPanel = name ; display = outPut ;  isFinalPanelV = finalPanel ;  cmd = command;
        }
        IPanel* exec() override;
        ~PanelForOptionDisplay() = default;
};



class PanelForChangeHouseLayout : public BasePanel
{
    public:
        House* house;
    public:
        PanelForChangeHouseLayout(House* houseVal)
        {
            nameOfPanel = "House layout";
            display= " 1.House details\n 2.Rooms\n 3.Entrances\n 0.Back\n";
            isFinalPanelV = false;
            cmd = "";
            house =std::move(houseVal);
        }
        IPanel* exec() override ; 
        ~PanelForChangeHouseLayout() = default;
};


class PanelForChangeHouseDetails : public BasePanel
{
    public:
        House* house;
    public:
        PanelForChangeHouseDetails() = delete;
        PanelForChangeHouseDetails(House* houseVal) 
        {
            nameOfPanel = "House details";
            display= " 1.Change country\n 2.Change city\n 3.Change street\n 4.Change nr\n 0.Back\n";
            isFinalPanelV = false;
            cmd = "";
            house =std::move(houseVal);
        }
        IPanel* exec() override ; 
        ~PanelForChangeHouseDetails() = default;
    private:
        std::string inOutHouseDetails(int option);
};

class PanelForChangeRooms : public BasePanel
{
    public:
        House* house;
    public:
        PanelForChangeRooms(House* houseVal) 
        {
            nameOfPanel = "Rooms";
            display= " 1.Add room\n 2.Delete room\n 3.Change room\n 0.Back\n";
            isFinalPanelV = false;
            cmd = "";
            house =std::move(houseVal);
        } 
        IPanel* exec() override ; 
        ~PanelForChangeRooms() = default;
};  


class PanelForAddRoom : public BasePanel
{
    public:
        House* house;
    public:
        PanelForAddRoom(House* houseVal) 
        {
            nameOfPanel = "Add room";
            display= " 1.Confirm\n 2.Abort\n";
            isFinalPanelV = true;
            cmd = "";
            house =std::move(houseVal);
        }
        IPanel* exec() override ; 
        ~PanelForAddRoom() = default;
};  

class PanelForChangeRoom : public BasePanel
{
    public:
        House* house;
    public:
        PanelForChangeRoom(House* houseVal)
        {
            nameOfPanel = "Change room";
            display= " 1.Confirm\n 2.Abort\n";
            isFinalPanelV = true;
            cmd = "";
            house =std::move(houseVal);
        }
        IPanel* exec() override ; 
        ~PanelForChangeRoom() = default;
};  


class PanelForDeleteRoom : public BasePanel
{
    public:
        House* house;
    public:
        PanelForDeleteRoom( House* houseVal) 
        {
            nameOfPanel = "Delete room";
            display= " 1.Confirm\n 2.Abort\n";
            isFinalPanelV = true;
            cmd = "";
            house =std::move(houseVal);
        } 
        IPanel* exec() override ; 
        ~PanelForDeleteRoom() = default;
};  


class PanelForChangeEntrances : public BasePanel
{
    public:
        House* house;
    public:
        PanelForChangeEntrances(House* houseVal)
        {
            nameOfPanel = "Entrances";
            display= " 1.Add entrance\n 2.Delete entrance\n 3.Change entrance\n 0.Back\n";
            isFinalPanelV = false;
            cmd = "";
            house =std::move(houseVal);
        }
        IPanel* exec() override ; 
       ~PanelForChangeEntrances() = default;
};  



class PanelForAddEntrance : public BasePanel
{
    public:
        House* house;
    public:
        PanelForAddEntrance(House* houseVal)
        {
            nameOfPanel = "Add entrance";
            display= " 1.Confirm\n 2.Abort\n";
            isFinalPanelV = true;
            cmd = "";
            house =std::move(houseVal);
        }
        IPanel* exec() override ; 
        ~PanelForAddEntrance() = default;
};  

class PanelForDeleteEntrance : public BasePanel
{
    public:
        House* house;
    public:
        PanelForDeleteEntrance(House* houseVal)
        {
            nameOfPanel = "Delete entrance";
            display= " 1.Confirm\n 2.Abort\n";
            isFinalPanelV = true;
            cmd = "";
            house =std::move(houseVal);
        }
        IPanel* exec() override ; 
        ~PanelForDeleteEntrance() = default;
};  

class PanelForChangeEntrance : public BasePanel
{
    public:
        House* house;
    public:
        PanelForChangeEntrance(House* houseVal) 
        {
            nameOfPanel = "Change entrance";
            display= " 1.Confirm\n 2.Abort\n";
            isFinalPanelV = true;
            cmd = "";
            house =std::move(houseVal);
        }
        IPanel* exec() override ; 
        ~PanelForChangeEntrance() = default;
}; 