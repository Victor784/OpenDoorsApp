#include"../src/Connection/Connection.hpp"
#include "../src/Client/Client.hpp"
#include "../src/UI/ConcretePanels.hpp"
#include "../src/Repo/House.hpp"

#include <chrono>
#include <memory>
#include <thread>
#include <vcruntime_typeinfo.h>
#include <vector>




void ClientCode() {
  Ui *ui = new Ui(new PanelInitial, "");

  ui->run();
  
  delete ui;
}
   










int main()
{
    // -----------------------------CONNECTION TESTING--------------------------------------------------
    std::string outGoingPipe = "C:/Users/victo/Desktop/ProjectsCPP/MiniClientServer/ClientServerPipe.txt"; 
    std::string inGoingPipe = "C:/Users/victo/Desktop/ProjectsCPP/MiniClientServer/ServerClientPipe.txt";
    Pipe p(outGoingPipe, inGoingPipe);
    Connection c(p);
    Ui *ui = new Ui(new PanelInitial, "");

    Entrance entrance1(EntranceType::Door, Position::East, Status::Closed);

    Entrance entrance2(EntranceType::Window, Position::East, Status::Closed);

    std::vector<Entrance> vect;
    vect.push_back(entrance1);
    vect.push_back(entrance2);
    Room room1("Bucatarie" , 1, vect);
    Room room2("Dormitor" , 1);
    House h1;
    h1.addRoom(room1);
    h1.addRoom(room2);
    Client cl(c, *ui,h1);

    std::cout << "MAIn>>>>>>>>>>>>>>>>House ID: " << h1.getId() << '\n';

    // while(true)
    // {
        
    //     std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    //     cl.connection.write("ClientInput");
    //     std::cout << "from pipe  "<< cl.connection.read();
    // }

    // ---------------------------UI TESTING--------------------------------
    ClientCode();
    
    // ---------------------------REPO TESTING---------------------------

    
//     std::cout << "Type : " << toString(entrance1.getType()) << '\n';
//     std::cout << "Position : " << toString(entrance1.getPosition()) << '\n';
//     std::cout << "Status : " << toString(entrance1.getStatus()) << '\n';

//     entrance1.setStatus(Status::Open);
//     entrance1.setType(EntranceType::Window);
//     entrance1.setPosition(Position::North);

//     std::cout << "Type : " << toString(entrance1.getType()) << '\n';
//     std::cout << "Position : " << toString(entrance1.getPosition()) << '\n';
//     std::cout << "Status : " << toString(entrance1.getStatus()) << '\n';

//     std::cout << "entrance1 Id : " << entrance1.getId() << '\n';
//     std::cout << "entrance2 Id : " << entrance2.getId() << '\n';

   

    
//     std::cout << "Id : " << room1.getId() << '\n';
//     std::cout << "Room name : " << room1.getName() << "\n";
//     std::cout << "Room level : " << room1.getLevel() << "\n";
//     std::cout << "Entrances: ";

//     for (const auto &entrance : room1.getEntrances())
//     {
//       std::cout << entrance << " ; ";
//     }
//     std::cout << '\n';

   
//     std::cout << "Id : " << room2.getId() << '\n';
//     std::cout << "Room name : " << room2.getName() << "\n";
//     std::cout << "Room level : " << room2.getLevel() << "\n";
//     std::cout << "Entrances: ";

//     for (const auto &entrance : room2.getEntrances())
//     {
//       std::cout << entrance << " ; ";
//     }
//     std::cout << '\n';

    // room2.addEntrance(entrance2);
    // room2.addEntrance(entrance1);

//     for (const auto &entrance : room2.getEntrances())
//     {
//       std::cout << entrance << " ; ";
//     }
//     std::cout << '\n';

//     room2.removeEntrance(entrance1.getId());

//     std::cout << "AFTER REMOVAL \n";

//      for (const auto &entrance : room2.getEntrances())
//     {
//       std::cout << entrance << " ; ";
//     }
//     std::cout << '\n';

//     room2.setName("test");
//     room2.setLevel(-1);
//     room2.setEntrances(vect);

//     std::cout << "\n\n***********AFTER SETS****************\n\n";

//     std::cout << "Id : " << room2.getId() << '\n';
//     std::cout << "Room name : " << room2.getName() << "\n";
//     std::cout << "Room level : " << room2.getLevel() << "\n";
//     std::cout << "Entrances: ";

//     for (const auto &entrance : room2.getEntrances())
//     {
//       std::cout << entrance << " ; ";
//     }
//     std::cout << '\n';
    
//     unsigned int val = 5;
//     room2.removeEntrance(val);
// std::cout << "\n\n***********WRONG ID REMOVAL TEST AFTER****************\n\n";

//      for (const auto &entrance : room2.getEntrances())
//     {
//       std::cout << entrance << " ; ";
//     }
    // 

    // std::cout << "house1 Id : " << h1.getId();

    // House h2;



    return 0;

}