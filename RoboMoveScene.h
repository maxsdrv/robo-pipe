#ifndef ROBOPIPE_ROBOMOVESCENE_H
#define ROBOPIPE_ROBOMOVESCENE_H

#include <QtWidgets>

namespace roboscene {
    class Pipe : public QGraphicsPixmapItem {
        explicit Pipe(QGraphicsItem *parent = nullptr);

        ~Pipe() override { qDebug() << "~Pipe"; };

        void rotate_pipe(qreal angle);
    };

    class Robot : public QGraphicsPixmapItem {
        explicit Robot(QGraphicsItem *parent = nullptr);

        ~Robot() override { qDebug() << "~Robot"; };

        void move_robot(QPointF n_pos);

        void rotate_robot(qreal angle);
    };

    class RoboWidget : public QGraphicsView {
        explicit RoboWidget(QWidget *parent = nullptr);

        ~RoboWidget() override { qDebug() << "~RoboWidget"; }
    };
}

#endif //ROBOPIPE_ROBOMOVESCENE_H
