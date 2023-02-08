#include "draganddrop.h"

DragAndDrop::DragAndDrop(QGraphicsItem* parent):
    QGraphicsRectItem(parent), dragged(false)
{
    setAcceptDrops(true);
    setFlags(QGraphicsItem::ItemIsSelectable|
                 QGraphicsItem::ItemIsMovable);
}
void DragAndDrop::setAnchorPoint(const QPointF& anchorPoint)
{
    this->anchorPoint = anchorPoint;
}
void DragAndDrop::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    dragged = true;
    QGraphicsRectItem::mouseMoveEvent(event);
}

void DragAndDrop::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(dragged)
    {
        this->setPos(this->x(), this->y());
    }
    dragged = false;
    QGraphicsRectItem::mouseReleaseEvent(event);
}
