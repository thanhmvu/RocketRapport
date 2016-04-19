#ifndef SCRAPBOOKPOST_H
#define SCRAPBOOKPOST_H
#include "post.h"


class ScrapbookPost : public Post
{
private:
    static int id_cnt;
    int id;
public:
    ScrapbookPost();
};

#endif // SCRAPBOOKPOST_H
