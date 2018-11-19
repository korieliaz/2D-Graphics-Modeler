#include "Polyline.h"
#include "qtconversions.h"
#include <sstream>

std::string Polyline::getSpec(int specNum) const
{
    std::string returnString{""};

    if(specNum % 2 == 0)
    {
        returnString = "x" + std::to_string((specNum/2)+1);
    }
    else
    {
        returnString = "y" + std::to_string((specNum/2)+1);
    }

    return returnString;
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
    painter.drawPolyline(points, numDimensions);
    painter.drawText(points[0].x(), points[0].y(), 20, 20, Qt::AlignLeft, QString::number(shapeId));
}

void Polyline::move(const QPoint &shift)
{
    for(QPoint* it = points ; it < points + numDimensions; ++it)
    {
        *it += shift;
    }
}

void Polyline::setPoints()
{
    int i = 0;

    for(QPoint* it = points ; it < points + numDimensions; ++it)
    {
        it -> setX(shapeDimensions[i]);
        it -> setY(shapeDimensions[i + 1]);
        i += 2;
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
