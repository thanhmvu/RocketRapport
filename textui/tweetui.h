#ifndef TWEETUI_H
#define TWEETUI_H
#include <sstream>
#include "screenui.h"
#include "../model/tweet.h"

class TweetUI : public ScreenUI
{
public:
    TweetUI(System* mainSystem);

    std::stringstream ss;
    int scrollIndex;

    void displayScreen();
    void runScreen();

    void printFormerTweets();
};

#endif // TWEETUI_H
