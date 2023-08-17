#include"../src/Connection/Connection.hpp"
#include "../src/Client/Client.hpp"
#include "../src/UI/ConcretePanels.hpp"
#include <chrono>
#include <memory>
#include <thread>









// void ClientCode() {
//   Ui *ui = new Ui(new Panel_Initial);

//   ui->run();
  
//   delete ui;
// }
   










int main()
{
    // std::string outGoingPipe = "C:/Users/victo/Desktop/ProjectsCPP/MiniClientServer/ClientServerPipe.txt"; 
    // std::string inGoingPipe = "C:/Users/victo/Desktop/ProjectsCPP/MiniClientServer/ServerClientPipe.txt";
    // Pipe p(outGoingPipe, inGoingPipe);
    // Connection c(p);
    // Client cl(c);
    
    // while(true)
    // {
        
    //     std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    //     cl.connection.write("ClientInput");
    //     std::cout << "from pipe  "<< cl.connection.read();
    // }
    ClientCode();
    return 0;

}