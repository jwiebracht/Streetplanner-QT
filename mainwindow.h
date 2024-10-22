#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "map.h"
#include "street.h"
#include "mapio.h"
#include "mapionrw.h"
#include "dialogstreet.h"

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QGraphicsScene szene1;
    ~MainWindow();

private slots:
    void on_pushButton_teste_was_clicked();

    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_Test_Draw_City_clicked();

    void on_Map_Zeichnen_clicked();

    void on_Test_Street_clicked();

    void on_Test_Map_Streets_clicked();

    void on_verstecke_test_knoepfe_clicked();

    void on_Add_City_clicked();

    void on_Fill_Map_clicked();

    void on_Test_Abstract_Map_clicked();

    void on_Test_Dijkstra_clicked();

    void on_pushButton_suche_clicked();

    void initComboBox();

    void on_add_street_clicked();

private:
    Ui::MainWindow *ui;
    Map map;
    MapIo* mapio;

};
#endif // MAINWINDOW_H
