#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#include "Shape.h"

const int NUM_ELLIPSE_SPECS = 4;

class Ellipse: public Shape
{
public:
    // Default
    Ellipse();

    // CREATE SHAPE_DIMENSIONS ARRAY BEFORE FEEDING INTO CONSTRUCTOR
    Ellipse(int shapeId, std::string shapeType, int numDimensions, dim::specs* shapeDimensions)
          :Shape(shapeId, shapeType, numDimensions, shapeDimensions)
          {}

    ~Ellipse() override{}

    // Return label for this spec index
    std::string getSpec(int specNum) const override {return DimensionLabels[specNum];}

    // Calc perimeter
    dim::perimeter calcPerimeter() const override;
    // Calc area
    dim::area calcArea() const override;

    void draw() override;

    void move(const QPoint &shift) override;

    void setPosition();

private:
    enum class Specifications{X1, Y1, A, B};
    std::string DimensionLabels[NUM_ELLIPSE_SPECS]{"x1", "y1", "Semi-major", "Semi-minor"};
    QPoint position;
};



















#endif /*ELLIPSE_H_*/


