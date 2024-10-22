#ifndef DIALOGSTREET_H
#define DIALOGSTREET_H

#include <QDialog>
#include "map.h"

namespace Ui {
class DialogStreet;
}

class DialogStreet : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStreet(Map *map, QWidget *parent = nullptr);
    ~DialogStreet();

    Street* createStreet();

private:
    Ui::DialogStreet *ui;
    Map *map;
};

#endif // DIALOGSTREET_H

