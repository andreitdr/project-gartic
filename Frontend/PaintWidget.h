#pragma once

#include <QWidget>
#include "ui_PaintWidget.h"
#include <QtGlobal>
#include <QColor>
#include <QImage>
#include <QPoint>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QPainter>

class PaintWidget : public QWidget
{
	Q_OBJECT

public:
	PaintWidget(QWidget *parent = nullptr);
	~PaintWidget();
	void setPenColor(const QColor& newColor);
	void setPenWidth(int newWidth);

	QColor penColor() const;
	int penWidth() const;

	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void paintEvent(QPaintEvent* event);
	void resizeEvent(QResizeEvent* event);

private:
	Ui::PaintWidgetClass ui;
	void drawLine(const QPoint& endPoint);
	void resizeImage(QImage* image, const QSize& newSize);
	bool m_drawing;
	int m_PenWidth;
	QColor m_PenColor;
	QImage m_image;
	QPoint m_lastPoint;       

public slots:
	void clearImage();
};
