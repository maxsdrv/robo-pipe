#include <QCommandLineParser>
#include <random>

#include "RoboMoveScene.h"
#include "SensorWidget.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

	QCommandLineParser parser;
	parser.setApplicationDescription("Test task for TARIS company");

	QCommandLineOption app_robo_pipe("robo-pipe",
									 "Widget for displaying movements "
									 "of robot in pipe");
	QCommandLineOption app_sensor_widget("sensor-widget",
										 "Data of sensor which are displaying like circle");
	parser.addHelpOption();
	parser.addOption(app_robo_pipe);
	parser.addOption(app_sensor_widget);
	parser.process(app);

	if (parser.isSet("robo-pipe")) {
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

	} else if (parser.isSet("sensor-widget")) {
		qDebug() << "Sensor widget";
		std::map<double, double> data;
		//Create a random number generator
		std::random_device rd;
		std::mt19937 gen(rd());

		//Define the ranges for the random numbers
		std::uniform_real_distribution<> dist_angle(0, 2 * M_PI); // range (0, 2pi)
		std::uniform_real_distribution<> dist_d(0, 200); // range (0, 200)

		//Generate the random data and add it to the map
		for (int i = 0; i < 10; ++i) {
			double angle = dist_angle(gen);
			double distance = dist_d(gen);
			data[angle] = distance;
		}

		SensorWidget sensor_widget(std::move(data));
		sensor_widget.show();
		return QApplication::exec();
	}
	else  parser.showHelp();

}
