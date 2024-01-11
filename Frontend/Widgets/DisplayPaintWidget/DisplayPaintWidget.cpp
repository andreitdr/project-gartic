#include "DisplayPaintWidget.h"

DisplayPaintWidget::DisplayPaintWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

DisplayPaintWidget::~DisplayPaintWidget()
{}

void DisplayPaintWidget::updateImage(QImage image)
{
	m_image = image;
	update();
}

void DisplayPaintWidget::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	QPoint center = rect().center();
	QPoint imageTopLeft = center - m_image.rect().center();
	painter.drawImage(imageTopLeft, m_image);
}
