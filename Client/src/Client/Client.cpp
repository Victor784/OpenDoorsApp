#pragma once

#include"Client.hpp"

// inline void Client::sendCmd(std::string cmd)
// {
//     std::cout << "From sendCmd of Client : " << cmd << '\n';
//     connection.connect();
//     connection.write(cmd);
// }

namespace connection {



void Client::run()
{
    Entrance entrance1(EntranceType::Door, Position::East, Status::Closed);

    Entrance entrance2(EntranceType::Window, Position::West, Status::Closed);


    Entrance entrance3(EntranceType::Door, Position::North, Status::Closed);

    Entrance entrance4(EntranceType::Door, Position::South, Status::Closed);


    std::vector<Entrance> vect;
    vect.push_back(entrance1);
    vect.push_back(entrance2);


    std::vector<Entrance> vect2;
    vect2.push_back(entrance3);
    vect2.push_back(entrance4);

    Room room1("Bucatarie" , 1, vect);
    Room room2("Dormitor" , 1 , vect2);
    
    Address adr {10, 0, "Ciresilor", "Cluj-Napoca"};

    std::vector<Room> vectRoom;
    vectRoom.push_back(room1);
    vectRoom.push_back(room2);

    house.setAddress(adr);
    house.setRooms(vectRoom);
    
    
    PanelForOptionDisplay PanelConfirm("Confirmation Panel","", false, "");
    PanelForOptionDisplay PanelAbort("Abort Panel", "", false, "");

    PanelForOptionDisplay PanelExit("Exit Panel" , "....EXITING.....\n", false, "");

    PanelForOptionDisplay PanelInit("PanelInit", " 1.Change house layout\n 2.Check entrances \n 0.Exit\n", false, "");

    PanelForChangeHouseLayout PanelChangeHouseLayout(&house);
    PanelForListAllEntrances PanelListAllEntrances(&house);

    PanelForChangeHouseDetails PanelForChangeHouseDetails(&house );

    PanelForChangeRooms PanelForChangeRooms(&house);
    
    PanelForAddRoom PanelForAddRoom(&house);

    PanelForChangeRoom PanelForChangeRoom(&house);

    PanelForDeleteRoom PanelForDeleteRoom(&house);

    
    PanelForChangeEntrances PanelForChangeEntrances(&house);
    
    PanelForAddEntrance PanelForAddEntrance( &house);


    PanelForDeleteEntrance PanelForDeleteEntrance(&house);

    PanelForChangeEntrance PanelForChangeEntrance(&house);

    IPanel* panelChangeEntrancePtr = &PanelForChangeEntrance;
    IPanel* panelDeleteEntrancePtr = &PanelForDeleteEntrance;
    IPanel* initPanelPtr = &PanelInit;
    IPanel* panelChangeHouseLayoutPtr = &PanelChangeHouseLayout;
    IPanel* panelExitPtr = &PanelExit;
    IPanel* panelConfirmPtr = &PanelConfirm;
    IPanel* panelAbortPtr = &PanelAbort;
    IPanel* panelListAllEntrancesPtr = &PanelListAllEntrances;
    IPanel* panelForChangeHouseDetailsPtr = &PanelForChangeHouseDetails;
    IPanel* panelForChangeRoomsPtr = &PanelForChangeRooms;
    IPanel* panelForAddRoomPtr = &PanelForAddRoom;
    IPanel* panelForChangeRoomPtr = &PanelForChangeRoom;
    IPanel* panelForDeleteRoomPtr = &PanelForDeleteRoom;
    IPanel* panelForChangeEntrancesPtr =  &PanelForChangeEntrances;
    IPanel* panelForAddEntrancePtr = &PanelForAddEntrance;

    std::vector<IPanel*> vectPanelForChangeEntrance;
    vectPanelForChangeEntrance.push_back(panelForChangeEntrancesPtr);
    vectPanelForChangeEntrance.push_back(panelConfirmPtr);
    vectPanelForChangeEntrance.push_back(panelAbortPtr);

    std::vector<IPanel*> vectPanelForDeleteEntrance;
    vectPanelForDeleteEntrance.push_back(panelForChangeEntrancesPtr);
    vectPanelForDeleteEntrance.push_back(panelConfirmPtr);
    vectPanelForDeleteEntrance.push_back(panelAbortPtr);

    std::vector<IPanel*> vectPanelForAddEntrance;
    vectPanelForAddEntrance.push_back(panelForChangeEntrancesPtr);
    vectPanelForAddEntrance.push_back(panelConfirmPtr);
    vectPanelForAddEntrance.push_back(panelAbortPtr);

    std::vector<IPanel*> vectPanelForChangeEntrances;
    vectPanelForChangeEntrances.push_back(panelChangeHouseLayoutPtr);
    vectPanelForChangeEntrances.push_back(panelForAddEntrancePtr);
    vectPanelForChangeEntrances.push_back(panelDeleteEntrancePtr);
    vectPanelForChangeEntrances.push_back(panelChangeEntrancePtr);

    std::vector<IPanel*> vectPanelForDeleteRoom;
    vectPanelForDeleteRoom.push_back(panelForChangeRoomsPtr);
    vectPanelForDeleteRoom.push_back(panelConfirmPtr);
    vectPanelForDeleteRoom.push_back(panelAbortPtr);

    std::vector<IPanel*> vectPanelForChangeRoom;
    vectPanelForChangeRoom.push_back(panelForChangeRoomsPtr);
    vectPanelForChangeRoom.push_back(panelConfirmPtr);
    vectPanelForChangeRoom.push_back(panelAbortPtr);

    std::vector<IPanel*> vectPanelForAddRoom;
    vectPanelForAddRoom.push_back(panelForChangeRoomsPtr);
    vectPanelForAddRoom.push_back(panelConfirmPtr);
    vectPanelForAddRoom.push_back(panelAbortPtr);

    std::vector<IPanel*> vectPanelForChengeRooms;
    vectPanelForChengeRooms.push_back(panelChangeHouseLayoutPtr);
    vectPanelForChengeRooms.push_back(panelForAddRoomPtr);
    vectPanelForChengeRooms.push_back(panelForChangeRoomPtr);
    vectPanelForChengeRooms.push_back(panelForDeleteRoomPtr);
   

    std::vector<IPanel*> vectPanelForChangeHouseDetails;
    vectPanelForChangeHouseDetails.push_back(panelChangeHouseLayoutPtr);

    std::vector<IPanel*> vectForPanelListAllEntrances;
    vectForPanelListAllEntrances.push_back(initPanelPtr);

    std::vector<IPanel*> vectForPanelInit;
    vectForPanelInit.push_back(panelExitPtr);
    vectForPanelInit.push_back(panelChangeHouseLayoutPtr);
    vectForPanelInit.push_back(panelListAllEntrancesPtr);



    std::vector<IPanel*> vectForpanelChangeHouseLayout;
    vectForpanelChangeHouseLayout.push_back(initPanelPtr);
    vectForpanelChangeHouseLayout.push_back(panelForChangeHouseDetailsPtr); 
    vectForpanelChangeHouseLayout.push_back(panelForChangeRoomsPtr);
    vectForpanelChangeHouseLayout.push_back(panelForChangeEntrancesPtr);
    
   
    
    
    initPanelPtr->setAvailablePanels(vectForPanelInit);
    panelChangeHouseLayoutPtr->setAvailablePanels(vectForpanelChangeHouseLayout);

    panelListAllEntrancesPtr->setAvailablePanels(vectForPanelListAllEntrances);
    panelForChangeHouseDetailsPtr->setAvailablePanels(vectPanelForChangeHouseDetails);
    PanelForChangeRooms.setAvailablePanels(vectPanelForChengeRooms);
    panelForAddRoomPtr->setAvailablePanels(vectPanelForAddRoom);
    panelForChangeRoomPtr->setAvailablePanels(vectPanelForChangeRoom);
    panelForDeleteRoomPtr->setAvailablePanels(vectPanelForDeleteRoom);
    panelForChangeEntrancesPtr->setAvailablePanels(vectPanelForChangeEntrances);
    panelForAddEntrancePtr->setAvailablePanels(vectPanelForAddEntrance);
    panelDeleteEntrancePtr->setAvailablePanels(vectPanelForDeleteEntrance);
    panelChangeEntrancePtr->setAvailablePanels(vectPanelForChangeEntrance);

    // UI s(initPanelPtr, "", &house);
        //ui = s;
    ui.currentPanel = initPanelPtr;
    ui.cmd = "";
    ui.house = &house;




    while(ui.currentPanel->getNameOfPanel() != "Exit Panel")
    {
        connection.connect_();
        std::cout << "From client.run() - ui.cmd : " << ui.cmd << '\n';
        connection.write_(ui.cmd);

        ui.cmd = "";
        ui.run();
    }
    connection.disconnect_();
    
}
}