#pragma once


#include <QMainWindow>
#include "../include/PlotWidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    PlotWidget* plotWidget;

private slots:
    void on_plotButton_clicked();
};

