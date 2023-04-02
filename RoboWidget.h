#ifndef ROBO_PIPE_ROBOWIDGET_H
#define ROBO_PIPE_ROBOWIDGET_H

#include <QtWidgets>


class RoboWidget : public QWidget{
public:
    explicit RoboWidget(QWidget *parent = nullptr);
    ~RoboWidget() override = default;

    void set_robo_position(QPointF pos);
    void set_robo_tilt(int tilt_x, int tilt_y);
protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
private:
    QPixmap m_pipe_image {};
    QPixmap m_robo_image {};
    QPointF m_pipe_pos {};
    QPointF m_robo_pos; // позиция робота
    qreal m_robo_angle; // угол робота
    qreal m_robo_tiltX; // наклон робота по оси Х
    qreal m_robo_tiltY; // наклон робота по оси У
    qreal m_pipe_radius;
    QPointF m_pipe_center;
};


#endif //ROBO_PIPE_ROBOWIDGET_H
