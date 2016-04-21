#ifndef TWEETUI_H
#define TWEETUI_H
#include "screenui.h"

class TweetUI : public ScreenUI
{
public:
    TweetUI(System* mainSystem);

    void displayScreen();
    void runScreen();
};

#endif // TWEETUI_H
