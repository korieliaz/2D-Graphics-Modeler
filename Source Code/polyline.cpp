#include "polyline.h"
#include "qtconversions.h"
#include <sstream>

Polyline::Polyline()
{
    points = new QPoint[numDimensions / 2];
    for(int i = 0; i < numDimensions/2; ++i)
    {
        points[i].setX(0);
        points[i].setY(0);
    }
}

Polyline::Polyline(int shapeId, std::string shapeType, int numDimensions, dim::specs *shapeDimensions)
    :Shape(shapeId, shapeType, numDimensions, shapeDimensions)
{
    points = new QPoint[numDimensions / 2];
    for(int i = 0; i < (numDimensions/2); ++i)
    {
        points[i].setX(0);
        points[i].setY(0);
    }
    setPosition();
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
    QPoint staticPoints[numDimensions/2];

    for(int i = 0; i < numDimensions/2; ++i)
    {
        staticPoints[i].setX(shapeDimensions[2*i]);
        staticPoints[i].setY(shapeDimensions[2*i+1]);
    }
    points = staticPoints;

    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawPolyline(staticPoints, numDimensions/2);
    painter.setPen(Qt::black);
    painter.drawText(points[0].x(), points[0].y(), 20, 20, Qt::AlignLeft, QString::number(shapeId));
}

void Polyline::move(const QPoint &shift)
{
    for(QPoint* it = points ; it < points + (numDimensions / 2); ++it)
    {
        *it += shift;
    }
}

void Polyline::setPosition()
{   
    for(int i = 0; i < (numDimensions/2); i++)
    {
        points[i].setX(shapeDimensions[(2*i)]);
        points[i].setY(shapeDimensions[(2*i)+1]);
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
