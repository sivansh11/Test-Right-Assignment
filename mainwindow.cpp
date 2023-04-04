#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString fileName = QFileDialog::getOpenFileName(this, {}, {}, {"*csv"});
    csvReader = new csv::CSVReader{fileName.toStdString()};

    MainWindow::makePlot();
}

MainWindow::~MainWindow()
{
    delete csvReader;
    delete ui;
}

void MainWindow::makePlot()
{
//    // generate some data:
//    QVector<double> x(101), y(101); // initialize with entries 0..100
//    for (int i=0; i<101; ++i)
//    {
//      x[i] = i/50.0 - 1; // x goes from -1 to 1
//      y[i] = x[i]*x[i]; // let's plot a quadratic function
//    }

    QVector<double> X, Y;
    for (auto& row: *csvReader) {
        std::cout << row[0].get<>() << ' ' << row[1].get<>() << ' ' << row[2].get<>() << '\n';
        X.push_back(row[1].get<double>());
        Y.push_back(row[2].get<double>());
    }

    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->setInteractions(QCP::Interaction::iRangeDrag | QCP::Interaction::iRangeZoom);
    ui->customPlot->graph(0)->setData(X, Y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(-10, 10);
    ui->customPlot->yAxis->setRange(-100, 100);
    ui->customPlot->replot();

}
