#include "pastguest.h"

PastGuest::PastGuest()
{
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);
    dayDeparted = localTime->tm_mday;
    monthDeparted = localTime->tm_mon + 1;
    yearDeparted = localTime->tm_year + 1900;
}


/**
 * @brief Getter for the past guest's list of projects worked on.
 */
std::vector<std::string> PastGuest::getProjectsWorkedOn() {
    return this->projectsWorkedOn;
}


/**
 * @brief Adds a project to the past guest's list of projects.
 */
void PastGuest::addProject(std::string projectName) {
    this->getProjectsWorkedOn().push_back(projectName);
}


/**
 * @brief Adds a project to the past guest's list of projects.
 */
void PastGuest::removeProject(std::string projectName) {
    for (int i = 0; i < this->getProjectsWorkedOn().size(); i++) {
        if (projectName == this->getProjectsWorkedOn()[i]) {
            this->getProjectsWorkedOn().erase(this->getProjectsWorkedOn().begin() + i);
            break;
        }
    }
}


/**
 * @brief Getter for the past guest's month departed from the ranch.
 */
int PastGuest::getMonthDeparted() {
    return this->monthDeparted;
}


/**
 * @brief Setter for the past guest's month departed from the ranch.
 */
void PastGuest::setMonthDeparted(int month) {
    this->monthDeparted = month;
}


/**
 * @brief Getter for the past guest's day departed from the ranch.
 */
int PastGuest::getDayDeparted() {
    return this->dayDeparted;
}


/**
 * @brief Setter for the past guest's day departed from the ranch.
 */
void PastGuest::setDayDeparted(int day) {
    this->dayDeparted = day;
}


/**
 * @brief Getter for the past guest's year departed from the ranch.
 */
int PastGuest::getYearDeparted() {
    return this->yearDeparted;
}


/**
 * @brief Setter for the past guest's year departed from the ranch.
 */
void PastGuest::setYearDeparted(int year) {
    this->yearDeparted = year;
}
