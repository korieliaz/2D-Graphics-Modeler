#include "square.h"

void Square::draw()
{
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(position.x(), position.y(), shapeDimensions[int(Specifications::L)], shapeDimensions[int(Specifications::L)]);
    painter.drawText(position.x(), position.y(), 20, 20, Qt::AlignLeft, QString::number(shapeId));
}

void Square::move(const QPoint &shift)
{
    position += shift;
}

void Square::setPosition()
{
    position = {shapeDimensions[int(Specifications::X1)], shapeDimensions[int(Specifications::Y1)]};
}
