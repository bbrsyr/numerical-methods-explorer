#include "ui_mainwindow.h"
#include "mainwindow.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    plotWidget = new PlotWidget(this);

    auto* layout = new QVBoxLayout(ui->plotContainer);
    layout->addWidget(plotWidget);

    connect(
        ui->nextButton,
        &QPushButton::clicked,
        this,
        &MainWindow::nextIteration
        );

    connect(
        ui->previousButton,
        &QPushButton::clicked,
        this,
        &MainWindow::previousIteration
        );
}


void MainWindow::updatePlot() {
    plotWidget->clear();

    plotWidget->plotFunction(function, -2, 6, 0.01);

    plotWidget->plotNewtonSteps(history, currentIteration);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_plotButton_clicked()
{
    FunctionEvaluator function;

    QString expression = ui->FunctionInputLineEdit->text();

    if (function.setExpression(expression.toStdString())) {
        plotWidget->plotFunction(function, -2, 6, 0.01);
    }
}

void MainWindow::previousIteration() {
    if (currentIteration > 0) {
        currentIteration--;
        updatePlot();
    }
}

void MainWindow::nextIteration() {
    if (currentIteration < history.size() - 2) {
        currentIteration++;
        updatePlot();
    }

}

