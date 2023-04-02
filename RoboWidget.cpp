#include "RoboWidget.h"


RoboWidget::RoboWidget(QWidget *parent) : QWidget(parent),
                                          m_robo_pos(QPointF(0, 0)),
                                          m_robo_angle(0),
                                          m_robo_tiltX(0),
                                          m_robo_tiltY(0),
                                          m_pipe_radius(0),
                                          m_pipe_center(0, 0)
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


    // Compute the position of the robot inside the pipe image
    double robo_scale = 0.6;
    double robo_offset = 0.1;
    m_robo_pos = m_pipe_center + QPointF(qCos(m_robo_angle * M_PI / 180) * m_pipe_radius * robo_offset,
                                      qSin(m_robo_angle * M_PI / 180) * m_pipe_radius * 0.5);


    // Set the widget size to match the pipe image size
    setFixedSize(m_pipe_image.size());
}

void RoboWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event)

    //Draw the pipe image
    QPainter painter(this);
    painter.drawPixmap(m_pipe_pos.toPoint(), m_pipe_image);

    //Draw the rotated robot image
    // Save the painter state to restore it later
    painter.save();
    QTransform transform;
    painter.translate(m_robo_pos);
    painter.rotate(m_robo_angle);
    painter.rotate(m_robo_tiltX);
    painter.rotate(m_robo_tiltY);
//    transform.rotate(m_robo_tiltX, Qt::XAxis);
//    transform.rotate(m_robo_tiltY, Qt::YAxis);
//    painter.setTransform(transform);
    painter.drawPixmap(-m_robo_image.width() / 2, -m_robo_image.height() /2,
                       m_robo_image.width(), m_robo_image.height(), m_robo_image);
    painter.restore();
}

void RoboWidget::keyPressEvent(QKeyEvent *event) {
    // Move the robot based on the arrow key pressed

    switch (event->key()) {
        case Qt::Key_Left:
            set_robo_position(m_robo_pos + QPointF(-10, 0));
            break;
        case Qt::Key_Right:
            set_robo_position(m_robo_pos + QPointF(10, 0));
            break;
        case Qt::Key_Up:
            m_robo_angle -= 5;
            if (m_robo_angle < 0) {
                m_robo_angle += 360;
            }
            update();
            break;
        case Qt::Key_Down:
            m_robo_angle += 5;
            if (m_robo_angle >= 360) {
                m_robo_angle -= 360;
            }
            update();
            break;
        default:
            QWidget::keyPressEvent(event);
    }

    update();
}

void RoboWidget::set_robo_position(QPointF pos) {
    m_robo_pos = pos;
    update();
}

void RoboWidget::set_robo_tilt(int tilt_x, int tilt_y) {
    m_robo_tiltX = tilt_x;
    m_robo_tiltY = tilt_y;
    update();
}





