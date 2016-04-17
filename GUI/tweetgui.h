#ifndef TWEETGUI_H
#define TWEETGUI_H

#include <QWidget>

namespace Ui {
class TweetGUI;
}

class TweetGUI : public QWidget
{
    Q_OBJECT

public:
    explicit TweetGUI(QWidget *parent = 0);
    ~TweetGUI();

private:
    Ui::TweetGUI *ui;
};

#endif // TWEETGUI_H
