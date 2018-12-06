#include "ellipse.h"

//! Sets the QPainter object to draw an ellipse according to the Ellipse object's specifications.
void Ellipse::draw()
{
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawEllipse(position.x(), position.y(), shapeDimensions[int(Specifications::A)], shapeDimensions[int(Specifications::B)]);
    painter.setPen(Qt::black);
    painter.drawText(position.x(), position.y(), 20, 20, Qt::AlignLeft, QString::number(shapeId));
}

//! Shifts the position of the ellipse.
void Ellipse::move(const QPoint &shift)
{
    position += shift;
    setShapeDimensions(shift);
}

//! Calculates and returns the perimeter of the ellipse.
dim::perimeter Ellipse::calcPerimeter() const
{
    int a = *(shapeDimensions + int(Specifications::A));
    int b = *(shapeDimensions + int(Specifications::B));

    return (dim::PI * (3 * (a + b) - sqrt((3 * a + b)*(a + 3 * b))));
}

//! Calculates and returns the area of the ellipse.
dim::area Ellipse::calcArea() const
{
    return multiply(*(shapeDimensions + int(Specifications::A)), *(shapeDimensions + int(Specifications::B)), dim::PI);
}

//! Sets the position of the top left corner of the ellipse.
void Ellipse::setPosition()
{
    position = {shapeDimensions[int(Specifications::X1)], shapeDimensions[int(Specifications::Y1)]};
}
