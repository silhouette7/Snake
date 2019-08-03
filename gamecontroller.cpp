#include <QGraphicsScene>
#include <QEvent>
#include <QKeyEvent>
#include "gamecontroller.h"
#include "snake.h"
#include "food.h"
#include "wall.h"

GameController::GameController(QGraphicsScene *scene, QObject *parent) :
    QObject(parent),
    scene(scene),
    snake(new Snake(this)),
    wall(new Wall())
{
    timer.start(100/33);

    Food *a1 = new Food(0, -50);
    scene->addItem(snake);
    scene->addItem(a1);
    scene->addItem(wall);
    scene->installEventFilter(this);

    resume();
}
bool GameController::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::KeyPress){
        handleKeyPressed((QKeyEvent *)event);
        return true;
    }
    else return QObject::eventFilter(watched, event);
}
void GameController::handleKeyPressed(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Left:
        snake->setMoveDirection(Snake::MoveLeft);
        break;
    case Qt::Key_Right:
        snake->setMoveDirection(Snake::MoveRight);
        break;
    case Qt::Key_Up:
        snake->setMoveDirection(Snake::MoveUp);
        break;
    case Qt::Key_Down:
        snake->setMoveDirection(Snake::MoveDown);
        break;
    }
}
void GameController::pause()
{
    disconnect(&timer, &QTimer::timeout,
               scene, &QGraphicsScene::advance);
}
void GameController::resume()
{
    connect(&timer, &QTimer::timeout,
            scene, &QGraphicsScene::advance);
}
void GameController::gameOver()
{
    scene->clear();
    snake = new Snake(this);
    scene->addItem(snake);
    wall = new Wall();
    scene->addItem(wall);
    addNewFood();
}
void GameController::snakeAteFood(Food *food)
{
    scene->removeItem(food);
    delete food;
    addNewFood();
}
void GameController::snakeAteItself()
{
    QTimer::singleShot(0, this, &GameController::gameOver);
}
void GameController::snakeHitWall()
{
    QTimer::singleShot(0, this, &GameController::gameOver);
}
void GameController::addNewFood()
{
    int x, y;
    do{
        x = (int)(qrand() % 100) / 10;
        y = (int)(qrand() % 100) / 10;
        x *= 10;
        y *= 10;
    }while(snake->shape().contains(snake->mapFromScene(QPointF(x+5, y+5))));
    Food *food = new Food(x, y);
    scene->addItem(food);
}
