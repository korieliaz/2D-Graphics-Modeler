#include "polygon.h"

Polygon::Polygon()
{
    points = new QPoint[numDimensions / 2];
    for(int i = 0; i < numDimensions/2; ++i)
    {
        points[i].setX(0);
        points[i].setY(0);
    }
}

Polygon::Polygon(int shapeId, std::string shapeType, int numDimensions, dim::specs *shapeDimensions)
    :Shape(shapeId, shapeType, numDimensions, shapeDimensions)
{
    points = new QPoint [numDimensions / 2];
    for(int i = 0; i < numDimensions/2; ++i)
    {
        points[i].setX(0);
        points[i].setY(0);
    }
    setPosition();
}

std::string Polygon::getSpec(int specNum) const
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

dim::perimeter Polygon::calcPerimeter() const
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

        i -= 2;
        perimeter += distance(*(x0), *(x1 + i), *(y0), *(y1 + i));

    return perimeter;
}

dim::area Polygon::calcArea() const
{
    int *x0{nullptr}, *x1{nullptr}, *y0{nullptr}, *y1{nullptr};

    x0 = &shapeDimensions[0];
    y0 = &shapeDimensions[1];
    x1 = &shapeDimensions[2];
    y1 = &shapeDimensions[3];

    dim::area area{0.0};

    int n;

    for(n = 0; n < numDimensions - 2; n += 2)
    {
        area += (determinant(*(x0 + n), *(x1 + n), *(y0 + n), *(y1 + n)));
    }
        n -= 2;
        area += (determinant(*(x1 + n), *(x0), *(y1 + n), *(y0)));

    return fabs(area / 2.0);
}

void Polygon::draw()
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
    painter.drawPolygon(staticPoints, numDimensions/2);
    painter.setPen(Qt::black);
    painter.drawText(points[0].x(), points[0].y(), 20, 20, Qt::AlignLeft, QString::number(shapeId));
}

void Polygon::move(const QPoint &shift)
{
    for(QPoint *it = points; it < points + (numDimensions / 2); ++it)
    {
        *it += shift;
    }
}

void Polygon::setPosition()
{
//    int i = 0;

//    for(QPoint* it = points ; it < points + (numDimensions / 2); ++it)
//    {
//        it -> setX(shapeDimensions[i]);
//        it -> setY(shapeDimensions[i + 1]);
//        i += 2;
//    }

    for(int i = 0; i < (numDimensions/2); i++)
    {
        points[i].setX(shapeDimensions[(2*i)]);
        points[i].setY(shapeDimensions[(2*i)+1]);
    }
}
