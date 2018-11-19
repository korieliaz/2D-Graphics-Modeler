#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <QPaintDevice>
#include <QPoint>
#include "Shape.h"

const int NUM_CIRCLE_SPECS = 3;

class Circle: public Shape
{
public:
    // Default
    Circle();

    // CREATE SHAPE_DIMENSIONS ARRAY BEFORE FEEDING INTO CONSTRUCTOR
    Circle(int shapeId, std::string shapeType, int numDimensions, dim::specs* shapeDimensions)
          :Shape(shapeId, shapeType, numDimensions, shapeDimensions)
          {}

    ~Circle() override {}

    // Return label for this spec index
    std::string getSpec(int specNum) const override {return DimensionLabels[specNum];}

    void draw() override;

    void move(const QPoint &shift) override;

    // Calc perimeter
    dim::perimeter calcPerimeter() const override;
    // Calc area
    dim::area calcArea() const override;

    void setPosition();

private:
    enum class Specifications{X1, Y1, RADIUS};
    std::string DimensionLabels[NUM_CIRCLE_SPECS]{"x1", "y1", "radius"};
    QPoint position;
};















#endif /*CIRCLE_H_*/
