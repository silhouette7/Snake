#ifndef SNAKE_H
#define SNAKE_H

#include <QGraphicsItem>

class GameController;

class Snake : public QGraphicsItem
{
public:
    enum Direction{
        NoMove,
        MoveLeft,
        MoveRight,
        MoveUp,
        MoveDown
    };

    Snake(GameController * controller);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QPainterPath shape() const;
    void setMoveDirection(Direction direction);
protected:
    void advance(int step);
private:
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void handleCollisions();

    GameController *controller;
    QPointF head;
    QList<QPointF> tail;
    Direction moveDirection;
    int growing;
    int tickCounter;
    int speed;
};

#endif // SNAKE_H
