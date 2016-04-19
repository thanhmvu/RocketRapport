#include "scrapbookpost.h"

int ScrapbookPost::id_cnt = 0;

ScrapbookPost::ScrapbookPost()
{
    id = id_cnt;
    id_cnt++;
}
