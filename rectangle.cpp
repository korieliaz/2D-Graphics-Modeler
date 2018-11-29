#include "rectangle.h"

void Rectangle::draw()
{
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(position.x(), position.y(), shapeDimensions[int(Specifications::W)], shapeDimensions[int(Specifications::H)]);
    painter.setPen(Qt::black);
    painter.drawText(position.x() - 20, position.y() - 20, 20, 20, Qt::AlignLeft, QString::number(shapeId));
}

void Rectangle::move(const QPoint &shift)
{
    position += shift;
    setShapeDimensions(shift);
}

void Rectangle::setPosition()
{
    position = {shapeDimensions[int(Specifications::X1)], shapeDimensions[int(Specifications::Y1)]};
}
