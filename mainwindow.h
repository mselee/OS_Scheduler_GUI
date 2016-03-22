#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVBoxLayout>
#include <QLineEdit>
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

private:
    Ui::MainWindow *ui;
    QVBoxLayout* vLayout;
    int index = 0;
    Scheduler* scheduler;
};

#endif // MAINWINDOW_H
