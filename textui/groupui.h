#ifndef GROUPUI_H
#define GROUPUI_H
#include <sstream>
#include "screenui.h"
#include "../model/group.h"


class GroupUI : public ScreenUI
{

    int accountIndex;

public:
    GroupUI(System* mainSystem);

    std::stringstream ss;
    int scrollIndex;

    void displayScreen();
    void runScreen();

    int getAccountIndex();
    void setAccountIndex(int number);
};

#endif // GROUPUI_H
