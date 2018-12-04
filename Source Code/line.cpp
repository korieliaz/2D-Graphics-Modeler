/*!
 * \brief   Line CPP File - Team Mittens USA
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

#include "line.h"
#include <sstream>
#include "qtconversions.h"

//! Sets the QPainter object to draw a line according to the Line object's specifications.
void Line::draw()
{
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawLine(point1, point2);
    painter.setPen(Qt::black);
    painter.drawText(point1.x(), point1.y(), 20, 20, Qt::AlignLeft, QString::number(shapeId));
}

//! Shifts the position of the line.
void Line::move(const QPoint &shift)
{
    point1 += shift;
    point2 += shift;
    setShapeDimensions(shift);
}

//! Calculates and returns the length of the line.
dim::perimeter Line::calcPerimeter() const
{
    return distance(*(shapeDimensions + int(Specifications::X1)),
                    *(shapeDimensions + int(Specifications::X2)),
                    *(shapeDimensions + int(Specifications::Y1)),
                    *(shapeDimensions + int(Specifications::Y2)));
}

//! Sets the shape dimensions array to new values after the line is moved.
void Line::setShapeDimensions(const QPoint &shift)
{
    shapeDimensions[int(Specifications::X1)] += shift.x();
    shapeDimensions[int(Specifications::X2)] += shift.x();
    shapeDimensions[int(Specifications::Y1)] += shift.y();
    shapeDimensions[int(Specifications::Y2)] += shift.y();
}

//! Sets the position of the two points on the line.
void Line::setPosition()
{
    point1 = {shapeDimensions[int(Specifications::X1)], shapeDimensions[int(Specifications::Y1)]};
    point2 = {shapeDimensions[int(Specifications::X2)], shapeDimensions[int(Specifications::Y2)]};
}

//! Prints the line specifications as one string to be used in the AllShapes class.
/*! \sa AllShapes::printAll() */
std::string Line::print() const
{
    using std::endl;

    std::ostringstream oss;

    oss << "ShapeId: " << shapeId << endl;
    oss << "ShapeType: " << shapeType << endl;
    oss << "ShapeDimensions: ";
    for(int i = 0; i < numDimensions; ++i)
    {
         oss << shapeDimensions[i];

         if(i < numDimensions - 1)
         {
             oss << ", ";
         }
    }
    oss << endl;

    oss << "PenColor: " << getColorAsString(pen.color()) << endl;
    oss << "PenWidth: " << pen.width() << endl;
    oss << "PenStyle: " << getPenStyleAsString(pen.style()) << endl;
    oss << "PenCapStyle: " << getCapStyleAsString(pen.capStyle()) << endl;
    oss << "PenJoinStyle: " << getJoinStyleAsString(pen.joinStyle()) << endl;

    return oss.str();
}
