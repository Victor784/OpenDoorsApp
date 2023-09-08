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

    House house {adr, vectRoom};

    
    
    
    PanelForOptionDisplay PanelConfirm("Confirmation Panel","", false, "");
    PanelForOptionDisplay PanelAbort("Abort Panel", "", false, "");

    PanelForOptionDisplay PanelExit("Exit Panel" , "....EXITING.....\n", false, "");

    PanelForOptionDisplay PanelInit("PanelInit", " 1.Change house layout\n 2.Check entrances \n 0.Exit\n", false, "");

    PanelForChangeHouseLayout PanelChangeHouseLayout("House layout", " 1.House details\n 2.Rooms\n 3.Entrances\n 0.Back\n", false, "", &house);

    PanelForListAllEntrances PanelListAllEntrances("All entrances " , " 0.Back\n" , false , "" , &house);

    PanelForChangeHouseDetails PanelForChangeHouseDetails("House details" , " 1.Change country\n 2.Change city\n 3.Change street\n 4.Change nr\n 0.Back\n", false, "" , &house );

    PanelForChangeRooms PanelForChangeRooms("Rooms", " 1.Add room\n 2.Delete room\n 3.Change room\n 0.Back\n", false, "", &house);
    
    PanelForAddRoom PanelForAddRoom("Add room", " 1.Confirm\n 2.Abort\n", true, "" , &house);

    PanelForChangeRoom PanelForChangeRoom("Change room",  " 1.Confirm\n 2.Abort\n", true, "" , &house);

    PanelForDeleteRoom PanelForDeleteRoom("Delete room", " 1.Confirm\n 2.Abort\n", true, "" , &house);

    
    PanelForChangeEntrances PanelForChangeEntrances("Entrances", " 1.Add entrance\n 2.Change entrance\n 3.Delete entrance\n 0.Back\n", false, "", &house);
    
    PanelForAddEntrance PanelForAddEntrance("Add entrance", " 1.Confirm\n 2.Abort\n", true, "" , &house);


    PanelForDeleteEntrance PanelForDeleteEntrance("Delete entrance", " 1.Confirm\n 2.Abort\n", true, "" , &house);


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

    UI s(initPanelPtr, "", &house);

    s.run();

    return 0;

}
