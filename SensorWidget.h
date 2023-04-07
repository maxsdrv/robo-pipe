#ifndef ROBOPIPE__SENSORWIDGET_H_
#define ROBOPIPE__SENSORWIDGET_H_

#include <QWidget>
#include <QPainter>

#include <map>
#include <algorithm>


class SensorWidget : public QWidget {
public:
	explicit SensorWidget(std::map<double, double>&& data, QWidget *parent = nullptr);
private:
	std::map<double, double> m_data;
protected:
  	void paintEvent(QPaintEvent *event) override;
};

#endif //ROBOPIPE__SENSORWIDGET_H_
