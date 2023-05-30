#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"
#include <iostream>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    myTextField = ui->MyLineEdit;
    // Importing the game
    ZorkUL game;
    Console1 = ui->textBrowser_1; //Text output
    Console2 = ui->textBrowser_2;
    Console1->setPlainText(QString::fromStdString(game.printWelcome()));
    Console2->setPlainText(QString::fromStdString(game.printWelcome()));

    QObject::connect(myTextField, &QLineEdit::returnPressed, this, &MainWindow::onLineEditReturnPressed);
    //   Reference/Name on GUI, what sends the signal, 'this'=Current instanse of Main Window, the slot/function called
    QObject::connect(ui->north, &QPushButton::pressed, this, &MainWindow::onButtonPressed);
    QObject::connect(ui->south, &QPushButton::pressed, this, &MainWindow::onButtonPressed);
    QObject::connect(ui->east, &QPushButton::pressed, this, &MainWindow::onButtonPressed);
    QObject::connect(ui->west, &QPushButton::pressed, this, &MainWindow::onButtonPressed);

    QObject::connect(ui->quit, &QPushButton::pressed, this, &MainWindow::onProcessButtonPressed);
    QObject::connect(ui->info, &QPushButton::pressed, this, &MainWindow::onProcessButtonPressed);
    QObject::connect(ui->map, &QPushButton::pressed, this, &MainWindow::onProcessButtonPressed);
    QObject::connect(ui->inventory, &QPushButton::pressed, this, &MainWindow::onProcessButtonPressed);


//    connect(temp, SIGNAL(printOutput(string)), this, SLOT(printOutput(string)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::printOutput(string text){
//    ui->textBrowser->append(QString::fromStdString(text));
//}

void MainWindow::onLineEditReturnPressed(){
    QString text = myTextField->text();
    //                                       Parses the String as a command
    QString qstr = QString::fromStdString("\n" + game.nearlyProcessCommand(text.toStdString()));

    Console1->setText(qstr + Console1->toPlainText());
    Console2->setText(qstr + Console2->toPlainText());
    myTextField->setText("");
        }

void MainWindow::onButtonPressed(){
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString buttonName = button->objectName();
        // Converting String from qString to Regular String
        QString qstr = QString::fromStdString(game.go(buttonName.toStdString()));
        // Pushes what was text in cout, puts the returned text into the Console on the GUI
        Console1->setText(qstr + Console1->toPlainText());
        Console2->setText(qstr + Console2->toPlainText());

    }
}

void MainWindow::onProcessButtonPressed(){
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString buttonName = button->objectName();
        // Converting String from qString to Regular String
        QString qstr = QString::fromStdString(game.nearlyProcessCommand(buttonName.toStdString()));
        Console1->setText(qstr + "\n" + Console1->toPlainText());
        Console2->setText(qstr + "\n" + Console2->toPlainText());
    }
}
