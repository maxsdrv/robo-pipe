#include "RoboWidget.h"

namespace {
	int WIDTH = 640;
	int HEIGHT = 480;
}


RoboWidget::RoboWidget(QWidget *parent) : QWidget(parent), m_robo_pos(QPointF(0, 0)),
														   m_pipe_pos(QPointF(0, 0)),
										  				   m_robo_tilt_angle(0),
														   m_pipe_radius(0),
														   m_robo_speed(5),
														   m_robo_radius(0),
														   m_move_direction(0)
{

    // Load the pipe and robot images
    m_pipe_image.load("images/Widget_test/RobotCircle.png");
    if (m_pipe_image.isNull()) {
        qWarning() << "Error load pipe image";
    }

    m_robo_image.load("images/Widget_test/RobBack.png");
    if (m_robo_image.isNull()) {
        qDebug() << "Error load robo image";
    }

	setFixedSize(WIDTH, HEIGHT);

	m_pipe_radius = m_pipe_image.width() / 2.0;
	m_robo_radius = m_robo_image.width() / 2.0;
}
void RoboWidget::paintEvent(QPaintEvent *event) {
	QPainter painter(this);

	painter.save();

	painter.drawImage(m_pipe_pos, m_pipe_image);

	QTransform transform;
	transform.translate(m_robo_pos.x() + m_robo_radius, m_robo_pos.y() + m_robo_radius);
	transform.rotate(m_robo_tilt_angle);
	transform.translate(-m_robo_radius, -m_robo_radius);

	QImage robo_image = m_robo_image.transformed(transform, Qt::SmoothTransformation);
	painter.drawImage(m_robo_pos - QPointF(m_robo_radius, m_robo_radius), robo_image);

//	painter.drawImage(m_robo_pos, m_robo_image);

	painter.restore();

}
void RoboWidget::keyPressEvent(QKeyEvent *event) {
	switch (event->key()) {
		case Qt::Key_Left:
			m_move_direction = -1;
			update_robot_position();
			break;
		case Qt::Key_Right:
			m_move_direction = 1;
			update_robot_position();
			break;
	}
	update();
}
void RoboWidget::resizeEvent(QResizeEvent *event) {
	QPointF center(width() / 2.0, height() / 2.0);
	m_robo_pos = center - QPointF(m_robo_image.width() / 2.0, m_robo_image.height() / 2.0);
	m_pipe_pos = center - QPointF(m_pipe_image.width() / 2.0, m_pipe_image.height() / 2.0);

	m_robo_image = m_robo_image.scaledToWidth(width() * 0.2, Qt::SmoothTransformation);
	m_pipe_image = m_pipe_image.scaledToWidth(width() * 0.6, Qt::SmoothTransformation);

}
void RoboWidget::update_robot_position() {
	QPointF new_pos = m_robo_pos + QPointF(m_robo_speed * m_move_direction, 0);

	// Calculate the distance between the robot and the pipe
	qreal dist = QLineF(new_pos, m_pipe_pos).length();

	m_robo_pos = new_pos;
//	if (dist > m_pipe_radius - m_robo_radius) {
//		// If the robot would move outside the pipe, adjust its position and tilt angle
//		qreal angle = qRadiansToDegrees(qAtan2(new_pos.y() - m_pipe_pos.y(), new_pos.x() - m_pipe_pos.x()));
//		qreal x = m_pipe_pos.x() + (m_pipe_radius - m_robo_radius) * qCos(qDegreesToRadians(angle));
//		qreal y = m_pipe_pos.y() + (m_pipe_radius - m_robo_radius) * qSin(qDegreesToRadians(angle));
//		m_robo_pos = QPointF(x, y);
//		m_robo_tilt_angle = angle + 90;
//	}
//	else {
//		m_robo_pos = new_pos;
//		m_robo_tilt_angle = 0;
//	}
	update();
}






