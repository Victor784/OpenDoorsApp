#include "ConcretePanels.hpp"
#include <string>

IPanel* PanelForOptionDisplay::exec()
        {
            std::cout << "-----------" << nameOfPanel << "-----------" << '\n';
            
            std::cout << display;
            int option;
            std::cin >> option;
            if(option >= availablePanels.size()) //a lso check if the option is of type int
            {
                std::cout << "Invalid input..\n";
                return availablePanels[0]; // all panels have an exit / back option on the 0th position
            }
            else
            {   
                return availablePanels[option];
            }
            
        }

IPanel* PanelForListAllEntrances::exec()
        {
            std::cout << "---------" << nameOfPanel << "-----------" << '\n';
            int counter = 1;
            std::vector<Entrance*> auxEntranceVect; // in later implementation the house class should have a getAllEntrances method that can be used instead of an aux
            for(int i = 0; i < repoPtr->getRooms().size(); i ++ )
            
            {
                std::cout <<"-->" << (*repoPtr).getRooms()[i].getName() << '\n';
                    for(int j =0; j< (*repoPtr).getRooms()[i].getEntrances().size(); j++)
                    {
                        std::cout << "    " << counter ++ << '.' << *(*repoPtr).getRooms()[i].getEntrances()[j] << '\n';
                        auxEntranceVect.push_back((*repoPtr).getRooms()[i].getEntrances()[j]);
                    }
            }

            std::cout << display;
            std::cout << "Change the status of an entrance by pressing the number asociated with it: \n";
            int option;
            std::cin >> option;
            if(option == 0)
            {
                return availablePanels[0]; // all panels have an exit / back option on the 0th position
            }
            else if (option > counter - 1)
            {   
                std::cout << "\nInvalid choice..\n";
                return availablePanels[0];
            }
            else 
            {
                // case for changing the status
                Entrance* entrancePtrV = auxEntranceVect[option -1];
                if(entrancePtrV->getType() == EntranceType::RabatableDoor || 
                    entrancePtrV->getType() == EntranceType::RabatableWindow)
                    {
                        std::cout << "Choose new entrance state : \n";
                        if(entrancePtrV->getStatus() == Status::Closed)
                        {
                            std::cout << "1. Folded\n 2. Open\n";
                            int option;
                            std::cin >> option;
                            switch (option) {
                                case 1:
                                    entrancePtrV->setStatus(Status::Folded);
                                    // TODO: send msg to Server in this case
                                case 2:
                                    entrancePtrV->setStatus(Status::Open);
                                    // TODO: send msg to Server in this case
                                default:
                                    std::cout << "Invalid choice, no action was taken\n";
                            }
                        }
                        else if(entrancePtrV->getStatus() == Status::Folded)
                        {
                            std::cout << "1. Closed\n 2. Open\n";
                            int option;
                            std::cin >> option;
                            switch (option) {
                                case 1:
                                    entrancePtrV->setStatus(Status::Closed);
                                    // TODO: send msg to Server in this case
                                case 2:
                                    entrancePtrV->setStatus(Status::Open);
                                    // TODO: send msg to Server in this case
                                default:
                                    std::cout << "Invalid choice, no action was taken\n";
                            }
                        }
                        else { //open state
                            std::cout << "1. Folded\n 2. Closed\n";
                            int option;
                            std::cin >> option;
                            switch (option) {
                                case 1:
                                    entrancePtrV->setStatus(Status::Folded);
                                    // TODO: send msg to Server in this case
                                case 2:
                                    entrancePtrV->setStatus(Status::Closed);
                                    // TODO: send msg to Server in this case
                                default:
                                    std::cout << "Invalid choice, no action was taken\n";
                                }
                            }
                    }
                    else 
                    {
                        if(entrancePtrV->getStatus() == Status::Closed)
                        {
                            // TODO: send msg to Server in this case
                            entrancePtrV->setStatus(Status::Open);
                        }    
                        else
                        {
                            // TODO: send msg to Server in this case
                            entrancePtrV->setStatus(Status::Closed);
                        }        
                    }
            
        }
        return this;
        }


IPanel* PanelForChangeHouseLayout::exec()
        {
            std::cout << "-----------" << nameOfPanel << "-----------" << '\n';
            
            std::cout << (*house).toString();
            std::cout << display;
            int option;
            std::cin >> option;
            if(option >= availablePanels.size()) //a lso check if the option is of type int
            {
                std::cout << "Invalid input..\n";
                return availablePanels[0]; // all panels have an exit / back option on the 0th position
            }
            else
            {   
                return availablePanels[option];
            }
            
        }


IPanel* PanelForChangeHouseDetails::exec()
        {
            std::cout << "-----------" << nameOfPanel << "-----------" << '\n';
            
            std::cout << house->toString();
            std::cout << display;
            int option;
            std::cin >> option;

            if(option == 0)
            {
                return availablePanels[0];
            }
            else 
            {    
                switch (option) {
                    case 1:
                        {
                            std::cout << "\n Enter new country: ";
                            std::string newName;
                            std::cin >> newName; //TOOD validate input
                            house->setAddressCountry(newName);
                            //TODO send to server updata request
                            break;
                        }
                    case 2:
                        {
                            std::cout << "\n Enter new city: ";
                            std::string newName;
                            std::cin >> newName; //TOOD validate input
                            house->setAddressCity(newName);
                            //TODO send to server updata request
                            break;
                        }
                    case 3:
                        {
                            std::cout << "\n Enter new street name: ";
                            std::string newName;
                            std::cin >> newName; //TOOD validate input
                            house->setAddressStreet(newName);
                            //TODO send to server updata request
                            break;
                        }
                    case 4:
                        {
                        std::cout << "\n Enter new nr: ";
                            unsigned int nr;
                            std::cin >> nr; //TOOD validate input
                            house->setAddressNr(nr); 
                            //TODO send to server updata request
                            break;
                        }
                    default:
                        std::cout << "\nError..no action taken.\n";
                }
                return this;
            }
        }     


IPanel* PanelForChangeRooms::exec()
        {
            std::cout << "-----------" << nameOfPanel << "-----------" << '\n';
            
            for (const auto& room : house->getRooms())
            {
                std::cout << "Id: " << room.getId() << " Name: " << room.getName()
                << " Level: " << room.getLevel() << " Nr. of entrances: " << room.getEntrances().size() << '\n';
            }
            std::cout << "---------\n";
            std::cout << display;
            int option;
            std::cin >> option;
            if(option >= availablePanels.size()) //a lso check if the option is of type int
            {
                std::cout << "Invalid input..\n";
                return availablePanels[0]; // all panels have an exit / back option on the 0th position
            }
            else
            {   
                return availablePanels[option];
            }
            
        }

IPanel* PanelForAddRoom::exec()
        {
            std::cout << "-----------" << nameOfPanel << "-----------" << '\n';
            
            std::cout << "Name: ";
            std::string name;
            std::cin >> name;
            std::cout << "Level: ";
            int level;
            std::cin >> level;
            std::cout << "Entrances can be added from the \"Entrances\" panel\n";
            std::cout << "---------\n";
            Room room(name,level);
            std::cout << display;
            int option;
            std::cin >> option;
            if(option >= availablePanels.size()) //a lso check if the option is of type int
            {
                std::cout << "Invalid input..\n";
                return availablePanels[0]; // all panels have an exit / back option on the 0th position
            }
            else
            {   
                if(option == 1)
                {
                    house->addRoom(room);
                    cmd = "{add-room, id:" + std::to_string(room.getId()) +",name:" + room.getName() + ",level:" + std::to_string(room.getLevel()) + "}";
                    std::cout << "\nRoom added successfully..\n";
                }
                else if(option == 0){
                    std::cout << "\nOperation aborted..\n";
                }
                return availablePanels[option];
            }
            
        }


IPanel* PanelForChangeRoom::exec()
        {
            // TODO: This needs to be changed there are better ways to do this
            std::cout << "-----------" << nameOfPanel << "-----------" << '\n';
            std::cout << "Enter the Id of the room that needs to be changed:";
            unsigned int id;
            std::cin >> id;
            std::vector<Entrance*> auxEntr;
            bool found = false;
            for(const auto&  room : house->getRooms())
            {
                if(room.getId() == id)
                {
                    auxEntr = room.getEntrances();
                    found = true;
                }
            }
            if(found)
            {
                house->removeRoom(id);
                std::cout << "New name: ";
                std::string name;
                std::cin >> name;
                std::cout << "New Level: ";
                int level;
                std::cin >> level;
                std::cout << "Entrances can be changed from the \"Entrances\" panel\n";
                std::cout << "---------\n";
                Room room(name,level);
                std::cout << display;
                int option;
                std::cin >> option;
                if(option >= availablePanels.size()) //a lso check if the option is of type int
                {
                    std::cout << "Invalid input..\n";
                    return availablePanels[0]; // all panels have an exit / back option on the 0th position
                }
                else
                {   
                    if(option == 1)
                    {
                        house->addRoom(room);
                        cmd = "{change-room , id:" + std::to_string(id) +",new-name:" + room.getName() + ",new-level:" + std::to_string(room.getLevel()) + "}";
                        std::cout << "\nRoom changed successfully..\n";
                    }
                    else if(option == 0){
                        std::cout << "\nOperation aborted..\n";
                    }
                    return availablePanels[option];
                }
                
            }
            else {
            std::cout << "Id not found..\n";
            return this;
            }      
        }


IPanel* PanelForDeleteRoom::exec()
        {
            std::cout << "-----------" << nameOfPanel << "-----------" << '\n';
            
           std::cout << "Enter the Id of the room that needs to be changed:";
            unsigned int id;
            std::cin >> id;
            std::cout << "---------\n";
            std::cout << display;
            int option;
            std::cin >> option;
            if(option >= availablePanels.size()) //a lso check if the option is of type int
            {
                std::cout << "Invalid input..\n";
                return availablePanels[0]; // all panels have an exit / back option on the 0th position
            }
            else
            {   
                if(option == 1)
                {
                    house->removeRoom(id);
                    cmd = "{delete-room, id:" + std::to_string(id);
                    std::cout << "\nRoom deleted successfully..\n";
                }
                else if(option == 0){
                    std::cout << "\nOperation aborted..\n";
                }
                return availablePanels[option];
            }
            
        }