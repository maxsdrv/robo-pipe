#ifndef ROBO_PIPE_ROBOWIDGET_H
#define ROBO_PIPE_ROBOWIDGET_H

#include <QtWidgets>


class RoboWidget : public QWidget{
public:
    explicit RoboWidget(QWidget *parent = nullptr);
    ~RoboWidget() override = default;

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
	void resizeEvent(QResizeEvent *event) override;
private:
    QImage m_pipe_image {};
    QImage m_robo_image {};

	QPointF m_robo_pos;
	QPointF m_pipe_pos;

	qreal m_robo_tilt_angle;
	qreal m_pipe_radius;
	qreal m_robo_speed;
	qreal m_robo_radius;
	qreal m_move_direction;

	void update_robot_position();
};


#endif //ROBO_PIPE_ROBOWIDGET_H
