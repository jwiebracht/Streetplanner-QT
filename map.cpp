#include "map.h"

/**
 * @brief Konstruktor für ein Map-Objekt.
 */
Map::Map() {}

/**
 * @brief Fügt eine Stadt zur Karte hinzu.
 *
 * @param city Ein Zeiger auf die hinzuzufügende Stadt.
 */
void Map::addCity(City* city)
{
    allCities.push_back(city);
    qDebug() << "Name der hinzugefügten Stadt: " << city->getName() << Qt::endl;
}

/**
 * @brief Zeichnet alle Städte und Straßen auf eine gegebene QGraphicsScene.
 *
 * @param scene Die QGraphicsScene, auf der die Städte und Straßen gezeichnet werden sollen.
 */
void Map::draw(QGraphicsScene& scene)
{
    for(std::vector<City*>::iterator it = allCities.begin(); it != allCities.end(); ++it)
    {
        (*it)->draw(scene);
    }
    for(std::vector<Street*>::iterator it = allStreets.begin(); it != allStreets.end(); ++it)
    {
        (*it)->draw(scene);
    }
}

/**
 * @brief Fügt eine Straße zur Karte hinzu, wenn beide Städte in der Karte vorhanden sind.
 *
 * @param street Ein Zeiger auf die hinzuzufügende Straße.
 * @return true, wenn die Straße hinzugefügt wurde, andernfalls false.
 */
bool Map::addStreet(Street* street)
{
    City* city1 = street->getCity1();
    City* city2 = street->getCity2();

    if(findCity(city1->getName()) != nullptr && findCity(city2->getName()) != nullptr)
    {
        allStreets.push_back(street);
        qDebug() << "Die Straße zwischen" << city1->getName() << "und" << city2->getName() << "wurde in die Karte hinzugefügt.\n";
        return true;
    }
    return false;
}

/**
 * @brief Findet eine Stadt in der Karte anhand ihres Namens.
 *
 * @param cityName Der Name der zu findenden Stadt.
 * @return Ein Zeiger auf die gefundene Stadt oder nullptr, wenn die Stadt nicht gefunden wurde.
 */
City* Map::findCity(const QString cityName) const
{
    for(std::vector<City*>::const_iterator it = allCities.begin(); it != allCities.end(); ++it)
    {
        if((*it)->getName() == cityName)
        {
            return *it;
        }
    }
    return nullptr;
}

/**
 * @brief Gibt eine Liste der Straßen zurück, die mit einer bestimmten Stadt verbunden sind.
 *
 * @param city Ein Zeiger auf die Stadt.
 * @return Eine QVector-Liste der verbundenen Straßen.
 */
QVector<Street*> Map::getStreetList(const City* city) const
{
    QVector<Street*> connStreetList;

    for(std::vector<Street*>::const_iterator it = allStreets.begin(); it != allStreets.end(); it++)
    {
        if((*it)->getCity1() == city || (*it)->getCity2() == city)
        {
            connStreetList.push_back(*it);
        }
    }
    return connStreetList;
}

/**
 * @brief Gibt die gegenüberliegende Stadt einer Straße zurück.
 *
 * @param street Ein Zeiger auf die Straße.
 * @param city Ein Zeiger auf eine der Städte.
 * @return Ein Zeiger auf die gegenüberliegende Stadt oder nullptr, wenn die Stadt nicht Teil der Straße ist.
 */
City* Map::getOppositeCity(const Street* street, const City* city) const
{
    if(city == street->getCity1())
    {
        return street->getCity2();
    }
    else if(city == street->getCity2())
    {
        return street->getCity1();
    }
    else
    {
        return nullptr;
    }
}

/**
 * @brief Berechnet die Länge einer Straße.
 *
 * @param street Ein Zeiger auf die Straße.
 * @return Die Länge der Straße.
 */
double Map::getLength(const Street* street) const
{
    double laengeX = street->getCity1()->getXKoord() - street->getCity2()->getXKoord();
    double laengeY = street->getCity1()->getYKoord() - street->getCity2()->getYKoord();

    return sqrt(laengeX * laengeX + laengeY * laengeY);
}

std::vector<City*> Map::getAllCities()
{
    return allCities;;
}

