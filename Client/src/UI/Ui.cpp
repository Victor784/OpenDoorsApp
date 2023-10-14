#include "Ui.hpp"

void UI::run()
        {
            // while(currentPanel->getNameOfPanel() != "Exit Panel")
            // {
                if(currentPanel->isFinalPanel())
                {
                    std::cout << "\n DEBUG: " << currentPanel->getNameOfPanel() << '\n';
                    IPanel* aux = currentPanel->exec();
                    if(aux->getNameOfPanel() == "Confirmation Panel")
                    {  
                        cmd = currentPanel->getCmd(); // prepare the cmd for the client so it can be sent
                        currentPanel = currentPanel->getAvailablePanels()[0]; // after "sending" the cmd move the the confirmation panel move back to previous state
                    }
                    if(aux->getNameOfPanel() == "Abort Panel")
                    {
                        cmd.clear(); 
                        std::cout << "Aborted the operation \n";
                        currentPanel = currentPanel->getAvailablePanels()[0]; // after "aborting" the operation move the the confirmation panel move back 2 states
                    }

                }
                else 
                { 
                    IPanel* aux = currentPanel->exec();
                    if(aux->getNameOfPanel() == "All entrances")
                    {
                        cmd = currentPanel->getCmd();
                    }
                    else if(aux->getNameOfPanel() == "House details")
                    {
                        cmd = currentPanel->getCmd();
                    }
                    currentPanel = aux;
                }
                
            // }
        }