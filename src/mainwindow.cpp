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
        plotWidget->plotFunction(function, -10, 10, 0.1);
    }
}

