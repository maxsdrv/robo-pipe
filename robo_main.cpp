#include <iostream>

#include "RoboWidget.h"
#include "Projectile.h"
#include "RoboMoveScene.h"


int main(int argc, char** argv) {
    QApplication app(argc, argv);

    //Create the main window
    QMainWindow window;
    window.setWindowTitle("Robo Widget");

    //Create the robot widget
//    RoboWidget robo(&window);
//    robo.setFocusPolicy(Qt::StrongFocus);

    //Add the robot widget to the main window's central widget
//    auto central_widget = new QWidget(&window);
//    auto layout = new QVBoxLayout(central_widget);
//    layout->addWidget(&robo);
//    window.setCentralWidget(central_widget);

    /*QGraphicsScene scene(-50, -50, -100, 100);

    auto projectile = std::make_unique<Projectile>(45 * M_PI / 180, 10);
    scene.addItem(projectile.get());

    QGraphicsView view(&scene);
    view.show();

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &scene, &QGraphicsScene::advance);
    timer.start(10);*/


//    window.show();

	roboscene::RoboWidget widget(&window);
	auto central_widget = new QWidget(&window);
	auto layout = new QVBoxLayout(central_widget);
	layout->addWidget(&widget);
	window.setCentralWidget(central_widget);

	window.show();

    return QApplication::exec();
}
