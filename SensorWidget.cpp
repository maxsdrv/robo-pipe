#include "SensorWidget.h"

#include <QDebug>
#include <QtMath>

namespace {
	const double DISTANCE_THRESHOLD = 1000; // range for data filter
}

SensorWidget::SensorWidget(std::map<double, double> &&data, QWidget *parent) : m_data(data),
																		       QWidget(parent) {
	setFixedSize(400, 400);
	for (const auto& [key, value] : m_data) {
		qDebug() << key << " " << value;
	}
}
void SensorWidget::paintEvent(QPaintEvent *event) {
	QPainter painter(this);

	// Filter the data to remove false points
	for (auto it = m_data.begin(); it != m_data.end(); ) {
		if (it->second > DISTANCE_THRESHOLD) {
			it = m_data.erase(it);
		}
		else {
			++it; // avoid using an invalid iterator
		}
	}

	// Calculate the center of the circle
	double sum_x = 0;
	double sum_y = 0;
	// Convert polar coordinates to Cartesian for easily perform necessary calculations
	for (const auto& [angle, dist]: m_data) {
		sum_x += angle * qCos(dist);
		sum_y += angle * qSin(dist);
	}
	double center_x = sum_x / static_cast<double>(m_data.size());
	double center_y = sum_y / static_cast<double>(m_data.size());

	// Calculate the radius of the circle
	double sum_dist = 0;
	for (const auto& [angle, dist]: m_data) {
		double dx = center_x - dist * qCos(angle);
		double dy = center_y - dist * qSin(angle);
		double distance = qSqrt(dx * dx + dy * dy); // Pythagorean theorem
		sum_dist += distance;
	}
	double radius = sum_dist / static_cast<double>(m_data.size());
	double diameter = 2 * radius;

	// Draw the circle
	painter.translate(width() / 2.0, height() / 2.0);
	painter.setPen(QPen(Qt::black, 2));
	painter.drawEllipse(QPointF(center_x, center_y), radius, radius);

	// Display the diameter
	painter.drawText(10, 20, "Diameter: " + QString::number(diameter) + " mm");
}








