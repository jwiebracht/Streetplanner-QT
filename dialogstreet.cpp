#include "dialogstreet.h"
#include "ui_dialogstreet.h"
#include <QMessageBox>

/**
 * @brief Konstruktor für ein DialogStreet-Objekt.
 *
 * @param map Ein Zeiger auf die Karte, in der die Straße erstellt werden soll.
 * @param parent Der Eltern-Widget.
 */
DialogStreet::DialogStreet(Map *map, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogStreet),
    map(map)
{
    ui->setupUi(this);
}

/**
 * @brief Destruktor für ein DialogStreet-Objekt.
 */
DialogStreet::~DialogStreet()
{
    delete ui;
}

/**
 * @brief Erstellt eine Straße zwischen den in der Benutzeroberfläche angegebenen Städten.
 *
 * @return Ein Zeiger auf die erstellte Straße oder nullptr, wenn eine oder beide Städte nicht gefunden wurden.
 */
Street* DialogStreet::createStreet()
{
    QString cityName1 = ui->lineEdit->text();
    QString cityName2 = ui->lineEdit_2->text();

    City* city1 = map->findCity(cityName1);
    City* city2 = map->findCity(cityName2);

    if (!city1 || !city2) {
        QMessageBox::warning(this, "Fehler", "Eine oder beide Städte wurden nicht gefunden.");
        return nullptr;
    }

    return new Street(city1, city2);
}


