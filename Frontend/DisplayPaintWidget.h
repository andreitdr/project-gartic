#pragma once

#include <QWidget>
#include "ui_DisplayPaintWidget.h"
#include <QImage>
#include <QResizeEvent>
#include <QPainter>

class DisplayPaintWidget : public QWidget
{
	Q_OBJECT

public:
	DisplayPaintWidget(QWidget *parent = nullptr);
	~DisplayPaintWidget();

	void loadImage();
	void paintEvent(QPaintEvent* event) override;

private:
	Ui::DisplayPaintWidgetClass ui;
	QImage m_image;
};
