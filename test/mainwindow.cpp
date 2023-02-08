#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDir Image_Dir(QCoreApplication::applicationDirPath() + "/Images/");
    for (const QFileInfo &fileinfo : Image_Dir.entryInfoList(QDir::Files))
    {
        ui->listWidgetImage->addItem(fileinfo.absoluteFilePath());
    }
    Scene = new QGraphicsScene(this);
    connect(ui->graphicsView,SIGNAL(itemDrop(QString)), this, SLOT(graphicsViewEnter(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::graphicsViewEnter(QString ImagePath)
{
    qDebug()<< ImagePath;
    if (Scene->items().count() > 0) Scene->clear();
    QPixmap Image(ImagePath);
    Scene->addPixmap(Image);
    Scene->setSceneRect(Image.rect());
    ui->graphicsView->setScene(Scene);
    ui->graphicsView->setSceneRect(Scene->sceneRect());
    ui->graphicsView->viewport()->update();
    ui->graphicsView->update();
    ui->graphicsView->show();
}

