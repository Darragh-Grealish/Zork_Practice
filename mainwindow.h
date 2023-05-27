#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QTextBrowser>
#include "ZorkUL.h"
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLineEdit *myTextField;
    QTextBrowser *Console1;
//    QTextBrowser *Console2;
    QPushButton *goUp;
    // Global variable, avaliable for all functions in cpp
    ZorkUL game;
    Parser parser;

private slots: // Recieve signals
    void onLineEditReturnPressed();
    void onButtonPressed();
    void onProcessButtonPressed();
//    void printOutput(string text);
};
#endif // MAINWINDOW_H
