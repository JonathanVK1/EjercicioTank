#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    QTimer *timer;
    float b=0,a=0;
    int T=0;
    float caudi,cauds;


//comandos creados

public slots:

    void setRange(QString);
    void setValuerUp();
    void setValuerDw();
    void setValuerUpe(QString);
    void setValuerDwe(QString);
    void setTimer(QString);


};
#endif // MAINWINDOW_H
