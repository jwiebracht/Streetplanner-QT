#include "street.h"

/**
 * @brief Konstruktor für ein Street-Objekt.
 *
 * @param city1 Ein Zeiger auf die erste Stadt.
 * @param city2 Ein Zeiger auf die zweite Stadt.
 */
Street::Street(City* city1, City* city2) : city1(city1), city2(city2)
{
}

/**
 * @brief Zeichnet die Straße auf eine gegebene QGraphicsScene.
 *
 * @param scene Die QGraphicsScene, auf der die Straße gezeichnet werden soll.
 */
void Street::draw(QGraphicsScene& scene)
{
    QPen pen(Qt::black);
    scene.addLine(city1->getXKoord(), city1->getYKoord(), city2->getXKoord(), city2->getYKoord(), pen);
    qDebug() << "Straße erstellt von" << city1->getXKoord() << city1->getYKoord() << city2->getXKoord() << city2->getYKoord();
}

/**
 * @brief Zeichnet die Straße in Rot auf eine gegebene QGraphicsScene.
 *
 * @param scene Die QGraphicsScene, auf der die Straße gezeichnet werden soll.
 */
void Street::drawRed(QGraphicsScene& scene)
{
    QPen pen(Qt::red);
    scene.addLine(city1->getXKoord(), city1->getYKoord(), city2->getXKoord(), city2->getYKoord(), pen);
}

/**
 * @brief Gibt die erste Stadt zurück.
 *
 * @return Ein Zeiger auf die erste Stadt.
 */
City* Street::getCity1() const
{
    return city1;
}

/**
 * @brief Gibt die zweite Stadt zurück.
 *
 * @return Ein Zeiger auf die zweite Stadt.
 */
City* Street::getCity2() const
{
    return city2;
}




