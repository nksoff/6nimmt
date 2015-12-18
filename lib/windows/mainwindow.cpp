#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), gameWindow(NULL)
{
    setUnifiedTitleAndToolBarOnMac(true);
    QSettings settings(MainWindow::APP_NAME, MainWindow::APP_NAME);
    QPoint pos = settings.value("pos", MainWindow::DEFAULT_POSITION).toPoint();
    QSize size = settings.value("size", QSize(MainWindow::DEFAULT_WIDTH, MainWindow::DEFAULT_HEIGHT)).toSize();
    resize(size);
    move(pos);


    QPixmap bkgnd(MainWindow::BACKGROUND_FILE);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);


    QLabel *header = new QLabel(this);
    checkNullPointer(header);
    header->setGeometry(MainWindow::PIC_LOGO_X,
                        MainWindow::PIC_LOGO_Y,
                        MainWindow::PIC_LOGO_WIDTH,
                        MainWindow::PIC_LOGO_HEIGHT);
    QPixmap logo(MainWindow::PIC_LOGO);
    logo = logo.scaledToHeight(MainWindow::PIC_LOGO_HEIGHT);
    header->setPixmap(logo);

    toDelete.push_back(header);

    QPushButton *button = new QPushButton(MainWindow::START_GAME, this);
    checkNullPointer(button, [=]() {
        delete header;
    });
    button->setGeometry(header->geometry().x(),
                        header->geometry().bottom(),
                        header->geometry().width(),
                        MainWindow::START_GAME_BUTTON_HEIGHT);
    connect(button, SIGNAL(clicked()), this, SLOT(startNewGame()));
}

MainWindow::~MainWindow()
{
    for(size_t i = 0; i < toDelete.size(); i++)
    {
        if(toDelete[i] != NULL)
        {
            delete toDelete[i];
        }
    }
}

void MainWindow::startNewGame()
{
    gameWindow = new GameWindow;
    checkNullPointer(gameWindow);
    gameWindow->show();
    toDelete.push_back(gameWindow);
}
