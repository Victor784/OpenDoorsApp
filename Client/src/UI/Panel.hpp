// #pragma once

#include <iostream>
#include <vector>

class Panel;

class IPanel
{
    public:
        virtual IPanel* exec() = 0;
        virtual std::string getNameOfPanel() = 0;
        virtual bool isFinalPanel() = 0;
        virtual std::vector<IPanel*> getAvailablePanels() = 0;
        virtual std::string getCmd() = 0;
        virtual void setAvailablePanels(const std::vector<IPanel*> &vect) = 0;
};
