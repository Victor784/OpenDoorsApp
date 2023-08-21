#pragma once

#include "Panel.hpp"
#include"Ui.hpp"

/**
 * Concrete Panels implement various behaviors, associated with a panel of the
 * Ui.
 */

class PanelInitial : public Panel {

 public:
  void run() override;

};

class PanelCheckEntrances : public Panel {
 public:
  void run() override;
};

class PanelUpdateHouseLayout : public Panel {
 public:
  void run() override;
};

class PanelCheckRooms : public Panel {
 public:
  void run() override;
};

class PanelCheckAllEntrances : public Panel {
 public:
  void run() override;
};

class PanelTest : public Panel {
 public:
  void run() override;
};

class PanelRoom : public Panel{
 public:
  PanelRoom(const Room& room);
  void run() override;
 public: 
  const Room* roomPtr;
};