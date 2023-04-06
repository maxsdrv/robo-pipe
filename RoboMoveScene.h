#ifndef ROBOPIPE_ROBOMOVESCENE_H
#define ROBOPIPE_ROBOMOVESCENE_H

#include <QtWidgets>

namespace roboscene {
// A class representing the circular pipe in which the robot moves
    class Pipe : public QGraphicsPixmapItem {
	public:
	  // Constructor taking a parent QGraphicsItem
        explicit Pipe(QGraphicsItem *parent = nullptr);
	  // Destructor
        ~Pipe() override { qDebug() << "~Pipe"; };
		// A method to rotate the pipe by a given angle
        void rotate_pipe(qreal angle);
	    // A method to check if the robot is out of the pipe bounds given a position
		[[nodiscard]] bool is_out_of_bounds(QPointF pos) const;

	private:
	  qreal pipe_radius; // The radius of the pipe
    };
// A class representing the robot
    class Robot : public QGraphicsPixmapItem {
	public:
	  // Constructor taking a parent QGraphicsItem
        explicit Robot(QGraphicsItem *parent = nullptr);
	  // Destructor
        ~Robot() override { qDebug() << "~Robot"; };

		// A method to move the robot to a new position
        void move_robot(QPointF n_pos);
		// A method to rotate the robot by a given angle
        void rotate_robot(qreal angle);
	private:
    };

// A class representing the widget
    class RoboWidget : public QGraphicsView {
	public:
	  // Constructor taking a parent QWidget
        explicit RoboWidget(QWidget *parent = nullptr);
	  // Destructor
        ~RoboWidget() override { qDebug() << "~RoboWidget"; }

	private:
		QGraphicsScene *scene; // The graphics scene
		std::unique_ptr<Pipe> pipe; //  Pipe object
		std::unique_ptr<Robot> robot; // Robot object

	protected:
	  // A method to handle key press event
	  void keyPressEvent(QKeyEvent *event) override;
    };
} // namespace roboscene

#endif //ROBOPIPE_ROBOMOVESCENE_H
