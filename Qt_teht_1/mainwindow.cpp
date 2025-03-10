#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /* connect(lahettajanOsoite, lahettajanSignaaliFunktionOsoite,
                vastaanottajanOsoite, vastaanottajanSignaaliFunktionOsoite
    */
    connect(ui->pushCardNumber, &QPushButton::clicked,
            this, &MainWindow::handleCardButton);
    connect(ui->pushPinNumber, &QPushButton::clicked,
            this, &MainWindow::handlePinButton);

    reader = new Reader(this);
    connect(reader, &Reader::sendCardNumber,
            this, &MainWindow::handleCardNumber);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleCardButton()
{
    qDebug()<<"Card Button pressed";
    //reader->show();
    reader->open();
    //reader->exec();
    qDebug()<<"Suoritettiinko tama viela";
}

void MainWindow::handlePinButton()
{
    qDebug()<<"Pin Button pressed";
}

void MainWindow::handleCardNumber(QString s)
{
    qDebug()<<"Vastaanotettiin kortin numero";
    ui->cardNumber->setText(s);
}
