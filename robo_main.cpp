#include <iostream>

#include "RoboMoveScene.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    //Create the main window
    QMainWindow window;
    window.setWindowTitle("Robo Widget");

	//Create the robot widget
	roboscene::RoboWidget widget(&window);

	//Add the robot widget to the main window's central widget
	auto central_widget = new QWidget(&window);
	auto layout = new QVBoxLayout(central_widget);
	layout->addWidget(&widget);
	window.setCentralWidget(central_widget);

	window.show();

    return QApplication::exec();
}
