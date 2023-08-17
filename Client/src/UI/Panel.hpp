#pragma once

#include <iostream>

/**
 * The base Panel class declares methods that all Concrete Panel should
 * implement and also provides a backreference to the Ui object, associated
 * with the Panel. This backreference can be used by Panels to transition the
 * Ui to another Panel.
 */
class Ui;

class Panel {

 protected:
  Ui *ui_;
  bool finalPanel;


 public:
  virtual ~Panel() {
  }

  void set_ui(Ui *ui) {
    this->ui_ = ui;
  }

  bool  isPanelFinal()
  {
    return this->finalPanel;
  }
  virtual void run() = 0;
};
