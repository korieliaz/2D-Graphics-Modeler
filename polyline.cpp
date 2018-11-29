#include "polyline.h"
#include "qtconversions.h"
#include <sstream>

Polyline::Polyline(int shapeId, std::string shapeType, int numDimensions, dim::specs *shapeDimensions)
    :Shape(shapeId, shapeType, numDimensions, shapeDimensions)
{
    setPosition();
}

void Polyline::setPosition()
{
    if(!points.empty())
    {
        points.clear();
    }

    QPoint newPoint;
    for(int i = 0; i < (numDimensions/2); i++)
    {
        newPoint.setX(shapeDimensions[(2*i)]);
        newPoint.setY(shapeDimensions[(2*i)+1]);
        points.push_back(newPoint);
    }
}

dim::perimeter Polyline::calcPerimeter() const
{
    int *x0{nullptr}, *x1{nullptr}, *y0{nullptr}, *y1{nullptr};

    x0 = &shapeDimensions[0];
    y0 = &shapeDimensions[1];
    x1 = &shapeDimensions[2];
    y1 = &shapeDimensions[3];

    dim::perimeter perimeter{0.0};

    int i;

    for(i = 0; i < numDimensions / 2; i += 2)
    {
        perimeter += distance(*(x0 + i), *(x1 + i), *(y0 + i), *(y1 + i));
    }

    return perimeter;
}

void Polyline::draw()
{
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawPolyline(&points[0], numDimensions/2);
    painter.setPen(Qt::black);
    painter.drawText(points[0].x(), points[0].y(), 20, 20, Qt::AlignLeft, QString::number(shapeId));
}

void Polyline::move(const QPoint &shift)
{
    for(std::vector<QPoint>::iterator it = points.begin(); it != points.end(); ++it)
    {
        *it += shift;
    }

    setShapeDimensions(shift);
}

void Polyline::setShapeDimensions(const QPoint &shift)
{
    for(int i = 0; i < numDimensions; i++)
    {
        shapeDimensions[2*i] += shift.x();
        shapeDimensions[(2*i)+1] += shift.y();
    }
}

std::string Polyline::print() const
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
