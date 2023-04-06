#include "RoboMoveScene.h"

using namespace roboscene;

Robot::Robot(QGraphicsItem *parent) : QGraphicsPixmapItem
										  (QPixmap("images/Widget_test/RobBack.png"), parent) {
	setTransformOriginPoint(QGraphicsPixmapItem::boundingRect().center());

	// Move the robot to the center of the scene
	QPointF offset(-QGraphicsPixmapItem::boundingRect().width() / 2,
				   -QGraphicsPixmapItem::boundingRect().height() / 2);
	setPos(pos() + offset);

}

void Robot::move_robot(QPointF n_pos) {
	setPos(n_pos);
}

void Robot::rotate_robot(qreal angle) {
	setRotation(angle);
}

Pipe::Pipe(QGraphicsItem *parent) : QGraphicsPixmapItem
										(QPixmap("images/Widget_test/RobotCircle.png"), parent),
										pipe_radius(QGraphicsPixmapItem::boundingRect().width() / 2){
	setTransformOriginPoint(QGraphicsPixmapItem::boundingRect().center());

	// Move the pipe to the center of the scene
	QPointF offset(-QGraphicsPixmapItem::boundingRect().width() / 2,
				   -QGraphicsPixmapItem::boundingRect().height()/ 2);
	setPos(pos() + offset);
}

void Pipe::rotate_pipe(qreal angle) {
	setRotation(angle);
}
bool Pipe::is_out_of_bounds(QPointF pos) const {
	// Calculate the bounding rectangle of the pipe
	auto bounds = QRectF(pipe_radius, pipe_radius, -pipe_radius, -pipe_radius);
	QPointF n_center = mapToParent(bounds.center());
	qreal n_distance = QLineF(n_center, pos).length();
	return n_distance > pipe_radius;
}

RoboWidget::RoboWidget(QWidget *parent) : QGraphicsView(parent),
									      pipe(std::make_unique<Pipe>()),
										  robot(std::make_unique<Robot>())
{
	// Displaying the contents of a QGraphicsScene
	scene = new QGraphicsScene(this);
	setScene(scene);
	setFixedSize(pipe->pixmap().size());
	scene->addItem(pipe.get()); // Display pipe
	scene->addItem(robot.get()); // Display robot
}
void RoboWidget::keyPressEvent(QKeyEvent *event) {
	const qreal step = 5; // step size of robot
	const qreal rotation_step = 2; // rotate step of robot
	// Checking out of bounds and move
	switch (event->key()){
		case Qt::Key_Left:
			if (!pipe->is_out_of_bounds(robot->pos() - QPointF(step, 0)))
				robot->move_robot(robot->pos() - QPointF(step, 0));
			break;
		case Qt::Key_Right:
			if (!pipe->is_out_of_bounds((robot->pos() + QPointF(step,   0))))
				robot->move_robot(robot->pos() + QPointF(step, 0));
			break;
		case Qt::Key_Up:
			if (!pipe->is_out_of_bounds(robot->pos() - QPointF(0, step)))
				robot->move_robot(robot->pos() - QPointF(0, step));
			break;
		case Qt::Key_Down:
			if (!pipe->is_out_of_bounds(robot->pos() + QPointF(0, step)))
				robot->move_robot(robot->pos() + QPointF(0, step));
			break;
		case Qt::Key_Q:
			pipe->rotate_pipe(pipe->rotation() + rotation_step);
			robot->rotate_robot(robot->rotation() + rotation_step);
			break;
		case Qt::Key_E:
			pipe->rotate_pipe(pipe->rotation() - rotation_step);
			robot->rotate_robot(robot->rotation() - rotation_step);
			break;
		default:
			QGraphicsView::keyPressEvent(event);
	}

	update();
}













