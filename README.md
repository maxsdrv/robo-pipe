

# RoboPipe

RoboPipe is a Qt-based application that simulates a robot moving inside a circular pipe. The application consists of three classes: Pipe, Robot, and RoboWidget.

# Pipe Class
The Pipe class represents the circular pipe in which the robot moves. It inherits from the QGraphicsPixmapItem class, and has a constructor that takes a QGraphicsItem parent object. It also has a rotate_pipe() method that takes an angle as input and rotates the pipe accordingly. Additionally, the is_out_of_bounds() method takes a QPointF position and checks if the robot is outside of the pipe bounds.

# Robot Class
The Robot class represents the robot in the application. It also inherits from the QGraphicsPixmapItem class, and has a constructor that takes a QGraphicsItem parent object. The move_robot() method takes a new position and moves the robot to that position. The rotate_robot() method takes an angle and rotates the robot accordingly.

# RoboWidget Class
The RoboWidget class represents the widget in which the simulation takes place. It inherits from the QGraphicsView class, and has a constructor that takes a QWidget parent object. The class has a QGraphicsScene object, a Pipe object, and a Robot object. It also has a keyPressEvent() method that handles key press events.

# Installation
To use this application, you will need to have Qt installed on your system. Once you have Qt installed, you can download the source code and build the application using Qt Creator.

# Usage
To use the application, simply run the executable file. The robot can be moved using the arrow keys on the keyboard, and can be rotated using the left and right arrow keys.


# Sensor Data Visualization
This project is a data visualization tool that takes in an array of sensor data consisting of angle and distance values, and displays the data as a circle on the screen. The points are sorted by angle and the angle values are unique.

The tool is built using C++ and the Qt framework. It can handle a variable number of data points, with a maximum of 4096. The axis of rotation of the sensors does not coincide with the center of the circle, which is taken into account when generating the circle.

The user interface displays the circle with the diameter indicated, providing a clear visualization of the sensor data. In addition, the tool includes a data filtering function to handle any false or erroneous data points.

To generate input data, the project uses the Qt framework, allowing for a wide range of input data types. The output can be easily customized and visualized, providing a powerful tool for analyzing and understanding sensor data.

# Getting Started
To get started with this project, you will need to clone the repository to your local machine and install Qt. You can then run the project using your preferred IDE or build system.

# Dependencies
This project requires the following dependencies:

. Qt

# Usage
To use this project, do the following:

Input the sensor data
Apply any necessary data filtering
Visualize the circle and diameter

# Building with CMake
To build the RoboPipe project, you will need to have CMake and Qt5 installed on your system. Once you have these dependencies installed, follow the steps below to build the project:

Clone the repository to your local machine.
Open a terminal window and navigate to the root directory of the project.
Create a build directory: mkdir build && cd build
Configure the project using CMake: cmake ..
Build the project: cmake --build .

# Contributors
This project was created by [HorMad]. If you would like to contribute to the project, please submit a pull request.

# Acknowledgments
This project was inspired by the need for a simple, yet powerful tool for visualizing and analyzing sensor data. Thanks to the Qt framework for providing a flexible and versatile platform for building graphical user interfaces.
