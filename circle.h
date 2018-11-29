#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <QPaintDevice>
#include <QPoint>
#include "shape.h"

const int NUM_CIRCLE_SPECS = 3;

class Circle: public Shape
{
public:
    // Default
    Circle() : position{0,0} {}

    // CREATE SHAPE_DIMENSIONS ARRAY BEFORE FEEDING INTO CONSTRUCTOR
    Circle(int shapeId, std::string shapeType, int numDimensions, dim::specs* shapeDimensions)
          :Shape(shapeId, shapeType, numDimensions, shapeDimensions)
          {setPosition();}

    ~Circle() override {}

    void draw() override;

    void move(const QPoint &shift) override;

    // Calc perimeter
    dim::perimeter calcPerimeter() const override;
    // Calc area
    dim::area calcArea() const override;

    void setPosition() override;

private:
    QPoint position;

public:
    std::string DimensionLabels[NUM_CIRCLE_SPECS]{"x1", "y1", "radius"};
    enum class Specifications{X1, Y1, RADIUS};
};















#endif /*CIRCLE_H_*/
