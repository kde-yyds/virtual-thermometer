#pragma once

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

private slots:
    void on_checkBox_use_current_time_stateChanged(int arg1);

    void on_horizontalSlider_sliderMoved(int position);

    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
