#include "dialog.h"
#include "ui_dialog.h"

/**
 * @brief Konstruktor für ein Dialog-Objekt.
 *
 * @param parent Der Eltern-Widget.
 */
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

/**
 * @brief Erstellt eine Stadt mit den in der Benutzeroberfläche angegebenen Details.
 *
 * @return Ein Zeiger auf die erstellte Stadt.
 */
City* Dialog::create_city()
{
    QString text = ui->lineEdit->text();
    int xKd = ui->spinBox->value();
    int yKd = ui->spinBox_2->value();

    return new City(text, xKd, yKd);
}

/**
 * @brief Destruktor für ein Dialog-Objekt.
 */
Dialog::~Dialog()
{
    delete ui;
}
