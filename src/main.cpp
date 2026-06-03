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

    FunctionEvaluator evaluator;

    evaluator.setExpression("x*x - 2");

    NewtonMethod newt(&evaluator, 1);

    GradientDescent gd(&evaluator, 1.5);

    std::cout << std::endl << "Newton's Method";

    while(!newt.converged()) {
        newt.step();

        auto state = newt.currentState();

        std::cout << "Iteration: " << state.iteration
                  << "  x: " << state.x
                  << "  f(x): " <<state.fx
                  << "  Error: "<<state.error << std::endl;

    }

    std::cout << std::endl << "Gradient Descent";

    while(!gd.converged()) {
        gd.step();

        auto state = gd.currentState();

        std::cout << "Iteration: " << state.iteration
                  << "  x: " << state.x
                  << "  f(x): " <<state.fx
                  << "  Error: "<<state.error << std::endl;
    }

    MainWindow w;
    w.show();
    return QCoreApplication::exec();
}
