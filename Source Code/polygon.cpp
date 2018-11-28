#include "polygon.h"

Polygon::Polygon(int shapeId, std::string shapeType, int numDimensions, dim::specs *shapeDimensions)
    :Shape(shapeId, shapeType, numDimensions, shapeDimensions)
{
    setPosition();
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
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawPolygon(&points[0], numDimensions/2);
    painter.setPen(Qt::black);
    painter.drawText(points[0].x(), points[0].y(), 20, 20, Qt::AlignLeft, QString::number(shapeId));
}

void Polygon::move(const QPoint &shift)
{
    for(std::vector<QPoint>::iterator it = points.begin(); it != points.end(); ++it)
    {
        *it += shift;
    }

    setShapeDimensions(shift);
}

void Polygon::setShapeDimensions(const QPoint &shift)
{
    for(int i = 0; i < numDimensions; i++)
    {
        shapeDimensions[2*i] += shift.x();
        shapeDimensions[(2*i)+1] += shift.y();
    }
}

void Polygon::setPosition()
{
    QPoint newPoint;
    for(int i = 0; i < (numDimensions/2); i++)
    {
        newPoint.setX(shapeDimensions[(2*i)]);
        newPoint.setY(shapeDimensions[(2*i)+1]);
        points.push_back(newPoint);
    }
}
