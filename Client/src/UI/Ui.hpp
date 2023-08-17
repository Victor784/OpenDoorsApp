#pragma once

#include"C:\Users\victo\Desktop\ProjectsCPP\MiniClientServer\Client\src\UI\Panel.hpp"
#include <string>

/**
 * The Ui defines the interface of interest to clients. It also maintains a
 * reference to an instance of a Panel subclass, which represents the current
 * panel of the Ui. THIS METHOD RELLIES HEAVEALY ON PANEL CONSTRUCTORS AND DESCTRUCTORS, WHILE USING RAW POINTERS. A BETTER METHOD MIGHT BE NEEDED IN THE FUTURE
 */
class Ui {

 private:
  Panel *panel_;
  std::string cmd = "";

 public:
  Ui(Panel *panel, std::string newCmd) : panel_(nullptr) , cmd(newCmd) {
    this->TransitionTo(panel);
  }
  ~Ui() {
    delete panel_;
  }

  void TransitionTo(Panel *panel) {
    if (this->panel_ != nullptr)
      delete this->panel_;
    this->panel_ = panel;
    this->panel_->set_ui(this);
    this->panel_->run();
  }
 
  void run() {
    this->panel_->run();
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