#pragma once

#include "ConcretePanels.hpp"
#include "../Repo/House.hpp"
/*
DESIGN PLAN: 


  THe idea: the State Machine (UI) has as a member a reference to a state called
  currentState, and has a method called run, which is a while(1) loop that calles the
  currentState()-> run() chatches the return val in an aux and changes the currnetState 
  of the UI to the aux val which is the next state.
  
  */

class Client;

class UI
{
    public:
        IPanel* currentPanel;
        std::string cmd;
        House* house;
    public:
        UI(){};
        UI(IPanel* initPanel, const std::string &command, House* repoVal) : 
        currentPanel(initPanel) , cmd(command) , house(repoVal){}
        void run();
};
