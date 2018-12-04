/*!
 * \brief   Circle CPP File - Team Mittens USA
 * \authors Kori Eliaz          <korieliaz@outlook.com>
 * \authors Trevor Dunham       <trevor_d@outlook.com>
 * \authors Michael Sinclair    <masinclair2@gmail.com>
 * \authors Brian Ferguson      <bferguson@gmail.com>
 * \authors Mariah Harris       <mariahh2017@gmail.com>
 * \authors Ali Bingol          <mythologyali@gmail.com>
 * \authors Peter Win           <peterzin@gmail.com>
 * \authors Braden Wurlitzer    <wurlitzerb@gmail.com>
 * \date    Fall 2018
 * \copyright Team Mittens USA
 * \copyright CS1C w/ Professor John Kath
 * \copyright Saddleback College
*/

#include "circle.h"

//! Sets the QPainter object to draw a circle according to the Circle object's specifications.
void Circle::draw()
{
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawEllipse(position.x(), position.y(), shapeDimensions[int(Specifications::RADIUS)], shapeDimensions[int(Specifications::RADIUS)]);
    painter.setPen(Qt::black);
    painter.drawText(position.x(), position.y(), 20, 20, Qt::AlignLeft, QString::number(shapeId));
}

//! Shifts the position of the circle.
void Circle::move(const QPoint &shift)
{
    position += shift;
    setShapeDimensions(shift);
}

//! Calculates and returns the perimeter of the circle.
dim::perimeter Circle::calcPerimeter() const
{
    return multiply(2.0, dim::PI, *(shapeDimensions + int(Specifications::RADIUS)));
}

//! Calculates and returns the area of the circle.
dim::area Circle::calcArea() const
{
    return multiply(dim::PI, pow(double(*(shapeDimensions + int(Specifications::RADIUS))), 2.0));
}

//! Sets the position of the top left corner of the circle.
void Circle::setPosition()
{
    position = {shapeDimensions[int(Specifications::X1)], shapeDimensions[int(Specifications::Y1)]};
}

