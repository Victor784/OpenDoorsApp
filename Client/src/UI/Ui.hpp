#pragma once

#include "ConcretePanels.hpp"
#include "../Repo/House.hpp"
/*
DESIGN PLAN: 


  THe idea: the State Machine (UI) has as a member a reference to a state called
  currentState, and has a method called run, which is a while(1) loop that calles the
  currentState()-> run() chatches the return val in an aux and changes the currnetState 
  of the UI to the aux val. 
  
  */

  
class UI
{
    public:
        IPanel* currentPanel;
        std::string cmd;
        House* house;
    public:
        UI(){};
        UI(IPanel* initPanel, std::string command, House* repoVal) : 
        currentPanel(initPanel) , cmd(command) , house(repoVal){}
        void run()
        {
            while(currentPanel->getNameOfPanel() != "Exit Panel")
            {
                if(currentPanel->isFinalPanel())
                {
                    IPanel* aux = currentPanel->exec();
                    if(aux->getNameOfPanel() == "Confirmation Panel")
                    {  
                        cmd = currentPanel->getCmd();
                        std::cout << "CurrentPanel : " << currentPanel->getCmd() << '\n';  // TODO this is where the command should be sent
                        currentPanel = currentPanel->getAvailablePanels()[0]; // after "sending" the cmd move the the confirmation panel move back 2 states
                    }
                    if(aux->getNameOfPanel() == "Abort Panel")
                    {
                        cmd.clear(); //99& sure that this is no longer needed
                        std::cout << "Aborted the operation \n";
                        currentPanel = currentPanel->getAvailablePanels()[0]; // after "aborting" the operation move the the confirmation panel move back 2 states
                    }

                }
                else 
                {
                    IPanel* aux = currentPanel->exec();
                    currentPanel = aux;
                }
                
            }
        }
};
