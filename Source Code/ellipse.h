#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#include "shape.h"

const int NUM_ELLIPSE_SPECS = 4;

class Ellipse: public Shape
{
public:
    // Default
    Ellipse() : position{0,0} {}

    // CREATE SHAPE_DIMENSIONS ARRAY BEFORE FEEDING INTO CONSTRUCTOR
    Ellipse(int shapeId, std::string shapeType, int numDimensions, dim::specs* shapeDimensions)
          :Shape(shapeId, shapeType, numDimensions, shapeDimensions)
          {setPosition();}

    ~Ellipse() override{}

    // Calc perimeter
    dim::perimeter calcPerimeter() const override;
    // Calc area
    dim::area calcArea() const override;

    void draw() override;

    void move(const QPoint &shift) override;

    void setPosition() override;

private:
    QPoint position;

public:
    enum class Specifications{X1, Y1, A, B};
    std::string DimensionLabels[NUM_ELLIPSE_SPECS]{"x1", "y1", "Semi-major", "Semi-minor"};
};



















#endif /*ELLIPSE_H_*/


