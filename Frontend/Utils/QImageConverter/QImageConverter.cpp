#include "QImageConverter.h"

QImageConverter::QImageConverter()
{
}

QImageConverter::~QImageConverter()
{
}

std::string QImageConverter::convertImageToString(const QImage& image)
{
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "JPG");

    std::string encodedData = byteArray.toBase64().toStdString();

    return encodedData;
}

QImage QImageConverter::convertStringToImage(const std::string& encodedString)
{
    QByteArray byteArray = QByteArray::fromBase64(encodedString.c_str());

    QImage image;
    image.loadFromData(byteArray, "JPG");

    return image;
}
