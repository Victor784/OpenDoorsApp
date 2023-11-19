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
        PanelForListAllEntrances(const std::string &name , const std::string &outPut, bool finalPanel, const std::string &command, House* repoPtrVal) : 
        nameOfPanel(name), display(outPut), isFinalPanelV(finalPanel), cmd(command) , repoPtr(std::move(repoPtrVal)){}
        // Panel(std::string name , std::vector<Panel*> vect) :
        // nameOfPanel(name) , availablePanels(vect) {}
        IPanel* exec() override;
        bool isFinalPanel() override {return isFinalPanelV;}
        std::string getNameOfPanel() override {return nameOfPanel;}
        std::vector<IPanel*> getAvailablePanels() override {return availablePanels;}
        std::string getCmd() override {return cmd;}
        void setAvailablePanels(const std::vector<IPanel*> &vect) override { availablePanels = vect;};
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
        PanelForOptionDisplay(const std::string &name , const std::string &outPut, bool finalPanel, const std::string &command) : 
        nameOfPanel(name), display(outPut), isFinalPanelV(finalPanel), cmd(command) {}
        IPanel* exec() override;
        bool isFinalPanel() override {return isFinalPanelV;}
        std::string getNameOfPanel() override {return nameOfPanel;}
        std::vector<IPanel*> getAvailablePanels() override {return availablePanels;}
        std::string getCmd() override {return cmd;}
        void setAvailablePanels(const std::vector<IPanel*> &vect) override { availablePanels = vect;};
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
        PanelForChangeHouseLayout(const std::string &name , const std::string &outPut, bool finalPanel, const std::string &command, House* houseVal) : 
        nameOfPanel(name), display(outPut), isFinalPanelV(finalPanel), cmd(command), house(std::move(houseVal)) {}
        IPanel* exec() override ; 
        bool isFinalPanel() override {return isFinalPanelV;}
        std::string getNameOfPanel() override {return nameOfPanel;}
        std::vector<IPanel*> getAvailablePanels() override {return availablePanels;}
        std::string getCmd() override {return cmd;}
        void setAvailablePanels(const std::vector<IPanel*> &vect) override { availablePanels = vect;};
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
        PanelForChangeHouseDetails(const std::string &name , const std::string &outPut, bool finalPanel, const std::string &command, House* houseVal) : 
        nameOfPanel(name), display(outPut), isFinalPanelV(finalPanel), cmd(command), house(std::move(houseVal)) {}
        IPanel* exec() override ; 
        bool isFinalPanel() override {return isFinalPanelV;}
        std::string getNameOfPanel() override {return nameOfPanel;}
        std::vector<IPanel*> getAvailablePanels() override {return availablePanels;}
        std::string getCmd() override {return cmd;}
        void setAvailablePanels(const std::vector<IPanel*> &vect) override { availablePanels = vect;};
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
        PanelForChangeRooms(const std::string &name , const std::string &outPut, bool finalPanel, const std::string &command, House* houseVal) : 
        nameOfPanel(name), display(outPut), isFinalPanelV(finalPanel), cmd(command), house(std::move(houseVal)) {}
        IPanel* exec() override ; 
        bool isFinalPanel() override {return isFinalPanelV;}
        std::string getNameOfPanel() override {return nameOfPanel;}
        std::vector<IPanel*> getAvailablePanels() override {return availablePanels;}
        std::string getCmd() override {return cmd;}
        void setAvailablePanels(const std::vector<IPanel*> &vect) override { availablePanels = vect;};
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
        PanelForAddRoom(const std::string &name , const std::string &outPut, bool finalPanel, const std::string &command, House* houseVal) : 
        nameOfPanel(name), display(outPut), isFinalPanelV(finalPanel), cmd(command), house(std::move(houseVal)) {}
        IPanel* exec() override ; 
        bool isFinalPanel() override {return isFinalPanelV;}
        std::string getNameOfPanel() override {return nameOfPanel;}
        std::vector<IPanel*> getAvailablePanels() override {return availablePanels;}
        std::string getCmd() override {return cmd;}
        void setAvailablePanels(const std::vector<IPanel*> &vect) override { availablePanels = vect;};
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
        PanelForChangeRoom(const std::string &name , const std::string &outPut, bool finalPanel, const std::string &command, House* houseVal) : 
        nameOfPanel(name), display(outPut), isFinalPanelV(finalPanel), cmd(command), house(std::move(houseVal)) {}
        IPanel* exec() override ; 
        bool isFinalPanel() override {return isFinalPanelV;}
        std::string getNameOfPanel() override {return nameOfPanel;}
        std::vector<IPanel*> getAvailablePanels() override {return availablePanels;}
        std::string getCmd() override {return cmd;}
        void setAvailablePanels(const std::vector<IPanel*> &vect) override { availablePanels = vect;};
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
        PanelForDeleteRoom(const std::string &name , const std::string &outPut, bool finalPanel, const std::string &command, House* houseVal) : 
        nameOfPanel(name), display(outPut), isFinalPanelV(finalPanel), cmd(command), house(std::move(houseVal)) {}
        IPanel* exec() override ; 
        bool isFinalPanel() override {return isFinalPanelV;}
        std::string getNameOfPanel() override {return nameOfPanel;}
        std::vector<IPanel*> getAvailablePanels() override {return availablePanels;}
        std::string getCmd() override {return cmd;}
        void setAvailablePanels(const std::vector<IPanel*> &vect) override { availablePanels = vect;};
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
        PanelForChangeEntrances(const std::string &name , const std::string &outPut, bool finalPanel, const std::string &command, House* houseVal) : 
        nameOfPanel(name), display(outPut), isFinalPanelV(finalPanel), cmd(command), house(std::move(houseVal)) {}
        IPanel* exec() override ; 
        bool isFinalPanel() override {return isFinalPanelV;}
        std::string getNameOfPanel() override {return nameOfPanel;}
        std::vector<IPanel*> getAvailablePanels() override {return availablePanels;}
        std::string getCmd() override {return cmd;}
        void setAvailablePanels(const std::vector<IPanel*> &vect) override { availablePanels = vect;};
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
        PanelForAddEntrance(const std::string &name , const std::string &outPut, bool finalPanel, const std::string &command, House* houseVal) : 
        nameOfPanel(name), display(outPut), isFinalPanelV(finalPanel), cmd(command), house(std::move(houseVal)) {}
        IPanel* exec() override ; 
        bool isFinalPanel() override {return isFinalPanelV;}
        std::string getNameOfPanel() override {return nameOfPanel;}
        std::vector<IPanel*> getAvailablePanels() override {return availablePanels;}
        std::string getCmd() override {return cmd;}
        void setAvailablePanels(const std::vector<IPanel*> &vect) override { availablePanels = vect;};
        ~PanelForAddEntrance() = default;
};  

class PanelForDeleteEntrance : public IPanel
{
    public:
        std::string nameOfPanel;
        std::vector<IPanel*> availablePanels;
        std::string display;
        bool isFinalPanelV;
        std::string cmd;
        House* house;
    public:
        PanelForDeleteEntrance() = delete;
        PanelForDeleteEntrance(const std::string &name , const std::string &outPut, bool finalPanel, const std::string &command, House* houseVal) : 
        nameOfPanel(name), display(outPut), isFinalPanelV(finalPanel), cmd(command), house(std::move(houseVal)) {}
        IPanel* exec() override ; 
        bool isFinalPanel() override {return isFinalPanelV;}
        std::string getNameOfPanel() override {return nameOfPanel;}
        std::vector<IPanel*> getAvailablePanels() override {return availablePanels;}
        std::string getCmd() override {return cmd;}
        void setAvailablePanels(const std::vector<IPanel*> &vect) override { availablePanels = vect;};
        ~PanelForDeleteEntrance() = default;
};  

class PanelForChangeEntrance : public IPanel
{
    public:
        std::string nameOfPanel;
        std::vector<IPanel*> availablePanels;
        std::string display;
        bool isFinalPanelV;
        std::string cmd;
        House* house;
    public:
        PanelForChangeEntrance() = delete;
        PanelForChangeEntrance(const std::string &name , const std::string &outPut, bool finalPanel, const std::string &command, House* houseVal) : 
        nameOfPanel(name), display(outPut), isFinalPanelV(finalPanel), cmd(command), house(std::move(houseVal)) {}
        IPanel* exec() override ; 
        bool isFinalPanel() override {return isFinalPanelV;}
        std::string getNameOfPanel() override {return nameOfPanel;}
        std::vector<IPanel*> getAvailablePanels() override {return availablePanels;}
        std::string getCmd() override {return cmd;}
        void setAvailablePanels(const std::vector<IPanel*> &vect) override { availablePanels = vect;};
        ~PanelForChangeEntrance() = default;
}; 