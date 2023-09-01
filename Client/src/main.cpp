#include"../src/Connection/Connection.hpp"
#include "../src/Client/Client.hpp"

#include <chrono>
#include <memory>
#include <thread>
#include <vcruntime_typeinfo.h>
#include <vector>


int main()
{   
    Entrance entrance1(EntranceType::Door, Position::East, Status::Closed);

    Entrance entrance2(EntranceType::Window, Position::West, Status::Closed);


    Entrance entrance3(EntranceType::Door, Position::North, Status::Closed);

    Entrance entrance4(EntranceType::Door, Position::South, Status::Closed);


    std::vector<Entrance*> vect;
    vect.push_back(&entrance1);
    vect.push_back(&entrance2);

    std::vector<Entrance*> vect2;
    vect2.push_back(&entrance3);
    vect2.push_back(&entrance4);

    Room room1("Bucatarie" , 1, vect);
    Room room2("Dormitor" , 1 , vect2);
    
    Address adr {10, 0, "Ciresilor", "Cluj-Napoca"};

    std::vector<Room> vectRoom;
    vectRoom.push_back(room1);
    vectRoom.push_back(room2);

    House house {adr, vectRoom};

    
    
    
    PanelForOptionDisplay PanelConfirm("Confirmation Panel","", false, "");
    PanelForOptionDisplay PanelAbort("Abort Panel", "", false, "");

    PanelForOptionDisplay PanelExit("Exit Panel" , "....EXITING.....\n", false, "");

    PanelForOptionDisplay PanelInit("PanelInit", " 1.Panel 1\n 2.Change house layout\n 3.Check entrances \n 0.Exit\n", false, "");

    PanelForOptionDisplay Panel1("Panel 1", " 1.Panel 1.1\n 2.Panel 1.2\n 0.Back", false, "");

    PanelForChangeHouseLayout PanelChangeHouseLayout("House layout", " 1.House details\n 2.Rooms\n 3.Entrances\n 0.Back\n", false, "", &house);

    PanelForOptionDisplay Panel1_1("Panel1_1", " Final Panel\n 0.Back\n 1.send \n 2.abort\n", true, "cmd from pnl1_1");

    PanelForOptionDisplay Panel1_2("Panel1_2", " Final Panel\n 0.Back\n 1.send \n 2.abort\n", true, "cmd from pnl1_2");

    PanelForListAllEntrances PanelListAllEntrances("All entrances " , " 0.Back\n" , false , "" , &house);

    PanelForChangeHouseDetails PanelForChangeHouseDetails("House details" , " 1.Change country\n 2.Change city\n 3.Change street\n 4.Change nr\n 0.Back\n", false, "" , &house );

    PanelForChangeRooms PanelForChangeRooms("Rooms", " 1.Add room\n 2.Change room\n 3.Delete room\n 0.Back\n", false, "", &house);
    
    PanelForAddRoom PanelForAddRoom("Add room", " 1.Confirm\n 2.Abort\n", true, "" , &house);

    PanelForChangeRoom PanelForChangeRoom("Change room",  " 1.Confirm\n 2.Abort\n", true, "" , &house);

    PanelForDeleteRoom PanelForDeleteRoom("Delete room", " 1.Confirm\n 2.Abort\n", true, "" , &house);

    IPanel* initPanelPtr = &PanelInit;
    IPanel* panel1Ptr = &Panel1;
    IPanel* panelChangeHouseLayoutPtr = &PanelChangeHouseLayout;
    IPanel* panel1_1Ptr = &Panel1_1;
    IPanel* panel1_2Ptr = &Panel1_2;
    IPanel* panelExitPtr = &PanelExit;
    IPanel* panelConfirmPtr = &PanelConfirm;
    IPanel* panelAbortPtr = &PanelAbort;
    IPanel* panelListAllEntrancesPtr = &PanelListAllEntrances;
    IPanel* panelForChangeHouseDetailsPtr = &PanelForChangeHouseDetails;
    IPanel* panelForChangeRoomsPtr = &PanelForChangeRooms;
    IPanel* panelForAddRoomPtr = &PanelForAddRoom;
    IPanel* panelForChangeRoomPtr = &PanelForChangeRoom;
    IPanel* panelForDeleteRoomPtr = &PanelForDeleteRoom;


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
    vectForPanelInit.push_back(panel1Ptr);
    vectForPanelInit.push_back(panelChangeHouseLayoutPtr);
    vectForPanelInit.push_back(panelListAllEntrancesPtr);

    std::vector<IPanel*> vectForPanel1;
    vectForPanel1.push_back(initPanelPtr);
    vectForPanel1.push_back(panel1_1Ptr);
    vectForPanel1.push_back(panel1_2Ptr);

    std::vector<IPanel*> vectForpanelChangeHouseLayout;
    vectForpanelChangeHouseLayout.push_back(initPanelPtr);
    vectForpanelChangeHouseLayout.push_back(panelForChangeHouseDetailsPtr); 
    vectForpanelChangeHouseLayout.push_back(panelForChangeRoomsPtr);
    
   
    
    std::vector<IPanel*> vectForPanel1_1;
    vectForPanel1_1.push_back(panel1Ptr);
    vectForPanel1_1.push_back(panelConfirmPtr);
    vectForPanel1_1.push_back(panelAbortPtr);

    std::vector<IPanel*> vectForPanel1_2;
    vectForPanel1_2.push_back(panel1Ptr);
    vectForPanel1_2.push_back(panelConfirmPtr);
    vectForPanel1_2.push_back(panelAbortPtr);
    
    initPanelPtr->setAvailablePanels(vectForPanelInit);
    panel1Ptr->setAvailablePanels(vectForPanel1);
    panelChangeHouseLayoutPtr->setAvailablePanels(vectForpanelChangeHouseLayout);

    panel1_1Ptr->setAvailablePanels(vectForPanel1_1);
    panel1_2Ptr->setAvailablePanels(vectForPanel1_2);
    panelListAllEntrancesPtr->setAvailablePanels(vectForPanelListAllEntrances);
    panelForChangeHouseDetailsPtr->setAvailablePanels(vectPanelForChangeHouseDetails);
    PanelForChangeRooms.setAvailablePanels(vectPanelForChengeRooms);
    panelForAddRoomPtr->setAvailablePanels(vectPanelForAddRoom);
    panelForChangeRoomPtr->setAvailablePanels(vectPanelForChangeRoom);
    panelForDeleteRoomPtr->setAvailablePanels(vectPanelForDeleteRoom);


    UI s(initPanelPtr, "", &house);

    s.run();

    return 0;

}
