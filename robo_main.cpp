#include <iostream>

#include "RoboWidget.h"


int main(int argc, char** argv) {
    QApplication app(argc, argv);

    //Create the main window
    QMainWindow window;
    window.setWindowTitle("Robo Widget");

    //Create the robot widget
    RoboWidget robo(&window);
    robo.setFocusPolicy(Qt::StrongFocus);

    //Add the robot widget to the main window's central widget
    auto central_widget = new QWidget(&window);
    auto layout = new QVBoxLayout(central_widget);
    layout->addWidget(&robo);
    window.setCentralWidget(central_widget);

    window.show();

    return QApplication::exec();
}
