#include "ConcretePanels.hpp"
#include <memory>
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
            int counter = 1; // TODO you can use i to display what you want in before each entrace
            std::vector<unsigned int> optionEntranceIdMap; // here vector is used as a map with key int (meaning the option) and the value is the entrance id;
            for(int i = 0; i < repoPtr->getRooms().size(); i ++ )
            
            {
                std::cout <<"-->" << (*repoPtr).getRooms()[i].getName() << '\n';
                    for(int j =0; j< (*repoPtr).getRooms()[i].getEntrances().size(); j++)
                    {
                        std::cout << "    " << counter ++ << '.' << (*repoPtr).getRooms()[i].getEntrances()[j] << '\n';
                        optionEntranceIdMap.push_back((*repoPtr).getRooms()[i].getEntrances()[j].getId());
                    }
            }
            
            
            std::cout << "Change the status of an entrance by pressing the number asociated with it: \n";
            std::cout << display;
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
                repoPtr->changeEntranceStatus(optionEntranceIdMap[option-1]);
                cmd = "{switch-status, entrance-id:" + std::to_string(optionEntranceIdMap[option-1]) + "}";
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
            std::vector<Entrance> auxEntr;
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
                std::cout << "New name: ";
                std::string name;
                std::cin >> name;
                std::cout << "New Level: ";
                std::string level;
                std::cin >> level;
                std::cout << "Entrances can be changed from the \"Entrances\" panel\n";
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
                        house->changeRoom(id, name, level);
                        cmd = "{change-room , id:" + std::to_string(id) +",new-name:" + name + ",new-level:" + level + "}";
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
            
            std::cout << "Enter the Id of the room that needs to be deleted:";
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


IPanel* PanelForChangeEntrances::exec()
        {
            std::cout << "-----------" << nameOfPanel << "-----------" << '\n';
            
            for (const auto& room : house->getRooms())
            {
                std::cout << "--> " << room.getName()<< " Id: " << room.getId() <<  '\n';
                for(auto entrace : room.getEntrances())
                    {
                        std::cout << "    " << entrace << '\n';
                    }
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


IPanel* PanelForAddEntrance::exec()
        {
            std::cout << "-----------" << nameOfPanel << "-----------" << '\n';
            
            std::cout << "Emter the id of the room that you want to add the entrance to: ";
            unsigned int id;
            std::cin >> id;

            std::cout << "Select type of entrance: \n";
            std::cout << " 1. Window\n";
            std::cout << " 2. Foldable window\n";
            std::cout << " 3. Door\n";
            std::cout << " 4. Foldable door\n";
            int type;
            std::cin>> type;
            EntranceType enType;
            switch (type) {
                case 1:
                    enType = EntranceType::Window;
                    break;
                case 2:
                    enType = EntranceType::RabatableWindow;
                    break;
                case 3:
                    enType = EntranceType::Door;
                    break;
                case 4:
                    enType = EntranceType::RabatableDoor;
                    break;
                default:
                    {
                        std::cout << "\nInvalid choice...\n";
                        return this;
                    }
            }
            std::cout << "Select position of entrance: \n";
            std::cout << " 1. East\n";
            std::cout << " 2. North\n";
            std::cout << " 3. South\n";
            std::cout << " 4. West\n";
            int pos;
            std::cin>> pos;
            Position position;
            switch (pos) {
                case 1:
                    position = Position::East;
                    break;
                case 2:
                    position = Position::North;
                    break;
                case 3:
                    position = Position::South;
                    break;
                case 4:
                    position = Position::West;
                    break;
                default:
                    {
                        std::cout << "\nInvalid choice...\n";
                        return this;
                    }
            }
            std::unique_ptr<Entrance> entrance = std::make_unique<Entrance>(enType, position, Status::Closed); 
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
                    house->addEntrance(id,std::move(*entrance));
                    cmd = "{add-entrance, room-id:" + std::to_string(id) +",type:" + utils::toString(enType) + ",position:" + utils::toString(position) + "}";
                    std::cout << "\nRoom added successfully..\n";
                }
                else if(option == 0){
                    std::cout << "\nOperation aborted..\n";
                }
                return availablePanels[option];
            }
            
        }

IPanel* PanelForDeleteEntrance::exec()
        {
        std::cout << "-----------" << nameOfPanel << "-----------" << '\n';
            
            std::cout << "Enter the Id of the entrance that needs to be deleted:";
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
                    house->removeEntrance(id);
                    cmd = "{delete-entrance, id:" + std::to_string(id);
                    std::cout << "\nEntrance deleted successfully..\n";
                }
                else if(option == 0){
                    std::cout << "\nOperation aborted..\n";
                }
                return availablePanels[option];
            }
            
        }

IPanel* PanelForChangeEntrance::exec()
        {
             std::cout << "-----------" << nameOfPanel << "-----------" << '\n';
            
            std::cout << "Enter the id of  the entrance  you want to change: ";
            unsigned int id;
            std::cin >> id;
            bool found = false;
            for (const auto& room : house->getRooms())
            {
                for(auto entrace : room.getEntrances())
                    {
                        if(entrace.getId() == id)
                            found = true;
                    }
            }
            if(!found)
            {
                std::cout << "Id not found..\n";
                return this;
            }
                
            std::cout << "Select type of entrance: \n";
            std::cout << " 1. Window\n";
            std::cout << " 2. Foldable window\n";
            std::cout << " 3. Door\n";
            std::cout << " 4. Foldable door\n";
            int type;
            std::cin>> type;
            EntranceType enType;
            switch (type) {
                case 1:
                    enType = EntranceType::Window;
                    break;
                case 2:
                    enType = EntranceType::RabatableWindow;
                    break;
                case 3:
                    enType = EntranceType::Door;
                    break;
                case 4:
                    enType = EntranceType::RabatableDoor;
                    break;
                default:
                    {
                        std::cout << "\nInvalid choice...\n";
                        return this;
                    }
            }
            std::cout << "Select position of entrance: \n";
            std::cout << " 1. East\n";
            std::cout << " 2. North\n";
            std::cout << " 3. South\n";
            std::cout << " 4. West\n";
            int pos;
            std::cin>> pos;
            Position position;
            switch (pos) {
                case 1:
                    position = Position::East;
                    break;
                case 2:
                    position = Position::North;
                    break;
                case 3:
                    position = Position::South;
                    break;
                case 4:
                    position = Position::West;
                    break;
                default:
                    {
                        std::cout << "\nInvalid choice...\n";
                        return this;
                    }
            }
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
                    for (const auto& room : house->getRooms())
                    {
                        for(auto entrace : room.getEntrances())
                            {
                                if(entrace.getId() == id)
                                    std::cout << "\n ChangeEntrancePanel before type : " << utils::toString(entrace.getType()) << '\n';

                            }
                    }
                    house->changeEntrance(id,enType, position);
                     for (const auto& room : house->getRooms())
                    {
                        for(auto entrace : room.getEntrances())
                            {
                                if(entrace.getId() == id)
                                    std::cout << "\n ChangeEntrancePanel after type : " << utils::toString(entrace.getType()) << '\n';

                            }
                    }
                    cmd = "{change-entrance, id:" + std::to_string(id) +",new-type:" + utils::toString(enType) + ",new-position:" + utils::toString(position) + "}";
                    std::cout << "\n Entrance changed successfully..\n";
                }
                else if(option == 0){
                    std::cout << "\nOperation aborted..\n";
                }
                return availablePanels[option];
            }
            
        }