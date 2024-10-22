#include "mainwindow.h"
#include "dialog.h"
#include "map.h"
#include "./ui_mainwindow.h"
#include "city.h"
#include <cstdlib> // für std::rand und std::srand
#include <ctime>   // für std::time

/**
 * @brief Konstruktor für MainWindow
 *
 * Initialisiert die Benutzeroberfläche und setzt die Szene für den View.
 * Initialisiert den Zufallsgenerator und das MapIoNrw-Objekt.
 *
 * @param parent Zeiger auf das übergeordnete QWidget
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , szene1(this) // Initialisiere szene1 mit this als Eltern
{
    ui->setupUi(this);
    ui->view1->setScene(&szene1);

    // Initialisiere den Zufallsgenerator
    std::srand(std::time(nullptr));

    //MapIoNrw
    mapio = new MapIoNrw();
}

/**
 * @brief Destruktor für MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Slot-Funktion, die aufgerufen wird, wenn der "Teste was"-Button gedrückt wird.
 *
 * Diese Funktion liest einen Text aus einem LineEdit, überprüft, ob es sich um eine Zahl handelt,
 * und zeigt entweder den Text oder die inkrementierte Zahl an. Zeichnet ein zufälliges Rechteck auf die Szene.
 */
void MainWindow::on_pushButton_teste_was_clicked()
{
    QString ausgabe = "";
    QString ausgabeText = ui->lineEdit_teste_was->text();
    bool ok;
    int a = ausgabeText.toInt(&ok);
    if (!ok)
    {
        ausgabe = QString("Der eingegebene Text ist: %1").arg(ausgabeText);
        qDebug() << ausgabe;
    }
    else
    {
        a++;
        qDebug() << "Die Zahl ist nun:" << a;
    }
    qDebug() << "Hallo";

    // Zufallszahlen zwischen 0 und 9 generieren
    int x = std::rand() % 10;
    int y = std::rand() % 10;

    szene1.addRect(x, y, 5, 5);
}

/**
 * @brief Slot-Funktion, die aufgerufen wird, wenn das "Exit"-Menüelement ausgewählt wird.
 *
 * Schließt die Anwendung.
 */
void MainWindow::on_actionExit_triggered()
{
    close();
}

/**
 * @brief Slot-Funktion, die aufgerufen wird, wenn das "Clear Scene"-Menüelement ausgewählt wird.
 *
 * Löscht alle Elemente von der Szene.
 */
void MainWindow::on_actionClear_Scene_triggered()
{
    szene1.clear();
    initComboBox();
}

/**
 * @brief Slot-Funktion, die aufgerufen wird, wenn das "About"-Menüelement ausgewählt wird.
 *
 * Zeigt ein About-Dialogfenster an.
 */
void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About", "About about about");
}

/**
 * @brief Slot-Funktion, die aufgerufen wird, wenn der "Test Draw City"-Button gedrückt wird.
 *
 * Zeichnet zwei Beispielstädte auf die Szene.
 */
void MainWindow::on_Test_Draw_City_clicked()
{
    City city1("Mannheim", 15, 15);
    city1.draw(szene1);
    City city2("Cologne", 10, 0);
    city2.draw(szene1);
    initComboBox();
}

/**
 * @brief Slot-Funktion, die aufgerufen wird, wenn der "Map Zeichnen"-Button gedrückt wird.
 *
 * Fügt eine Stadt zur Karte hinzu und zeichnet die Karte auf die Szene.
 */
void MainWindow::on_Map_Zeichnen_clicked()
{
    City* c1 = new City("city c1", 20,50);
    map.addCity(c1);
    map.draw(szene1);
    initComboBox();
}

/**
 * @brief Slot-Funktion, die aufgerufen wird, wenn der "Test Street"-Button gedrückt wird.
 *
 * Erstellt zwei Städte und eine Straße zwischen ihnen, fügt diese zur Karte hinzu und zeichnet sie auf die Szene.
 */
void MainWindow::on_Test_Street_clicked()
{
    Map map;

    // Städte dynamisch erstellen
    City* city1 = new City("city c1", 20, 50);
    map.addCity(city1);

    City* city2 = new City("city c2", 100, 160);
    map.addCity(city2);

    // Straße zwischen den Städten erstellen
    Street s1(city1, city2);

    // Karte und Straße zeichnen
    map.draw(szene1);
    s1.draw(szene1);
    initComboBox();
}

/**
 * @brief Slot-Funktion, die aufgerufen wird, wenn der "Test Map Streets"-Button gedrückt wird.
 *
 * Erstellt zwei Städte und eine Straße zwischen ihnen, fügt diese zur Karte hinzu und zeichnet sie auf die Szene.
 */
void MainWindow::on_Test_Map_Streets_clicked()
{
    City c1("berlin", 20, 50);
    map.addCity(&c1);
    City c2("cologne", 100, 160);
    map.addCity(&c2);
    Street s1(&c1, &c2);
    map.addStreet(&s1);
    map.draw(szene1);
    initComboBox();
}

/**
 * @brief Slot-Funktion, die aufgerufen wird, wenn der "Verstecke Test"-Button gedrückt wird.
 *
 * Versteckt oder zeigt Test-Buttons basierend auf dem Zustand der CheckBox.
 */
void MainWindow::on_verstecke_test_knoepfe_clicked()
{
    if(ui->verstecke_test_knoepfe->isChecked() == true)
    {
        ui->Test_Draw_City->hide();
        ui->Test_Map_Streets->hide();
        ui->Test_Street->hide();
        ui->lineEdit_teste_was->hide();
        ui->Map_Zeichnen->hide();
        ui->pushButton_teste_was->hide();
    }
    else if(ui->verstecke_test_knoepfe->isChecked() == false)
    {
        ui->Test_Draw_City->show();
        ui->Test_Map_Streets->show();
        ui->Test_Street->show();
        ui->lineEdit_teste_was->show();
        ui->Map_Zeichnen->show();
        ui->pushButton_teste_was->show();
    }
}

/**
 * @brief Slot-Funktion, die aufgerufen wird, wenn der "Add City"-Button gedrückt wird.
 *
 * Öffnet einen Dialog zur Eingabe einer neuen Stadt, fügt diese zur Karte hinzu und zeichnet sie auf die Szene.
 */
void MainWindow::on_Add_City_clicked()
{
    Dialog dialog(this);
    dialog.exec();

    City* city = dialog.create_city();
    map.addCity(city);
    city->draw(szene1);
    initComboBox();
}

/**
 * @brief Slot-Funktion, die aufgerufen wird, wenn der "Fill Map"-Button gedrückt wird.
 *
 * Füllt die Karte mit vordefinierten Daten und zeichnet sie auf die Szene.
 */
void MainWindow::on_Fill_Map_clicked()
{
    mapio->fillMap(map);
    map.draw(szene1);
    initComboBox();
}

/**
 * @brief Slot-Funktion, die aufgerufen wird, wenn der "Test Abstract Map"-Button gedrückt wird.
 *
 * Führt verschiedene Tests auf der Map-Klasse aus und gibt die Ergebnisse in der Konsole aus.
 */
void MainWindow::on_Test_Abstract_Map_clicked()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);

    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";
    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
    initComboBox();
}

/**
 * @brief Slot-Funktion, die aufgerufen wird, wenn der "Test Dijkstra"-Button gedrückt wird.
 *
 * Erstellt eine Testkarte mit drei Städten und drei Straßen, führt eine Dijkstra-Suche durch und zeichnet die kürzeste Route.
 */
void MainWindow::on_Test_Dijkstra_clicked()
{
    Map testMap;

    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    testMap.addCity(a);
    testMap.addCity(b);
    testMap.addCity(c);

    Street *s1 = new Street(a, b);
    Street *s2 = new Street(b, c);
    Street *s3 = new Street(a, c);
    testMap.addStreet(s1);
    testMap.addStreet(s2);
    testMap.addStreet(s3);

    testMap.draw(szene1);

    QVector<Street*> shortest = Dijkstra::search(testMap, a->getName(), c->getName());

    for(QVector<Street*>::iterator it = shortest.begin(); it != shortest.end(); it++)
    {
        qDebug() << "Going through" << (*it)->getCity1()->getName() << (*it)->getCity2()->getName();
        (*it)->drawRed(szene1);
    }
    initComboBox();
}

/**
 * @brief Slot-Funktion, die aufgerufen wird, wenn der "Suche"-Button gedrückt wird.
 *
 * Findet die kürzeste Route zwischen zwei Städten, die in den Eingabefeldern eingegeben wurden, und zeichnet die Route auf der Szene.
 */
void MainWindow::on_pushButton_suche_clicked()
{
    // QString stadt1 = ui->lineEdit_city1->text();
    // QString stadt2 = ui->lineEdit_city2->text();

    // City* city1 = map.findCity(stadt1);
    // City* city2 = map.findCity(stadt2);

    // if (city1 && city2)
    // {
    //     QVector<Street*> shortest = Dijkstra::search(map, city1->getName(), city2->getName());
    //     for(QVector<Street*>::iterator it = shortest.begin(); it != shortest.end(); it++)
    //     {
    //         (*it)->drawRed(szene1);
    //     }
    // }
    // else
    // {
    //     if (city1 == nullptr)
    //     {
    //         qDebug() << "Stadt 1 nicht gefunden: " << stadt1;
    //     }
    //     if (city2 == nullptr)
    //     {
    //         qDebug() << "Stadt 2 nicht gefunden: " << stadt2;
    //     }
    // }
    QString start = ui->comboBox_cityStart->currentText();
    QString end = ui->comboBox_cityEnd->currentText();

    if (start == end)
    {
        qDebug() << "Error: invalid route.";
        return;
    }

    QVector<Street*> shortest = Dijkstra::search(map, start, end);

    for(QVector<Street*>::iterator it = shortest.begin(); it != shortest.end(); it++)
    {
        qDebug() << "Going through" << (*it)->getCity1()->getName() << (*it)->getCity2()->getName();
        (*it)->drawRed(szene1);
    }
}


void MainWindow::on_add_street_clicked()
{
    DialogStreet dialog(&map,this);
    dialog.exec();

    Street* street = dialog.createStreet();
    if(street != nullptr)
    {
    map.addStreet(street);
    street->draw(szene1);
    }

}

/**
 * @brief Initialisiert die ComboBox-Widgets für Start- und Zielstädte.
 *
 * Diese Methode ruft alle Städte aus einer Kartenstruktur ab, leert die
 * vorhandenen Einträge in den ComboBoxen `comboBox_cityStart` und `comboBox_cityEnd`
 * und fügt dann die Namen der Städte zu diesen ComboBoxen hinzu.
 */
void MainWindow::initComboBox()
{
    // Ruft alle Städte aus der Kartenstruktur ab.
    std::vector<City*> mapCityList = map.getAllCities();

    // Leert die ComboBoxen für Start- und Zielstädte.
    ui->comboBox_cityStart->clear();
    ui->comboBox_cityEnd->clear();

    // Fügt die Namen der Städte zu den ComboBoxen hinzu.
    for(std::vector<City*>::iterator it = mapCityList.begin(); it != mapCityList.end(); it++)
    {
        ui->comboBox_cityStart->addItem((*it)->getName());
        ui->comboBox_cityEnd->addItem((*it)->getName());
    }
}



