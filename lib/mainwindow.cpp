#include "mainwindow.h"
#include "ownexception.h"
#include <QGuiApplication>
#include <QMessageBox>
#include <QSettings>
#include <QImageReader>
#include <QImage>
#include <QDebug>

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // settings for position and size of window
    setUnifiedTitleAndToolBarOnMac(true);
    QSettings settings("6 nimmt!", "6nimmt!");
    QPoint pos = settings.value("pos", QPoint(70, 70)).toPoint();
    QSize size = settings.value("size", QSize(300, 400)).toSize();
    resize(size);
    move(pos);

    // background of window
    QPixmap bkgnd(":/background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);

    // add widgets
    QLabel *header = new QLabel("Корова 006", this);
    header->setGeometry(80, 80, 150, 200);
    QPixmap logo(":/cards/6.png");
    logo = logo.scaledToHeight(200);
    header->setPixmap(logo);

    toDelete.push_back(header);

    QPushButton *button = new QPushButton("Start a game", this);
    button->setGeometry(80, 280, 150, 40);
    toDelete.push_back(button);

    /*QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView(scene);

    QBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(view);

    QGraphicsRectItem *rect = new QGraphicsRectItem();
    rect->setRect(200, 200, 100, 100);
    scene->addItem(rect);

    setCentralWidget(view);*/

    /*QGraphicsRectItem *rect = new QGraphicsRectItem();
    rect->setRect(200, 200, 100, 100);

    scene->addItem(rect);

    QGraphicsView *view = new QGraphicsView(scene);

    view->show();*/
}

MainWindow::~MainWindow() {
    for(size_t i = 0; i < toDelete.size(); i++) {
        if(toDelete[i] != NULL) delete toDelete[i];
    }
}
