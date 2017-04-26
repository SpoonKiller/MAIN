#ifndef PAINTSCENE_H
#define PAINTSCENE_H


#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QImage>
#include <QPainter>

class paintscene : public QGraphicsScene
{

    Q_OBJECT

public:
    explicit paintscene(QObject *parent = 0);
    ~paintscene();

private:
    QPointF previousPoint;

private:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);

};

#endif // PAINTSCENE_H
