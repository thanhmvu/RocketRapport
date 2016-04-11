#ifndef PASTGUEST_H
#define PASTGUEST_H
#include "account.h"
#include <ctime>


class PastGuest : public Account
{

    std::vector<std::string> projectsWorkedOn;
    int monthDeparted;
    int dayDeparted;
    int yearDeparted;

public:
    PastGuest();

    std::vector<std::string> getProjectsWorkedOn();
    void addProject(std::string projectName);
    void removeProject(std::string projectName);
    int getMonthDeparted();
    void setMonthDeparted(int month);
    int getDayDeparted();
    void setDayDeparted(int day);
    int getYearDeparted();
    void setYearDeparted(int year);
};

#endif // PASTGUEST_H
