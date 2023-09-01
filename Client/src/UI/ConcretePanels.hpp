#pragma once

#include "Panel.hpp"
#include"../Repo/House.hpp"

class PanelForListAllEntrances : public IPanel
{
    public:
        std::string nameOfPanel;
        std::vector<IPanel*> availablePanels;
        std::string display;
        bool isFinalPanelV;
        std::string cmd;
        House* repoPtr;

    public:
        PanelForListAllEntrances() = delete;
        PanelForListAllEntrances(std::string name , std::string outPut, bool finalPanel, std::string command, House* repoPtrVal) : 
        nameOfPanel(name), display(outPut), isFinalPanelV(finalPanel), cmd(command) , repoPtr(std::move(repoPtrVal)){}
        // Panel(std::string name , std::vector<Panel*> vect) :
        // nameOfPanel(name) , availablePanels(vect) {}
        IPanel* exec() override;
        bool isFinalPanel() override {return isFinalPanelV;}
        std::string getNameOfPanel() override {return nameOfPanel;}
        std::vector<IPanel*> getAvailablePanels() override {return availablePanels;}
        std::string getCmd() override {return cmd;}
        void setAvailablePanels(std::vector<IPanel*> vect) override { availablePanels = vect;};
        ~PanelForListAllEntrances() = default;
        House * getRepoPtr() {return repoPtr;};
};



class PanelForOptionDisplay : public IPanel
{
    public:
        std::string nameOfPanel;
        std::vector<IPanel*> availablePanels;
        std::string display;
        bool isFinalPanelV;
        std::string cmd;
    public:
        PanelForOptionDisplay() = delete;
        PanelForOptionDisplay(std::string name , std::string outPut, bool finalPanel, std::string command) : 
        nameOfPanel(name), display(outPut), isFinalPanelV(finalPanel), cmd(command) {}
        IPanel* exec() override;
        bool isFinalPanel() override {return isFinalPanelV;}
        std::string getNameOfPanel() override {return nameOfPanel;}
        std::vector<IPanel*> getAvailablePanels() override {return availablePanels;}
        std::string getCmd() override {return cmd;}
        void setAvailablePanels(std::vector<IPanel*> vect) override { availablePanels = vect;};
        ~PanelForOptionDisplay() = default;
};



class PanelForChangeHouseLayout : public IPanel
{
    public:
        std::string nameOfPanel;
        std::vector<IPanel*> availablePanels;
        std::string display;
        bool isFinalPanelV;
        std::string cmd;
        House* house;
    public:
        PanelForChangeHouseLayout() = delete;
        PanelForChangeHouseLayout(std::string name , std::string outPut, bool finalPanel, std::string command, House* houseVal) : 
        nameOfPanel(name), display(outPut), isFinalPanelV(finalPanel), cmd(command), house(std::move(houseVal)) {}
        IPanel* exec() override ; 
        bool isFinalPanel() override {return isFinalPanelV;}
        std::string getNameOfPanel() override {return nameOfPanel;}
        std::vector<IPanel*> getAvailablePanels() override {return availablePanels;}
        std::string getCmd() override {return cmd;}
        void setAvailablePanels(std::vector<IPanel*> vect) override { availablePanels = vect;};
        ~PanelForChangeHouseLayout() = default;
};


class PanelForChangeHouseDetails : public IPanel
{
    public:
        std::string nameOfPanel;
        std::vector<IPanel*> availablePanels;
        std::string display;
        bool isFinalPanelV;
        std::string cmd;
        House* house;
    public:
        PanelForChangeHouseDetails() = delete;
        PanelForChangeHouseDetails(std::string name , std::string outPut, bool finalPanel, std::string command, House* houseVal) : 
        nameOfPanel(name), display(outPut), isFinalPanelV(finalPanel), cmd(command), house(std::move(houseVal)) {}
        IPanel* exec() override ; 
        bool isFinalPanel() override {return isFinalPanelV;}
        std::string getNameOfPanel() override {return nameOfPanel;}
        std::vector<IPanel*> getAvailablePanels() override {return availablePanels;}
        std::string getCmd() override {return cmd;}
        void setAvailablePanels(std::vector<IPanel*> vect) override { availablePanels = vect;};
        ~PanelForChangeHouseDetails() = default;
    private:
        std::string inOutHouseDetails(int option);
};

class PanelForChangeRooms : public IPanel
{
    public:
        std::string nameOfPanel;
        std::vector<IPanel*> availablePanels;
        std::string display;
        bool isFinalPanelV;
        std::string cmd;
        House* house;
    public:
        PanelForChangeRooms() = delete;
        PanelForChangeRooms(std::string name , std::string outPut, bool finalPanel, std::string command, House* houseVal) : 
        nameOfPanel(name), display(outPut), isFinalPanelV(finalPanel), cmd(command), house(std::move(houseVal)) {}
        IPanel* exec() override ; 
        bool isFinalPanel() override {return isFinalPanelV;}
        std::string getNameOfPanel() override {return nameOfPanel;}
        std::vector<IPanel*> getAvailablePanels() override {return availablePanels;}
        std::string getCmd() override {return cmd;}
        void setAvailablePanels(std::vector<IPanel*> vect) override { availablePanels = vect;};
        ~PanelForChangeRooms() = default;
};  


class PanelForAddRoom : public IPanel
{
    public:
        std::string nameOfPanel;
        std::vector<IPanel*> availablePanels;
        std::string display;
        bool isFinalPanelV;
        std::string cmd;
        House* house;
    public:
        PanelForAddRoom() = delete;
        PanelForAddRoom(std::string name , std::string outPut, bool finalPanel, std::string command, House* houseVal) : 
        nameOfPanel(name), display(outPut), isFinalPanelV(finalPanel), cmd(command), house(std::move(houseVal)) {}
        IPanel* exec() override ; 
        bool isFinalPanel() override {return isFinalPanelV;}
        std::string getNameOfPanel() override {return nameOfPanel;}
        std::vector<IPanel*> getAvailablePanels() override {return availablePanels;}
        std::string getCmd() override {return cmd;}
        void setAvailablePanels(std::vector<IPanel*> vect) override { availablePanels = vect;};
        ~PanelForAddRoom() = default;
};  

class PanelForChangeRoom : public IPanel
{
    public:
        std::string nameOfPanel;
        std::vector<IPanel*> availablePanels;
        std::string display;
        bool isFinalPanelV;
        std::string cmd;
        House* house;
    public:
        PanelForChangeRoom() = delete;
        PanelForChangeRoom(std::string name , std::string outPut, bool finalPanel, std::string command, House* houseVal) : 
        nameOfPanel(name), display(outPut), isFinalPanelV(finalPanel), cmd(command), house(std::move(houseVal)) {}
        IPanel* exec() override ; 
        bool isFinalPanel() override {return isFinalPanelV;}
        std::string getNameOfPanel() override {return nameOfPanel;}
        std::vector<IPanel*> getAvailablePanels() override {return availablePanels;}
        std::string getCmd() override {return cmd;}
        void setAvailablePanels(std::vector<IPanel*> vect) override { availablePanels = vect;};
        ~PanelForChangeRoom() = default;
};  


class PanelForDeleteRoom : public IPanel
{
    public:
        std::string nameOfPanel;
        std::vector<IPanel*> availablePanels;
        std::string display;
        bool isFinalPanelV;
        std::string cmd;
        House* house;
    public:
        PanelForDeleteRoom() = delete;
        PanelForDeleteRoom(std::string name , std::string outPut, bool finalPanel, std::string command, House* houseVal) : 
        nameOfPanel(name), display(outPut), isFinalPanelV(finalPanel), cmd(command), house(std::move(houseVal)) {}
        IPanel* exec() override ; 
        bool isFinalPanel() override {return isFinalPanelV;}
        std::string getNameOfPanel() override {return nameOfPanel;}
        std::vector<IPanel*> getAvailablePanels() override {return availablePanels;}
        std::string getCmd() override {return cmd;}
        void setAvailablePanels(std::vector<IPanel*> vect) override { availablePanels = vect;};
        ~PanelForDeleteRoom() = default;
};  


class PanelForChangeEntrances : public IPanel
{
    public:
        std::string nameOfPanel;
        std::vector<IPanel*> availablePanels;
        std::string display;
        bool isFinalPanelV;
        std::string cmd;
        House* house;
    public:
        PanelForChangeEntrances() = delete;
        PanelForChangeEntrances(std::string name , std::string outPut, bool finalPanel, std::string command, House* houseVal) : 
        nameOfPanel(name), display(outPut), isFinalPanelV(finalPanel), cmd(command), house(std::move(houseVal)) {}
        IPanel* exec() override ; 
        bool isFinalPanel() override {return isFinalPanelV;}
        std::string getNameOfPanel() override {return nameOfPanel;}
        std::vector<IPanel*> getAvailablePanels() override {return availablePanels;}
        std::string getCmd() override {return cmd;}
        void setAvailablePanels(std::vector<IPanel*> vect) override { availablePanels = vect;};
        ~PanelForChangeEntrances() = default;
};  



class PanelForAddEntrance : public IPanel
{
    public:
        std::string nameOfPanel;
        std::vector<IPanel*> availablePanels;
        std::string display;
        bool isFinalPanelV;
        std::string cmd;
        House* house;
    public:
        PanelForAddEntrance() = delete;
        PanelForAddEntrance(std::string name , std::string outPut, bool finalPanel, std::string command, House* houseVal) : 
        nameOfPanel(name), display(outPut), isFinalPanelV(finalPanel), cmd(command), house(std::move(houseVal)) {}
        IPanel* exec() override ; 
        bool isFinalPanel() override {return isFinalPanelV;}
        std::string getNameOfPanel() override {return nameOfPanel;}
        std::vector<IPanel*> getAvailablePanels() override {return availablePanels;}
        std::string getCmd() override {return cmd;}
        void setAvailablePanels(std::vector<IPanel*> vect) override { availablePanels = vect;};
        ~PanelForAddEntrance() = default;
};  