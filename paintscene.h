#ifndef PAINTSCENE_H
#define PAINTSCENE_H


#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class paintscene : public QGraphicsScene
{

    Q_OBJECT

public:
    explicit paintscene(QObject *parent = 0);
    ~paintscene();
    std::vector<std::vector<int> > img;

private:
    QPointF previousPoint;

private:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);

};

#endif // PAINTSCENE_H
