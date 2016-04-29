#ifndef BLOGUI_H
#define BLOGUI_H
#include <sstream>
#include "screenui.h"
#include "../model/blog.h"

class BlogUI : public ScreenUI
{
public:
    BlogUI(System* mainSystem);

    std::stringstream ss;
    int scrollIndex;

    void displayScreen();
    void runScreen();

    void printFormerPosts();
};

#endif // BLOGUI_H
