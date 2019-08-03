#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "gamecontroller.h"
#include "constants.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
private slots:
    void adjustViewSIze();
private:
    void initScene();
    void initSceneBackground();
    
    QGraphicsScene *scene;
    QGraphicsView *view;
    GameController *game;
};

#endif // MAINWINDOW_H
