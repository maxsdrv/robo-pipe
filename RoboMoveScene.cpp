#include "RoboMoveScene.h"

using namespace roboscene;

namespace {
	const uint16_t PIPE_IMAGE_HEIGHT = 503;
	const uint16_t PIPE_IMAGE_WIDTH = 503;
};

Robot::Robot(QGraphicsItem *parent) : QGraphicsPixmapItem
										  (QPixmap("images/Widget_test/RobBack.png"),parent) {
	setTransformOriginPoint(QGraphicsPixmapItem::boundingRect().center());

	QPointF offset(-QGraphicsPixmapItem::boundingRect().width() / 2,
				   -QGraphicsPixmapItem::boundingRect().height()/ 2);
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
										radius(QGraphicsPixmapItem::boundingRect().width() / 2){
	setTransformOriginPoint(QGraphicsPixmapItem::boundingRect().center());

	QPointF offset(-QGraphicsPixmapItem::boundingRect().width() / 2,
				   -QGraphicsPixmapItem::boundingRect().height()/ 2);
	setPos(pos() + offset);
}

void Pipe::rotate_pipe(qreal angle) {
	setRotation(angle);
}
bool Pipe::is_out_of_bounds(QPointF pos) const {
	QPointF center = mapToParent(QGraphicsPixmapItem::boundingRect().center());
	qreal distance = QLineF(center, pos).length();
	return distance > radius;

}
bool Pipe::is_bounds() const {
	auto pipe_radius = qMin(PIPE_IMAGE_WIDTH, PIPE_IMAGE_HEIGHT) / 2;
	QPointF distance = mapToParent(pos()) - QPointF(0, 0);
	qreal distance_squared = distance.x() * distance.x() + distance.y() * distance.y();

	return distance_squared > pipe_radius * pipe_radius;
}

RoboWidget::RoboWidget(QWidget *parent) : QGraphicsView(parent),
									      pipe(std::make_unique<Pipe>()),
										  robot(std::make_unique<Robot>())
{
	scene = new QGraphicsScene(this);
	setScene(scene);
	setFixedSize(PIPE_IMAGE_WIDTH, PIPE_IMAGE_HEIGHT);

	scene->addItem(pipe.get());
	scene->addItem(robot.get());

}
void RoboWidget::keyPressEvent(QKeyEvent *event) {
	const qreal step = 5;
	const qreal rotation_step = 2;
	QPointF old_pos = pos();

	switch (event->key()){
		case Qt::Key_Left:
			if (!pipe->is_out_of_bounds(robot->pos() - QPointF(step, 0)))
				robot->move_robot(robot->pos() - QPointF(step, 0));
			break;
		case Qt::Key_Right:
			if (!pipe->is_out_of_bounds(robot->pos() + QPointF(step,   0)))
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













