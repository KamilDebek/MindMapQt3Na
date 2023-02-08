#ifndef DRAGANDDROP_H
#define DRAGANDDROP_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
class DragAndDrop : public QGraphicsRectItem
{
public:
    DragAndDrop(QGraphicsItem* parent = 0);
    void setAnchorPoint(const QPointF& anchorPoint);
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    QPointF anchorPoint;
    bool dragged;
};

#endif // DRAGANDDROP_H
