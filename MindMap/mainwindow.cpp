#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "draganddrop.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QSizePolicy>
#include <QMouseEvent>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QSizePolicy *viewSize = new QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    viewSize->setHorizontalStretch(80);
    ui->setupUi(this);
    QRectF rect(0,0,80,40);
    DragAndDrop* dItem = new DragAndDrop;
    dItem->setRect(rect);
    dItem->setBrush(QBrush(QColor("#ffa07a")));
    dItem->setPos(30,100);
    dItem->setAnchorPoint(dItem->pos());
}

MainWindow::~MainWindow()
{
    delete ui;
}

