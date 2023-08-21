#include"ConcretePanels.hpp"
#include <vector>

void PanelInitial::run() {
  
    std::cout << '+' << std::string(11, '-') << "First Panel" << std::string(11, '-') << '+' << '\n';

    std::cout << "1.Check entrances.\n";
    std::cout << "2.Update house layout. \n";
    std::cout << "0.Exit\n";
    std::cout << '+' << std::string(33, '-') << '+' << '\n';
    
    std::cout << " \nTESTING: " << "house ID in initpanel" <<this->ui->getClient()->getHouse().getId() << '\n';
    int option;
    std::cin >> option;
    switch (option) {
        case 1:
            this->ui->TransitionTo(new PanelCheckEntrances);
            break;
        case 2:
            this->ui->TransitionTo(new PanelUpdateHouseLayout);
            break;
        case 3:
            // TOOD find a way to close the process when the users chooses to close the app. Maybe an exit panel ? 
            break;
        default:
            break;
    }
    
}


void PanelCheckEntrances::run() {
 std::cout << '+' << std::string(11, '-') << "Check entrs" << std::string(11, '-') << '+' << '\n';

    std::cout << "1.Check rooms.\n";
    std::cout << "2.Check all entrances. \n";
    std::cout << "0.Back\n";
    std::cout << '+' << std::string(33, '-') << '+' << '\n';
    
    int option;
    std::cin >> option;
    switch (option) {
        case 1:
            this->ui->TransitionTo(new PanelCheckRooms);
            break;
        case 2:
            this->ui->TransitionTo(new PanelCheckAllEntrances);
            break;
        case 0:
            this->ui->TransitionTo(new PanelCheckAllEntrances);
            break;
        default:
            break;
    }
}

void PanelUpdateHouseLayout::run() {
  std::cout << '+' << std::string(11, '-') << "Update Haus" << std::string(11, '-') << '+' << '\n';

    std::cout << "1.Add room.\n";
    std::cout << "2.Delete room.\n";
    std::cout << "3.Rename room.\n";
    std::cout << "4.Add entrance.\n";
    std::cout << "5.Delete entrace.\n";
    std::cout << "6.Delete entrace.\n";
    std::cout << "7.Show current house Layout.\n";
    std::cout << "0.Back\n";
    std::cout << '+' << std::string(33, '-') << '+' << '\n';
    
    int option;
    std::cin >> option;
    switch (option) {
        case 1:
            this->ui->TransitionTo(new PanelTest);
            break;
        case 2:
            this->ui->TransitionTo(new PanelTest);
            break;
        case 3:
            this->ui->TransitionTo(new PanelTest);
            break;
        case 4:
            this->ui->TransitionTo(new PanelTest);
            break;
        case 5:
            this->ui->TransitionTo(new PanelTest);
            break;
        case 6:
            this->ui->TransitionTo(new PanelTest);
            break;
        case 7:
            this->ui->TransitionTo(new PanelTest);
            break;    
        case 0:
            this->ui->TransitionTo(new PanelCheckAllEntrances);
            break;
        default:
            break;
    }
}

void PanelCheckRooms::run() {
 std::cout << '+' << std::string(11, '-') << "Check rooms" << std::string(11, '-') << '+' << '\n';

    std::cout << "Rooms : \n";
    std::cout << "here1\n";
    auto vect = ui->getClient()->getHouse().getRooms();
    std::cout << "here2\n";
    int i = 1;
    for (auto room : vect)
    {
        std::cout << "=========================\n";
        std::cout <<i<<". "<< room.getName() << '\n';
        std::cout << "=========================\n";
        i++;
    }

    std::cout << "0. Back\n";
    std::cout << '+' << std::string(33, '-') << '+' << '\n';
    
    int option;
    std::cin >> option;
    if(option == 0)
    {
        this->ui->TransitionTo(new PanelCheckEntrances);
    }
    else if(option > 0 && option <= i)
    {
        this->ui->TransitionTo(new PanelRoom(vect[i-1]));
    }

}

void PanelCheckAllEntrances::run() {
 std::cout << '+' << std::string(11, '-') << "Check all Entrances" << std::string(11, '-') << '+' << '\n';

    std::cout<< "--------- NOT IMPLEMENTED YET -----------\n";
    std::cout << "1.ROOM1.\n";
    std::cout << "2.ROOM2. \n";
    std::cout << "0.Back\n";
    std::cout << '+' << std::string(33, '-') << '+' << '\n';
    
    int option;
    std::cin >> option;
    switch (option) {
        case 1:
            // this->ui->TransitionTo(new ConcretePanelB);
            break;
        case 2:
            // this->ui->TransitionTo(new ConcretePanelC);
            break;
        case 0:
            this->ui->TransitionTo(new PanelCheckEntrances);
            break;
        default:
            break;
    }
}

void PanelTest::run() {
 std::cout << '+' << std::string(11, '-') << "Panel test " << std::string(11, '-') << '+' << '\n';

    // TODO : function that gets the data from the server on the entrances of the house
    std::cout<< "--------- NOT IMPLEMENTED YET -----------\n";
    std::cout << "1.Option1.\n";
    std::cout << "2.Option2. \n";
    std::cout << "0.Back\n";
    std::cout << '+' << std::string(33, '-') << '+' << '\n';
    
    int option;
    std::cin >> option;
    switch (option) {
        case 1:
            // this->ui->TransitionTo(new ConcretePanelB);
            break;
        case 2:
            // this->ui->TransitionTo(new ConcretePanelC);
            break;
        case 0:
            this->ui->TransitionTo(new PanelUpdateHouseLayout);
            break;
        default:
            break;
    }
}

PanelRoom::PanelRoom(const Room& room)
{
    roomPtr = &room;
}


void PanelRoom::run()
{

 std::cout << '+' << std::string(11, '-') << roomPtr->getName() << std::string(11, '-') << '+' << '\n';

    std::vector<Entrance> entrances = roomPtr->getEntrances();
    bool isClosed = true;
    for (auto entrance : entrances)
    {
        if(entrance.getStatus() == Status::Open ||
            entrance.getStatus() == Status::Folded)
                isClosed = false;
    }
    std::cout << "Room status: " << (isClosed ? "closed" : "open") << '\n';
    std::cout << "1." << (isClosed ? "Mark room as open" : "Mark room as closed");
    std::cout << "2.Check the status of the entrances. \n";
    std::cout << "0.Back\n";
    std::cout << '+' << std::string(33, '-') << '+' << '\n';

    int option;
    std::cin >> option;
    switch (option) {
        case 0:
            this->ui->TransitionTo(new PanelCheckRooms);
            break;
        case 1:
            // TODO - function to make all entrances open / closed
            break;
        case 2:
            std::cout << "\n Entrances status : \n";
            for (auto entrance : entrances)
            {
                std::cout << entrance << '\n';
            }
            std::cout << "1." << (isClosed ? "Mark room as open" : "Mark room as closed");
            std::cout << "0.Back\n";
        default:
            break;
    }
}