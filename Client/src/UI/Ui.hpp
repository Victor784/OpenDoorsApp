#pragma once

#include"Panel.hpp"
#include"../Client/Client.hpp"
#include <string>


class Client;
/**
 * The Ui defines the interface of interest to clients. It also maintains a
 * reference to an instance of a Panel subclass, which represents the current
 * panel of the Ui. THIS METHOD RELLIES HEAVEALY ON PANEL CONSTRUCTORS AND DESCTRUCTORS, WHILE USING RAW POINTERS. A BETTER METHOD MIGHT BE NEEDED IN THE FUTURE
 */
class Ui {

 private:
  Panel *panel;
  std::string cmd = "";
  Client* client;

 public:
  Ui(Panel *panelVal, std::string newCmd) : panel(nullptr) , cmd(newCmd) {
    this->TransitionTo(panelVal);
  }
  ~Ui() {
    delete panel;
    delete client;
  }

  Client* getClient()
  {
    std::cout<<"here from getClient\n";
    return client;
  }

  void TransitionTo(Panel *panelVal) {
    if (this->panel != nullptr)
      delete this->panel;
    this->panel = panelVal;
    this->panel->setUi(this);
    this->panel->run();
  }
 
  void run() {
    this->panel->run();
  }
  std::string getCmd()
  {
    return cmd;
  }
  void setCmd(std::string newCmd)
  {
    cmd = newCmd;
  }

};