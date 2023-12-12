#pragma once

#include "Panel.hpp"


class BasePanel : public IPanel
{
     public:
        std::string nameOfPanel;
        std::vector<IPanel*> availablePanels;
        std::string display;
        bool isFinalPanelV;
        std::string cmd;
        

    public:
        
        bool isFinalPanel() override {return isFinalPanelV;}
        std::string getNameOfPanel() override {return nameOfPanel;}
        std::vector<IPanel*> getAvailablePanels() override {return availablePanels;}
        std::string getCmd() override {return cmd;}
        void setAvailablePanels(const std::vector<IPanel*> &vect) override { availablePanels = vect;};
        
};