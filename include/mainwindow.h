#pragma once


#include <QMainWindow>
#include "../include/PlotWidget.h"
#include "../include/FunctionEvaluator.h"
#include "../include/NewtonMethod.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    void updatePlot();

    ~MainWindow() override;

private:

    int currentIteration = 0;

    Ui::MainWindow *ui;

    PlotWidget* plotWidget;

    FunctionEvaluator function;
    NewtonMethod* newt;

    std::vector<IterationData> history;

private slots:
    void on_plotButton_clicked();
    void previousIteration();
    void nextIteration();
};

