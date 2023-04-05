#ifndef ROBOPIPE_ROBOMOVESCENE_H
#define ROBOPIPE_ROBOMOVESCENE_H

#include <QtWidgets>

namespace roboscene {
    class Pipe : public QGraphicsPixmapItem {
	public:
        explicit Pipe(QGraphicsItem *parent = nullptr);
        ~Pipe() override { qDebug() << "~Pipe"; };

        void rotate_pipe(qreal angle);
		[[nodiscard]] bool is_out_of_bounds(QPointF pos) const;
	    [[nodiscard]] bool is_bounds() const;
	private:
	  qreal radius;
    };

    class Robot : public QGraphicsPixmapItem {
	public:
        explicit Robot(QGraphicsItem *parent = nullptr);
        ~Robot() override { qDebug() << "~Robot"; };

        void move_robot(QPointF n_pos);
        void rotate_robot(qreal angle);
    };

    class RoboWidget : public QGraphicsView {
	public:
        explicit RoboWidget(QWidget *parent = nullptr);
        ~RoboWidget() override { qDebug() << "~RoboWidget"; }

	private:
		QGraphicsScene *scene;
		std::unique_ptr<Pipe> pipe;
		std::unique_ptr<Robot> robot;

	protected:
	  void keyPressEvent(QKeyEvent *event) override;
    };
}

#endif //ROBOPIPE_ROBOMOVESCENE_H
