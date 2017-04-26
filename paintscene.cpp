#include "paintscene.h"

paintscene::paintscene(QObject *parent) : QGraphicsScene(parent)
{
}

paintscene::~paintscene()
{

}

void paintscene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // При нажатии кнопки мыши отрисовываем эллипс
    addEllipse(event->scenePos().x() - 5,
               event->scenePos().y() - 5,
               10,
               10,
               QPen(Qt::NoPen),
               QBrush(Qt::black));
    // Сохраняем координаты точки нажатия
    previousPoint = event->scenePos();
}

void paintscene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
        addLine(previousPoint.x(),
                previousPoint.y(),
                event->scenePos().x(),
                event->scenePos().y(),
                QPen(Qt::black,10,Qt::SolidLine,Qt::RoundCap));
        previousPoint = event->scenePos();
}

