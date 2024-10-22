#ifndef MAP_H
#define MAP_H

#include "city.h"
#include "street.h"
#include "abstractmap.h"
#include "dijkstra.h"

#include <vector>

class Map : public AbstractMap
{
public:
    Map();
    void addCity(City*);
    void draw(QGraphicsScene& scene);
    bool addStreet(Street*);
    City* findCity(const QString cityName) const;
    QVector<Street*> getStreetList(const City* city) const;
    City* getOppositeCity(const Street* street, const City* city) const;
    double getLength(const Street* street) const;
    std::vector<City*> getAllCities();

private:
    std::vector<City*> allCities;
    std::vector<Street*> allStreets;
};

#endif // MAP_H
