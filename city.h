#ifndef CITY_H
#define CITY_H

#include <QApplication>
#include <QString>
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QPen>
#include <QBrush>

class City
{
public:
    City(QString name, int x, int y);
    void draw(QGraphicsScene& scene) const;
    // static std::vector<City*> allCities;
    QString getName() const;
    int getXKoord() const;
    int getYKoord() const;

private:
    QString name;
    int x;
    int y;
};

#endif // CITY_H
