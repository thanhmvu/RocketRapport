#include "profileui.h"

ProfileUI::ProfileUI(System* mainSystem)
{
    this->setSystem(mainSystem);
}

void ProfileUI::displayScreen() {
    for (int i = 0; i < this->getCols(); i++) {
        mvprintw(0, i, "-");
    }
    for (int i = 0; i < this->getCols(); i++) {
        mvprintw(2, i, "-");
    }
    for (int i = 0; i < this->getCols(); i++) {
        mvprintw(this->getRows()-2, i, "-");
    }
    ss << this->getSystem()->getCurrentUser()->getProfileUsername();
    int tempsize = this->getSystem()->getCurrentUser()->getProfileUsername().size();
    tempsize += 10;
    tempsize /= 2;
    ss << "'s Profile";
    mvprintw(1, (this->getCols()/2)-tempsize, ss.str().c_str());
    ss.str("");
    mvprintw(4, 1, "First Name:");
    mvprintw(6, 1, "Last Name:");
    mvprintw(8, 1, "Gender:");
    mvprintw(10, 1, "Home Address:");
    mvprintw(12, 1, "Most Recent Employer:");
    mvprintw(14, 1, "Age:");
    mvprintw(16, 1, "Phone Number:");
    mvprintw(18, 1, "About Yourself:");
    mvprintw(21, (this->getCols()/2)-4, "Main Menu");
    mvprintw(21, ((this->getCols()/2)/2)-7, "User's Blog");
    mvprintw(21, (((this->getCols()/2)/2)+(this->getCols()/2))-5, "User's Tweets");
    mvprintw(this->getRows()-1, 7, "Up, Down - Navigate Fields;     Home - Select;     Type - Edit");

    this->getSystem()->getCurrentUser()->setBlogTweetUsername(this->getSystem()->getCurrentUser()->getProfileUsername());

    refresh();
}

void ProfileUI::runScreen() {
    int fny = 4, fnx = 13;
    int lny = 6, lnx = 12;
    int gy = 8, gx = 9;
    int hay = 10, hax = 15;
    int mrey = 12, mrex = 23;
    int ay = 14, ax = 6;
    int pny = 16, pnx = 15;
    int ayy = 18, ayx = 17;
    int fnsize = 0;
    int lnsize = 0;
    int gsize = 0;
    int hasize = 0;
    int mresize = 0;
    int asize = 0;
    int pnsize = 0;
    int aysize = 0;
    std::stringstream fnss;
    std::stringstream lnss;
    std::stringstream gss;
    std::stringstream hass;
    std::stringstream mress;
    std::stringstream ass;
    std::stringstream pnss;
    std::stringstream ayss;
    std::stringstream sstemp;

    for(const auto &acc: this->getSystem()->getAllAccounts()) {
        if (acc.first.toStdString() == this->getSystem()->getCurrentUser()->getProfileUsername()) {
            std::string tempString;

            fnss << acc.second->getFirstName().toStdString();
            fnsize = acc.second->getFirstName().toStdString().size();

            lnss << acc.second->getLastName().toStdString();
            lnsize = acc.second->getLastName().toStdString().size();

            gss << acc.second->getGender().toStdString();
            gsize = acc.second->getGender().toStdString().size();

            hass << acc.second->getAddress().toStdString();
            hasize = acc.second->getAddress().toStdString().size();

            mress << acc.second->getMostRecentEmployer().toStdString();
            mresize = acc.second->getMostRecentEmployer().toStdString().size();

            ass << acc.second->getAge();
            sstemp << acc.second->getAge();
            tempString = sstemp.str();
            asize = tempString.size();
            sstemp.str("");

            pnss << acc.second->getPhoneNumber();
            sstemp << acc.second->getPhoneNumber();
            tempString = sstemp.str();
            pnsize = tempString.size();
            sstemp.str("");

            ayss << acc.second->getAbout().toStdString();
            aysize = acc.second->getAbout().toStdString().size();
        }
    }

    mvprintw(fny, fnx, fnss.str().c_str());
    mvprintw(lny, lnx, lnss.str().c_str());
    mvprintw(gy, gx, gss.str().c_str());
    mvprintw(hay, hax, hass.str().c_str());
    mvprintw(mrey, mrex, mress.str().c_str());
    mvprintw(ay, ax, ass.str().c_str());
    mvprintw(pny, pnx, pnss.str().c_str());
    mvprintw(ayy, ayx, ayss.str().c_str());

    fnx = 13+fnsize;
    lnx = 12+lnsize;
    gx = 9+gsize;
    hax = 15+hasize;
    mrex = 23+mresize;
    ax = 6+asize;
    pnx = 15+pnsize;
    ayx = 17+aysize;
    int mmy = 21, mmx = (this->getCols()/2)-5;
    int uby = 21, ubx = ((this->getCols()/2)/2)-8;
    int uty = 21, utx = (((this->getCols()/2)/2)+(this->getCols()/2))-6;
    int rowIndex = 0;
    int curY = 4;
    int curX = 13;

    curs_set(1);
    move(fny, fnx);
    refresh();

    int keyPress;
    while(this->getChangeScreens() == false) {
        getyx(stdscr, curY, curX);
        keyPress = getch();
        switch(keyPress) {
        case KEY_UP: // Move up options
            switch(rowIndex) {
            case 0:
                curs_set(0);
                move(uty, utx);
                printw(">");
                move(uty, utx);
                rowIndex = 10;
                break;
            case 1:
                move(fny, fnx);
                rowIndex = 0;
                break;
            case 2:
                move(lny, lnx);
                rowIndex = 1;
                break;
            case 3:
                move(gy, gx);
                rowIndex = 2;
                break;
            case 4:
                move(hay, hax);
                rowIndex = 3;
                break;
            case 5:
                move(mrey, mrex);
                rowIndex = 4;
                break;
            case 6:
                move(ay, ax);
                rowIndex = 5;
                break;
            case 7:
                move(pny, pnx);
                rowIndex = 6;
                break;
            case 8:
                curs_set(1);
                move(uby, ubx);
                printw(" ");
                move(ayy, ayx);
                rowIndex = 7;
                break;
            case 9:
                curs_set(0);
                printw(" ");
                move(uby, ubx);
                printw(">");
                move(uby, ubx);
                rowIndex = 8;
                break;
            case 10:
                curs_set(0);
                printw(" ");
                move(mmy, mmx);
                printw(">");
                move(mmy, mmx);
                rowIndex = 9;
                break;
            }
            break;
        case KEY_DOWN: // Move down options
            switch(rowIndex) {
            case 0:
                move(lny, lnx);
                rowIndex = 1;
                break;
            case 1:
                move(gy, gx);
                rowIndex = 2;
                break;
            case 2:
                move(hay, hax);
                rowIndex = 3;
                break;
            case 3:
                move(mrey, mrex);
                rowIndex = 4;
                break;
            case 4:
                move(ay, ax);
                rowIndex = 5;
                break;
            case 5:
                move(pny, pnx);
                rowIndex = 6;
                break;
            case 6:
                move(ayy, ayx);
                rowIndex = 7;
                break;
            case 7:
                curs_set(0);
                move(uby, ubx);
                printw(">");
                move(uby, ubx);
                rowIndex = 8;
                break;
            case 8:
                curs_set(0);
                move(uby, ubx);
                printw(" ");
                move(mmy, mmx);
                printw(">");
                move(mmy, mmx);
                rowIndex = 9;
                break;
            case 9:
                curs_set(0);
                move(mmy, mmx);
                printw(" ");
                move(uty, utx);
                printw(">");
                move(uty, utx);
                rowIndex = 10;
                break;
            case 10:
                curs_set(1);
                move(uty, utx);
                printw(" ");
                move(fny, fnx);
                rowIndex = 0;
                break;
            }
            break;
        case '\n':
            move(curY, curX);
            break;
        case KEY_BACKSPACE:
            if (this->getSystem()->getCurrentUser()->getUsername().toStdString() == this->getSystem()->getCurrentUser()->getProfileUsername()) {
                // User can edit
                switch(rowIndex) {
                case 0:
                    if ((fnx-13) > 0) {
                        fnx--;
                        mvprintw(fny, fnx, " ");
                        move(fny, fnx);
                        std::string remove = fnss.str();
                        remove.erase(remove.size()-1, 1);
                        fnss.str("");
                        fnss << remove;
                        this->getSystem()->getCurrentUser()->setFirstName(QString::fromStdString(fnss.str()));
                    } else {
                        move(curY, curX);
                    }
                    break;
                case 1:
                    if ((lnx-12) > 0) {
                        lnx--;
                        mvprintw(lny, lnx, " ");
                        move(lny, lnx);
                        std::string remove = lnss.str();
                        remove.erase(remove.size()-1, 1);
                        lnss.str("");
                        lnss << remove;
                        this->getSystem()->getCurrentUser()->setLastName(QString::fromStdString(lnss.str()));
                    } else {
                        move(curY, curX);
                    }
                    break;
                case 2:
                    if ((gx-9) > 0) {
                        gx--;
                        mvprintw(gy, gx, " ");
                        move(gy, gx);
                        std::string remove = gss.str();
                        remove.erase(remove.size()-1, 1);
                        gss.str("");
                        gss << remove;
                        this->getSystem()->getCurrentUser()->setGender(QString::fromStdString(gss.str()));
                    } else {
                        move(curY, curX);
                    }
                    break;
                case 3:
                    if ((hax-15) > 0) {
                        hax--;
                        mvprintw(hay, hax, " ");
                        move(hay, hax);
                        std::string remove = hass.str();
                        remove.erase(remove.size()-1, 1);
                        hass.str("");
                        hass << remove;
                        this->getSystem()->getCurrentUser()->setAddress(QString::fromStdString(hass.str()));
                    } else {
                        move(curY, curX);
                    }
                    break;
                case 4:
                    if ((mrex-23) > 0) {
                        mrex--;
                        mvprintw(mrey, mrex, " ");
                        move(mrey, mrex);
                        std::string remove = mress.str();
                        remove.erase(remove.size()-1, 1);
                        mress.str("");
                        mress << remove;
                        this->getSystem()->getCurrentUser()->setMostRecentEmployer(QString::fromStdString(mress.str()));
                    } else {
                        move(curY, curX);
                    }
                    break;
                case 5:
                    if ((ax-6) > 0) {
                        int numDump = 0;
                        std::string dump;
                        ax--;
                        mvprintw(ay, ax, " ");
                        move(ay, ax);
                        std::string remove = ass.str();
                        remove.erase(remove.size()-1, 1);
                        ass.str("");
                        ass.str(remove);
                        dump = ass.str();
                        ass >> numDump;
                        ass.clear();
                        ass << dump;
                        this->getSystem()->getCurrentUser()->setAge(numDump);
                    } else {
                        move(curY, curX);
                    }
                    break;
                case 6:
                    if ((pnx-15) > 0) {
                        int numDump = 0;
                        std::string dump;
                        pnx--;
                        mvprintw(pny, pnx, " ");
                        move(pny, pnx);
                        std::string remove = pnss.str();
                        remove.erase(remove.size()-1, 1);
                        pnss.str("");
                        pnss.str(remove);
                        dump = pnss.str();
                        pnss >> numDump;
                        pnss.clear();
                        pnss << dump;
                        this->getSystem()->getCurrentUser()->setPhoneNumber(numDump);
                    } else {
                        move(curY, curX);
                    }
                    break;
                case 7:
                    if ((ayx-17) > 0) {
                        ayx--;
                        mvprintw(ayy, ayx, " ");
                        move(ayy, ayx);
                        std::string remove = ayss.str();
                        remove.erase(remove.size()-1, 1);
                        ayss.str("");
                        ayss << remove;
                        this->getSystem()->getCurrentUser()->setAbout(QString::fromStdString(ayss.str()));
                    } else {
                        move(curY, curX);
                    }
                    break;
                case 8:
                    move(curY, curX);
                    break;
                case 9:
                    move(curY, curX);
                    break;
                case 10:
                    move(curY, curX);
                    break;
                }
            }
            break;
        case KEY_HOME:
            switch(rowIndex) {
            case 8:
                this->changeScreens(true);
                this->screenNumber = 4;
                break;
            case 9:
                this->changeScreens(true);
                this->screenNumber = 1;
                this->getSystem()->getCurrentUser()->setBlogTweetUsername(this->getSystem()->getCurrentUser()->getUsername().toStdString());
                break;
            case 10:
                this->changeScreens(true);
                this->screenNumber = 5;
                break;
            default:
                move(curY, curX);
                break;
            }
            break;
        default:
            if (this->getSystem()->getCurrentUser()->getUsername().toStdString() == this->getSystem()->getCurrentUser()->getProfileUsername()) {
                // User can edit
                char temp = (char)keyPress;
                switch(rowIndex) {
                case 0:
                    if (fnx < this->getCols()-1) {
                        fnss << temp;
                        sstemp << temp;
                        mvprintw(fny, fnx, sstemp.str().c_str());
                        sstemp.str("");
                        this->getSystem()->getCurrentUser()->setFirstName(QString::fromStdString(fnss.str()));
                        fnx++;
                    } else {
                        move(curY, curX);
                        printw(" ");
                        move(curY, curX);
                    }
                    break;
                case 1:
                    if (lnx < this->getCols()-1) {
                        lnss << temp;
                        sstemp << temp;
                        mvprintw(lny, lnx, sstemp.str().c_str());
                        sstemp.str("");
                        this->getSystem()->getCurrentUser()->setLastName(QString::fromStdString(lnss.str()));
                        lnx++;
                    } else {
                        move(curY, curX);
                        printw(" ");
                        move(curY, curX);
                    }
                    break;
                case 2:
                    if (gx < this->getCols()-1) {
                        gss << temp;
                        sstemp << temp;
                        mvprintw(gy, gx, sstemp.str().c_str());
                        sstemp.str("");
                        this->getSystem()->getCurrentUser()->setGender(QString::fromStdString(gss.str()));
                        gx++;
                    } else {
                        move(curY, curX);
                        printw(" ");
                        move(curY, curX);
                    }
                    break;
                case 3:
                    if (hax < this->getCols()-1) {
                        hass << temp;
                        sstemp << temp;
                        mvprintw(hay, hax, sstemp.str().c_str());
                        sstemp.str("");
                        this->getSystem()->getCurrentUser()->setAddress(QString::fromStdString(hass.str()));
                        hax++;
                    } else {
                        move(curY, curX);
                        printw(" ");
                        move(curY, curX);
                    }
                    break;
                case 4:
                    if (mrex < this->getCols()-1) {
                        mress << temp;
                        sstemp << temp;
                        mvprintw(mrey, mrex, sstemp.str().c_str());
                        sstemp.str("");
                        this->getSystem()->getCurrentUser()->setMostRecentEmployer(QString::fromStdString(mress.str()));
                        mrex++;
                    } else {
                        move(curY, curX);
                        printw(" ");
                        move(curY, curX);
                    }
                    break;
                case 5:
                    if (ax < this->getCols()-1) {
                        std::string dump;
                        int numDump = 0;
                        ass << temp;
                        sstemp << temp;
                        mvprintw(ay, ax, sstemp.str().c_str());
                        sstemp.str("");
                        dump = ass.str();
                        ass.str("");
                        ass.str(dump);
                        ass >> numDump;
                        ass.str("");
                        ass.clear();
                        ass << dump;
                        this->getSystem()->getCurrentUser()->setAge(numDump);
                        ax++;
                    } else {
                        move(curY, curX);
                        printw(" ");
                        move(curY, curX);
                    }
                    break;
                case 6:
                    if (pnx < this->getCols()-1) {
                        std::string dump;
                        int numDump = 0;
                        pnss << temp;
                        sstemp << temp;
                        mvprintw(pny, pnx, sstemp.str().c_str());
                        sstemp.str("");
                        dump = pnss.str();
                        pnss.str("");
                        pnss.str(dump);
                        pnss >> numDump;
                        pnss.str("");
                        pnss.clear();
                        pnss << dump;
                        this->getSystem()->getCurrentUser()->setPhoneNumber(numDump);
                        pnx++;
                    } else {
                        move(curY, curX);
                        printw(" ");
                        move(curY, curX);
                    }
                    break;
                case 7:
                    if (ayx < this->getCols()-1) {
                        ayss << temp;
                        sstemp << temp;
                        mvprintw(ayy, ayx, sstemp.str().c_str());
                        sstemp.str("");
                        this->getSystem()->getCurrentUser()->setAbout(QString::fromStdString(ayss.str()));
                        ayx++;
                    } else {
                        move(curY, curX);
                        printw(" ");
                        move(curY, curX);
                    }
                    break;
                case 8:
                    move(curY, curX);
                    printw(">");
                    move(curY, curX);
                    break;
                case 9:
                    move(curY, curX);
                    printw(">");
                    move(curY, curX);
                    break;
                case 10:
                    move(curY, curX);
                    printw(">");
                    move(curY, curX);
                    break;
                }
            }
            if (rowIndex == 8 || rowIndex == 9 || rowIndex == 10) {
                move(curY, curX);
                printw(">");
                move(curY, curX);
            }
            break;
        }
    }

    this->getSystem()->getCurrentUser()->setProfileUsername(this->getSystem()->getCurrentUser()->getUsername().toStdString());
    this->changeScreens(false);
    clear();
    refresh();
}
