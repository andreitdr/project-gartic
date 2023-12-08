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
#include <QFileDialog>

class PaintWidget : public QWidget
{
	Q_OBJECT

public:
	PaintWidget(QWidget *parent = nullptr);
	~PaintWidget();
	void setPenColor(const QColor& newColor);
	void setPenWidth(int newWidth);
	void saveImage();

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

private slots:
	//options
	virtual void on_pushButton_clearImage_clicked();
	virtual void on_pushButton_saveImage_clicked();
	//pen size
	virtual void on_pushButton_smallLineSize_clicked();
	virtual void on_pushButton_mediumLineSize_clicked();
	virtual void on_pushButton_largeLineSize_clicked();
	//pen color
	virtual void on_pushButton_white_clicked();
	virtual void on_pushButton_black_clicked();
	virtual void on_pushButton_grey_clicked();
	virtual void on_pushButton_red_clicked();
	virtual void on_pushButton_orange_clicked();
	virtual void on_pushButton_yellow_clicked();
	virtual void on_pushButton_pink_clicked();
	virtual void on_pushButton_blue_clicked();
	virtual void on_pushButton_magenta_clicked();
	virtual void on_pushButton_turquoise_clicked();
	virtual void on_pushButton_green_clicked();
	virtual void on_pushButton_brown_clicked();
};
