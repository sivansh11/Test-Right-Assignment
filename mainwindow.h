#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <csv.hpp>

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
    csv::CSVReader *csvReader;

private slots:
    void makePlot();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
