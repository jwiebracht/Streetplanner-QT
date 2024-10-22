#include "city.h"
#include <QDebug>
#include <QPen>
#include <QBrush>
#include <QGraphicsTextItem>

/**
 * @class City
 * @brief Repräsentiert eine Stadt mit einem Namen und Koordinaten auf einer Karte.
 *
 * Die Klasse City speichert den Namen und die Koordinaten einer Stadt und bietet Methoden, um die Stadt auf einer QGraphicsScene zu zeichnen.
 */

/**
 * @brief Konstruktor für ein City-Objekt.
 *
 * @param name Der Name der Stadt.
 * @param x Die x-Koordinate der Stadt.
 * @param y Die y-Koordinate der Stadt.
 */
City::City(QString name, int x, int y)
    : name(name), x(x), y(y)
{
    // Debug-Ausgabe im Konstruktor
    qDebug() << "Stadt erstellt:" << name << "mit Koordinaten:" << x << "," << y;
    // allCities.push_back(this);
}

/**
 * @brief Zeichnet die Stadt auf eine gegebene QGraphicsScene.
 *
 * @param scene Die QGraphicsScene, auf der die Stadt gezeichnet werden soll.
 */
void City::draw(QGraphicsScene& scene) const
{
    // Debug-Ausgabe in der draw-Funktion
    qDebug() << "Zeichne Stadt:" << name << "an Position:" << x << "," << y;

    // Erstelle einen roten Stift und Pinsel
    QPen pen(Qt::red);
    QBrush brush(Qt::red);

    // Zeichne die Ellipse mit roter Farbe
    scene.addEllipse(x, y, 2, 2, pen, brush);

    // Füge den Namen der Stadt hinzu, leicht verschoben, um Überlappung zu vermeiden
    QGraphicsTextItem* textItem = new QGraphicsTextItem(name);
    textItem->setDefaultTextColor(Qt::red);

    // Anpassung der Textposition relativ zur Ellipse
    qreal textOffsetX = 5; // 5 Pixel nach rechts
    qreal textOffsetY = -10; // 10 Pixel nach oben (wenn es über dem Punkt erscheinen soll)
    textItem->setPos(x + textOffsetX, y + textOffsetY);

    scene.addItem(textItem); // Füge das TextItem zur Szene hinzu
}

/**
 * @brief Gibt den Namen der Stadt zurück.
 *
 * @return Der Name der Stadt.
 */
QString City::getName() const
{
    return name;
}

/**
 * @brief Gibt die x-Koordinate der Stadt zurück.
 *
 * @return Die x-Koordinate der Stadt.
 */
int City::getXKoord() const
{
    return x;
}

/**
 * @brief Gibt die y-Koordinate der Stadt zurück.
 *
 * @return Die y-Koordinate der Stadt.
 */
int City::getYKoord() const
{
    return y;
}



