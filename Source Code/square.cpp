#include "square.h"

//! Sets the QPainter object to draw a square according to the Square object's specifications.
void Square::draw()
{
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(position.x(), position.y(), shapeDimensions[int(Specifications::L)], shapeDimensions[int(Specifications::L)]);
    painter.setPen(Qt::black);
    painter.drawText(position.x() - 20, position.y() - 20, 20, 20, Qt::AlignLeft, QString::number(shapeId));
}

//! Shifts the position of the square.
void Square::move(const QPoint &shift)
{
    position += shift;
    setShapeDimensions(shift);
}

//! Sets the position of the square.
void Square::setPosition()
{
    position = {shapeDimensions[int(Specifications::X1)], shapeDimensions[int(Specifications::Y1)]};
}
