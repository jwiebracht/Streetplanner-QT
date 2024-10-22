#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "city.h"
#include "map.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);

    City* create_city();

    ~Dialog();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
