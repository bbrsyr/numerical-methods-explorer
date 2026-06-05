#include "../include/mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>

#include "../include/PlotWidget.h"
#include "../include/NewtonMethod.h"
#include "../include/GradientDescent.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "NumericalMethodsExplorer_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    FunctionEvaluator* function = new FunctionEvaluator();
    function->setExpression("x^2 - x - 2");

    NewtonMethod newt(function, 5);
    PlotWidget* plot = new PlotWidget();

    plot->plotFunction(*function, -2, 6, 0.01);


    while (!newt.converged()) {
        newt.step();

        // auto state = newt.currentState();

        // std::cout << "Iteration: " << state.iteration << " ";
        // std::cout << "x: " << state.x << " ";
        // std::cout << "dfx: " << state.derivative << " ";
        // std::cout << "Error: " << state.error << std::endl;
    }

    for (const auto& step : newt.getHistory()) {
        std::cout << step.iteration << " "
                  << step.x << " "
                  << step.fx << " "
                  << std::endl;
    }

    plot->plotHistory(newt.getHistory());

    plot->plotNewtonSteps(newt.getHistory());

    plot->show();

    //MainWindow w;
    //w.show();
    return a.exec();
}
