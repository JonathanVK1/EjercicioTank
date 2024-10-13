#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,caudi(0.0)
    ,cauds(0.0)
{
    ui->setupUi(this);
    timer = new QTimer(this);

    connect(ui->lineEdittime,
            SIGNAL(textChanged(QString)),
            this,
            SLOT(setTimer(QString)));

    connect(ui->horizontalSliderin,
            SIGNAL(slaiderMoved()),   // or valuedChanged is same
            this,
            SLOT(setValuerUp()));

    connect(ui->horizontalSliderout,
            SIGNAL(slaiderMoved()),     // or valuedChanged is same
            this,
            SLOT(setValuerDw()));

    connect(ui->lineEditcap,
            SIGNAL(textEdited(QString)), // cambio textChanged
            this,
            SLOT(setRange(QString)));

    connect(ui->lineEditin,
            SIGNAL(textChanged(QString)),
            this,
            SLOT(setValuerUpe(QString)));

    connect(ui->lineEditout,
            SIGNAL(textChanged(QString)),
            this,
            SLOT(setValuerDwe(QString)));

    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(setValuerUp()));

    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(setValuerDw()));

    /*connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(setValuerUpe(QString)));

    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(setValuerDwe(QString)));*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTimer(QString text){

    bool ok;
    int value=text.toInt(&ok);

    timer->start(value);

}

void MainWindow::setRange(QString text){

    bool ok;
    b=text.toInt(&ok);
    ui->Tank->setRange(0,b);

}

void MainWindow::setValuerUp(){

    float current_level=ui->horizontalSliderin->value();

    a=a+caudi*(current_level/100);
    ui->Tank->setValue(a);


}
void MainWindow::setValuerDw(){

    float current_levell=ui->horizontalSliderout->value();
    a=a-cauds*(current_levell/100);
    ui->Tank->setValue(a);

}

void MainWindow::setValuerUpe(QString text){
    bool ok;
    float f=text.toInt(&ok);
    caudi=f;
    //ui->horizontalSliderin->setValue(caudi);


}
void MainWindow::setValuerDwe(QString text){
    bool ok;
    float g=text.toInt(&ok);
    cauds=g;
    //ui->horizontalSliderout->setValue(cauds);


}
