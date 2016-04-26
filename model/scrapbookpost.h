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

    // for debugging purpose
    static int getIdCnt(){ return id_cnt; };
};

#endif // SCRAPBOOKPOST_H
