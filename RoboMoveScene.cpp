#include "RoboMoveScene.h"

using namespace roboscene;

Robot::Robot(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {

}

void Robot::move_robot(QPointF n_pos) {

}

void Robot::rotate_robot(qreal angle) {

}

Pipe::Pipe(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {

}

void Pipe::rotate_pipe(qreal angle) {

}

RoboWidget::RoboWidget(QWidget *parent) : QGraphicsView(parent){

}