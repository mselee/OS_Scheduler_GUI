#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    vLayout = new QVBoxLayout();
    sim_vLayout = new QVBoxLayout();
    ui->scrollAreaWidgetContents->setLayout(vLayout);
    ui->scrollAreaWidgetContents_2->setLayout(sim_vLayout);
    sim_vLayout->setAlignment(Qt::AlignTop);
    sim_vLayout->setMargin(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAddRow_clicked()
{

    QWidget *horizontalWidget = new QWidget();
    QHBoxLayout *hLayout = new QHBoxLayout(horizontalWidget);

    QLineEdit* le1 = new QLineEdit(horizontalWidget);
    QLineEdit* le2 = new QLineEdit(horizontalWidget);
    QLineEdit* le3 = new QLineEdit(horizontalWidget);

    le1->setObjectName("arrival-" + QString::number(index));
    le2->setObjectName("burst-" + QString::number(index));
    le3->setObjectName("priority-" + QString::number(index));
    le3->setText("0");

    hLayout->addWidget(le1);
    hLayout->addWidget(le2);
    hLayout->addWidget(le3);

    vLayout->addWidget(horizontalWidget);
    index++;
}

void MainWindow::on_comboAlgorithm_currentIndexChanged(int index)
{
    if (index == 1 || index == 2)
        ui->comboPremp->setEnabled(true);
    else
        ui->comboPremp->setEnabled(false);
    if (index == 3)
        ui->gboxQuantum->setEnabled(true);
    else
        ui->gboxQuantum->setEnabled(false);
}

void MainWindow::on_btnStart_clicked()
{
    list<Process*> processes;
    for (int i = 0; i < index; ++i) {

        double arrival = ui->scrollAreaWidgetContents->findChild<QLineEdit*>("arrival-" + QString::number(i))->text().toDouble();
        double burst = ui->scrollAreaWidgetContents->findChild<QLineEdit*>("burst-" + QString::number(i))->text().toDouble();
        double priority = ui->scrollAreaWidgetContents->findChild<QLineEdit*>("priority-" + QString::number(i))->text().toDouble();

        Process* p = new Process(i, arrival, burst, priority);
        processes.push_back(p);
    }

    scheduler = new Scheduler(processes);

    switch (ui->comboAlgorithm->currentIndex()) {
    case 0:
        scheduler->fcfs();
        break;
    case 1:
        scheduler->sjf(ui->comboPremp->currentIndex());
        break;
    case 2:
        scheduler->priority(ui->comboPremp->currentIndex());
        break;
    case 3:
        scheduler->roundRobin(ui->txtQuantum->text().toDouble());
        break;
    default:
        break;
    }

    draw(scheduler->getLog());
}

void MainWindow::draw(list<Log*> log) {

    for(list<Log*>::iterator it = log.begin();it != log.end(); ++it){
        double start = (*it)->startTime();
        double finish = (*it)->finishTime();
        QWidget *horizontalWidget = new QWidget();
        QHBoxLayout *hlayout = new QHBoxLayout(horizontalWidget);

        QWidget* process = new QWidget(horizontalWidget);
        double period = finish - start;
        string colour = (*it)->colour();

        process->setFixedHeight(10);
        process->setFixedWidth(start + period);
        process->setStyleSheet(QString::fromStdString("margin-left: " + to_string(start) + ";" + "background-color: " + colour + ";"));


        hlayout->setAlignment(Qt::AlignLeft);

        hlayout->addWidget(process);

        sim_vLayout->addWidget(horizontalWidget);
    }
}
