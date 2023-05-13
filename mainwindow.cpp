#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myTextField = ui->MyLineEdit;
    ZorkUL temp;
    Console = ui->textBrowser;
    Console->setPlainText(QString::fromStdString(temp.printWelcome()));


    QObject::connect(myTextField, &QLineEdit::returnPressed, this, &MainWindow::onLineEditReturnPressed);
    //           Reference on GUI    If Pressed  'this'=Current Window
    QObject::connect(ui->north, &QPushButton::pressed, this, &MainWindow::onButtonPressed);
    QObject::connect(ui->south, &QPushButton::pressed, this, &MainWindow::onButtonPressed);
    QObject::connect(ui->east, &QPushButton::pressed, this, &MainWindow::onButtonPressed);
    QObject::connect(ui->west, &QPushButton::pressed, this, &MainWindow::onButtonPressed);

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
    QString qstr = QString::fromStdString("\n" + temp.go(text.toStdString()));

    Console->setText(Console->toPlainText() + qstr);
    myTextField->setText("");
        }

void MainWindow::onButtonPressed(){
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString buttonName = button->objectName();
        // Converting String from qString to Regular String
        QString qstr = QString::fromStdString(temp.go(buttonName.toStdString()));
        // Pushes what was text in cout, puts the returned text into the Console on the GUI
        Console->setText(qstr);

    }
}
