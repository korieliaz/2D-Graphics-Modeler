#include "line.h"
#include <sstream>
#include "qtconversions.h"

dim::perimeter Line::calcPerimeter() const
{
    return distance(*(shapeDimensions + int(Specifications::X1)),
                    *(shapeDimensions + int(Specifications::X2)),
                    *(shapeDimensions + int(Specifications::Y1)),
                    *(shapeDimensions + int(Specifications::Y2)));
}

void Line::draw()
{
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawLine(point1, point2);
    painter.setPen(Qt::black);
    painter.drawText(point1.x(), point1.y(), 20, 20, Qt::AlignLeft, QString::number(shapeId));
}

void Line::move(const QPoint &shift)
{
    point1 += shift;
    point2 += shift;
    setShapeDimensions(shift);
}

void Line::setShapeDimensions(const QPoint &shift)
{
    shapeDimensions[int(Specifications::X1)] += shift.x();
    shapeDimensions[int(Specifications::X2)] += shift.x();
    shapeDimensions[int(Specifications::Y1)] += shift.y();
    shapeDimensions[int(Specifications::Y2)] += shift.y();
}

void Line::setPosition()
{
    point1 = {shapeDimensions[int(Specifications::X1)], shapeDimensions[int(Specifications::Y1)]};
    point2 = {shapeDimensions[int(Specifications::X2)], shapeDimensions[int(Specifications::Y2)]};
}

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
