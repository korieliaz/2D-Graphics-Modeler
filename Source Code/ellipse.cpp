#include "ellipse.h"

dim::perimeter Ellipse::calcPerimeter() const
{
    int a = *(shapeDimensions + int(Specifications::A));
    int b = *(shapeDimensions + int(Specifications::B));

    return (dim::PI * (3 * (a + b) - sqrt((3 * a + b)*(a + 3 * b))));
}

dim::area Ellipse::calcArea() const
{
    return multiply(*(shapeDimensions + int(Specifications::A)), *(shapeDimensions + int(Specifications::B)), dim::PI);
}

void Ellipse::draw()
{
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawEllipse(position.x(), position.y(), shapeDimensions[int(Specifications::A)], shapeDimensions[int(Specifications::B)]);
    painter.setPen(Qt::black);
    painter.drawText(position.x(), position.y(), 20, 20, Qt::AlignLeft, QString::number(shapeId));
}

void Ellipse::move(const QPoint &shift)
{
    position += shift;
}

void Ellipse::setPosition()
{
    position = {shapeDimensions[int(Specifications::X1)], shapeDimensions[int(Specifications::Y1)]};
}
