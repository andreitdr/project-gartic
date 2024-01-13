#include "PaintWidget.h"

PaintWidget::PaintWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_drawing = false;
	m_PenWidth = 3;
	m_PenColor = Qt::black;
}

PaintWidget::~PaintWidget()
{}

void PaintWidget::setPenColor(const QColor & newColor)
{
	m_PenColor = newColor;
}

void PaintWidget::setPenWidth(int newWidth)
{
	m_PenWidth = newWidth;
}

void PaintWidget::saveImage()
{
	QString filePath = QFileDialog::getSaveFileName(this, tr("Save Image"),
		"untitled.png",
		tr("Images (*.png *.jpg)"));
	if (!filePath.isEmpty())
	{
		QImage imageToSave = m_image.copy(rect());
		imageToSave.save(filePath);
	}
}

QImage PaintWidget::getImage() const
{
	return m_image;
}

QColor PaintWidget::penColor() const
{
	return m_PenColor;
}

int PaintWidget::penWidth() const
{
	return m_PenWidth;
}

void PaintWidget::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_lastPoint = event->pos();
		m_drawing = true;
	}
}

void PaintWidget::mouseMoveEvent(QMouseEvent* event)
{
	if ((event->buttons() & Qt::LeftButton) && m_drawing)
		drawLine(event->pos());
}

void PaintWidget::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton && m_drawing)
	{
		drawLine(event->pos());
		m_drawing = false;
	}
}

void PaintWidget::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	QRect rect = event->rect();
	painter.drawImage(rect, m_image, rect);
}

void PaintWidget::resizeEvent(QResizeEvent* event)
{
	if (width() > m_image.width() || height() > m_image.height()) {
		int newWidth = qMax(width() + 128, m_image.width());
		int newHeight = qMax(height() + 128, m_image.height());
		resizeImage(&m_image, QSize(newWidth, newHeight));
		update();
	}
	QWidget::resizeEvent(event);
}

void PaintWidget::drawLine(const QPoint& endPoint)
{
	QPainter painter(&m_image);
	painter.setPen(QPen(m_PenColor, m_PenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	painter.drawLine(m_lastPoint, endPoint);
	int rad = (m_PenWidth / 2) + 2;
	update(QRect(m_lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
	m_lastPoint = endPoint;
}

void PaintWidget::resizeImage(QImage* image, const QSize& newSize)
{
	if (image->size() == newSize)
		return;

	QImage newImage(newSize, QImage::Format_RGB32);
	newImage.fill(qRgb(255, 255, 255));
	QPainter painter(&newImage);
	painter.drawImage(QPoint(0, 0), *image);
	*image = newImage;
}

void PaintWidget::on_pushButton_saveImage_clicked()
{
	saveImage();
}

void PaintWidget::on_pushButton_smallLineSize_clicked()
{
	setPenWidth(1);
}

void PaintWidget::on_pushButton_mediumLineSize_clicked()
{
	setPenWidth(3);
}

void PaintWidget::on_pushButton_largeLineSize_clicked()
{
	setPenWidth(5);
}

void PaintWidget::on_pushButton_white_clicked()
{
	setPenColor(QColor(255, 255, 255));
}

void PaintWidget::on_pushButton_black_clicked()
{
	setPenColor(QColor(0, 0, 0));
}

void PaintWidget::on_pushButton_grey_clicked()
{
	setPenColor(QColor(157, 157, 157));
}

void PaintWidget::on_pushButton_red_clicked()
{
	setPenColor(QColor(170, 0, 0));
}

void PaintWidget::on_pushButton_orange_clicked()
{
	setPenColor(QColor(244, 163, 0));
}

void PaintWidget::on_pushButton_yellow_clicked()
{
	setPenColor(QColor(255, 239, 21));
}

void PaintWidget::on_pushButton_pink_clicked()
{
	setPenColor(QColor(255, 0, 127));
}

void PaintWidget::on_pushButton_blue_clicked()
{
	setPenColor(QColor(85, 0, 255));
}

void PaintWidget::on_pushButton_magenta_clicked()
{
	setPenColor(QColor(170, 0, 255));
}

void PaintWidget::on_pushButton_turquoise_clicked()
{
	setPenColor(QColor(0, 85, 127));
}

void PaintWidget::on_pushButton_green_clicked()
{
	setPenColor(QColor(0, 85, 0));
}

void PaintWidget::on_pushButton_brown_clicked()
{
	setPenColor(QColor(170, 85, 0));
}

void PaintWidget::clearImage()
{
	m_image.fill(qRgb(255, 255, 255));
	update();
}

void PaintWidget::on_pushButton_clearImage_clicked()
{
	clearImage();
}
