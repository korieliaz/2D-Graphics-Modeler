#include "circle.h"

// Calc perimeter
dim::perimeter Circle::calcPerimeter() const
{
    return multiply(2.0, dim::PI, *(shapeDimensions + int(Specifications::RADIUS)));
}

// Calc area
dim::area Circle::calcArea() const
{
    return multiply(dim::PI, pow(double(*(shapeDimensions + int(Specifications::RADIUS))), 2.0));
}

void Circle::draw()
{
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawEllipse(position.x(), position.y(), shapeDimensions[int(Specifications::RADIUS)], shapeDimensions[int(Specifications::RADIUS)]);
    painter.setPen(Qt::black);
    painter.drawText(position.x(), position.y(), 20, 20, Qt::AlignLeft, QString::number(shapeId));
}

void Circle::move(const QPoint &shift)
{
    position += shift;
}

void Circle::setPosition()
{
    position = {shapeDimensions[int(Specifications::X1)], shapeDimensions[int(Specifications::Y1)]};
}

