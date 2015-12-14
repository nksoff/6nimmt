#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <vector>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    std::vector<QWidget *> toDelete;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
