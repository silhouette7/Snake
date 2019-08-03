#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>

class Snake;
class Food;
class Wall;

class GameController : public QObject
{
    Q_OBJECT
public:
    explicit GameController(QGraphicsScene *scene, QObject *parent = nullptr);
    void snakeAteFood(Food *food);
    void snakeHitWall();
    void snakeAteItself();
signals:

public slots:
    void pause();
    void resume();
    void gameOver();
protected:
    bool eventFilter(QObject *watched, QEvent *event);
private:
    void addNewFood();
    void handleKeyPressed(QKeyEvent *event);
    QGraphicsScene *scene;
    Snake *snake;
    QTimer timer;
    Wall *wall;
};

#endif // GAMECONTROLLER_H
