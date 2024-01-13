#pragma once
#include <QImage>
#include <QBuffer>
#include <QByteArray>
#include <QString>
#include <string>

class QImageConverter
{
public:
	QImageConverter();
	~QImageConverter();
	std::string convertImageToString(const QImage& image);
	QImage convertStringToImage(const std::string& encodedString);

};

