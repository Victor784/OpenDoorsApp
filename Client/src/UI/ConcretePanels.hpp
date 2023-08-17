#pragma once

#include "Panel.hpp"
#include"Ui.hpp"

/**
 * Concrete Panels implement various behaviors, associated with a panel of the
 * Ui.
 */

class Panel_Initial : public Panel {

 public:
  void run() override;

};

class Panel_CheckEntrances : public Panel {
 public:
  void run() override;
};

class Panel_UpdateHouseLayout : public Panel {
 public:
  void run() override;
};

class Panel_CheckRooms : public Panel {
 public:
  void run() override;
};

class Panel_CheckAllEntrances : public Panel {
 public:
  void run() override;
};

class Panel_test : public Panel {
 public:
  void run() override;
};