#include"ConcretePanels.hpp"

void Panel_Initial::run() {
  
    std::cout << '+' << std::string(11, '-') << "First Panel" << std::string(11, '-') << '+' << '\n';

    std::cout << "1.Check entrances.\n";
    std::cout << "2.Update house layout. \n";
    std::cout << "0.Exit\n";
    std::cout << '+' << std::string(33, '-') << '+' << '\n';
    
    int option;
    std::cin >> option;
    switch (option) {
        case 1:
            this->ui_->TransitionTo(new Panel_CheckEntrances);
            break;
        case 2:
            this->ui_->TransitionTo(new Panel_UpdateHouseLayout);
            break;
        case 3:
            // TOOD find a way to close the process when the users chooses to close the app. Maybe an exit panel ? 
            break;
        default:
            break;
    }
    
}


void Panel_CheckEntrances::run() {
 std::cout << '+' << std::string(11, '-') << "Check entrs" << std::string(11, '-') << '+' << '\n';

    std::cout << "1.Check rooms.\n";
    std::cout << "2.Check all entrances. \n";
    std::cout << "0.Back\n";
    std::cout << '+' << std::string(33, '-') << '+' << '\n';
    
    int option;
    std::cin >> option;
    switch (option) {
        case 1:
            this->ui_->TransitionTo(new Panel_CheckRooms);
            break;
        case 2:
            this->ui_->TransitionTo(new Panel_CheckAllEntrances);
            break;
        case 0:
            this->ui_->TransitionTo(new Panel_Initial);
            break;
        default:
            break;
    }
}

void Panel_UpdateHouseLayout::run() {
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
            this->ui_->TransitionTo(new Panel_test);
            break;
        case 2:
            this->ui_->TransitionTo(new Panel_test);
            break;
        case 3:
            this->ui_->TransitionTo(new Panel_test);
            break;
        case 4:
            this->ui_->TransitionTo(new Panel_test);
            break;
        case 5:
            this->ui_->TransitionTo(new Panel_test);
            break;
        case 6:
            this->ui_->TransitionTo(new Panel_test);
            break;
        case 7:
            this->ui_->TransitionTo(new Panel_test);
            break;    
        case 0:
            this->ui_->TransitionTo(new Panel_Initial);
            break;
        default:
            break;
    }
}

void Panel_CheckRooms::run() {
 std::cout << '+' << std::string(11, '-') << "Check rooms" << std::string(11, '-') << '+' << '\n';

    // TODO : function that gets the data from the server on the rooms of the house
    std::cout<< "--------- NOT IMPLEMENTED YET -----------\n";
    std::cout << "1.ROOM1.\n";
    std::cout << "2.ROOM2. \n";
    std::cout << "0.Back\n";
    std::cout << '+' << std::string(33, '-') << '+' << '\n';
    
    int option;
    std::cin >> option;
    switch (option) {
        case 1:
            // this->ui_->TransitionTo(new ConcretePanelB);
            break;
        case 2:
            // this->ui_->TransitionTo(new ConcretePanelC);
            break;
        case 0:
            this->ui_->TransitionTo(new Panel_CheckEntrances);
            break;
        default:
            break;
    }
}

void Panel_CheckAllEntrances::run() {
 std::cout << '+' << std::string(11, '-') << "Check allEn" << std::string(11, '-') << '+' << '\n';

    // TODO : function that gets the data from the server on the entrances of the house
    std::cout<< "--------- NOT IMPLEMENTED YET -----------\n";
    std::cout << "1.ROOM1.\n";
    std::cout << "2.ROOM2. \n";
    std::cout << "0.Back\n";
    std::cout << '+' << std::string(33, '-') << '+' << '\n';
    
    int option;
    std::cin >> option;
    switch (option) {
        case 1:
            // this->ui_->TransitionTo(new ConcretePanelB);
            break;
        case 2:
            // this->ui_->TransitionTo(new ConcretePanelC);
            break;
        case 0:
            this->ui_->TransitionTo(new Panel_CheckEntrances);
            break;
        default:
            break;
    }
}

void Panel_test::run() {
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
            // this->ui_->TransitionTo(new ConcretePanelB);
            break;
        case 2:
            // this->ui_->TransitionTo(new ConcretePanelC);
            break;
        case 0:
            this->ui_->TransitionTo(new Panel_UpdateHouseLayout);
            break;
        default:
            break;
    }
}