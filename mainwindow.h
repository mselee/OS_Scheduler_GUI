#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QMainWindow>
#include <list>
#include "Scheduler.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnAddRow_clicked();

    void on_comboAlgorithm_currentIndexChanged(int index);

    void on_btnStart_clicked();

    void draw(list<Log*> log);

private:
    Ui::MainWindow *ui;
    QVBoxLayout* vLayout;
    QVBoxLayout* sim_vLayout;
    QWidget* sim_processes;
    QWidget* sim_timeline;
    QHBoxLayout* sim_hLayout1;
    QHBoxLayout* sim_hLayout2;
    int index = 0;
    Scheduler* scheduler;
};

#endif // MAINWINDOW_H
