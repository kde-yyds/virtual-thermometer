#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <ctime>
using namespace std;
double min_tep=36.5,max_tep=37.1;
int seed=114514;
int use_time=1;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_checkBox_use_current_time_stateChanged(int arg1)
{
    int state=ui->checkBox_use_current_time->checkState();
    //0==disabled  2==enabled
    int current_time=time(0);
    cout<<"[Debug] ui->checkBox_use_current_time->checkState() = "<<state;
    if(state==0) cout<<" ; use current time disabled"<<endl;
    else cout<<" ; use current time enabled , time = "<<current_time<<endl;
    if(state==0)
    {
        ui->horizontalSlider->setEnabled(true);
        seed=114514;
        ui->label_2->setNum(seed);
        use_time=0;
    }
    if(state==2)
    {
        seed=current_time;
        ui->horizontalSlider->setEnabled(false);
        use_time=1;
    }
}

double randtemperature(double min,double max)
{
    int min_int=min*10;
    int max_int=max*10;
    if(use_time==1) seed=time(0);
    srand(seed);
    cout<<"[Debug] srand ("<<seed<<")"<<endl;
    int randnum_int=(rand())%(max_int-min_int)+min_int;
    cout<<"[Debug] randnum_int = "<<randnum_int<<endl;
    double randnum=(double)randnum_int/(double)10;
    cout<<"[Debug] randnum = "<<randnum<<endl;
    return randnum;
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    int pos=ui->horizontalSlider->value();
    cout<<"[Debug] ui->horizontalSlider->value() = "<<pos<<endl;
    seed=pos;
    ui->label_2->setNum(seed);
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    int state=ui->checkBox->checkState();
    //0==normal,1==hot
    if(state==0)
    {
        min_tep=35.8;
        max_tep=38.1;
    }
    else
    {
        min_tep=38.2;
        max_tep=42.0;
    }
}


void MainWindow::on_pushButton_clicked()
{
    ui->temperature_label->setNum(randtemperature(min_tep,max_tep));
}

