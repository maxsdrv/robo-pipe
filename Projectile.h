#ifndef ROBOPIPE_PROJECTILE_H
#define ROBOPIPE_PROJECTILE_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QtMath>

namespace {
    const qreal GRAVITY = 9.81;
}

class Projectile : public QGraphicsItem {
public:
    Projectile(qreal angle, qreal velocity) : m_angle(angle), m_velocity(velocity) { }

    QRectF boundingRect() const override {
        return QRectF(-2, -2, 4, 4);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override {
        painter->drawEllipse(boundingRect());
    }

    void advance(int phase) override {
        if (phase == 0) {
            m_time += 0.1;

            qreal x = m_velocity * qCos(m_angle) * m_time;
            qreal y = m_velocity * qSin(m_angle) * m_time;

            setPos(x, -y);

            if (y < 0) {
                scene()->removeItem(this);
            }
        }
    }

private:
    qreal m_angle;
    qreal m_velocity;
    qreal m_time = 0;
};

#endif //ROBOPIPE_PROJECTILE_H
