#ifndef GROUPGUI_H
#define GROUPGUI_H

#include <QWidget>

namespace Ui {
class GroupGUI;
}

class GroupGUI : public QWidget
{
    Q_OBJECT

public:
    explicit GroupGUI(QWidget *parent = 0);
    ~GroupGUI();

private:
    Ui::GroupGUI *ui;
};

#endif // GROUPGUI_H
