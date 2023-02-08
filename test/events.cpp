#include "events.h"

Events::Events()
{

}

Custom_Graphics_View::Custom_Graphics_View(QWidget *widget) : QGraphicsView(widget)
{
    setAcceptDrops(true);
}

void Custom_Graphics_View::dropEvent(QDropEvent *event)
{
    if (event->source() == this) return;
    QListWidget *listWidget = qobject_cast<QListWidget*>(event->source());
    QString Image_Path = listWidget->currentItem()->text();
    emit itemDrop(Image_Path);
}

void Custom_Graphics_View::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
    event->acceptProposedAction();

}

void Custom_Graphics_View::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
}

void Custom_Graphics_View::dragMoveEvent(QDragMoveEvent *event)
{
    event->accept();
    event->acceptProposedAction();
}
