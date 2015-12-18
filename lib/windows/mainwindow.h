#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "lib/main.h"

#include "lib/windows/gamewindow.h"

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QGuiApplication>
#include <QMessageBox>
#include <QSettings>
#include <QImage>
#include <QDebug>

#include <vector>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    const QString APP_NAME = "6 nimmt!";
    const QString BACKGROUND_FILE = ":/background.jpg";
    const QPoint  DEFAULT_POSITION = QPoint(70, 70);
    const int DEFAULT_WIDTH = 300;
    const int DEFAULT_HEIGHT = 400;

    const int PIC_LOGO_X = 80;
    const int PIC_LOGO_Y = 80;
    const int PIC_LOGO_WIDTH = 150;
    const int PIC_LOGO_HEIGHT = 200;
    const QString PIC_LOGO = ":/cards/6.png";

    const QString START_GAME = "Start a new game";
    const int START_GAME_BUTTON_HEIGHT = 40;

    std::vector<QWidget *> toDelete;
    GameWindow *gameWindow;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void startNewGame();
};

#endif // MAINWINDOW_H
