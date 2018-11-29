#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "shape.h"

const int NUM_RECTANGLE_SPECS = 4;

class Rectangle: public Shape
{
public:
    // Default
    Rectangle() : position{0,0} {}

    // CREATE SHAPE_DIMENSIONS ARRAY BEFORE FEEDING INTO CONSTRUCTOR
    Rectangle(int shapeId, std::string shapeType, int numDimensions, dim::specs* shapeDimensions)
          :Shape(shapeId, shapeType, numDimensions, shapeDimensions)
          {setPosition();}

    ~Rectangle() override {}

    // Calc perimeter
    dim::perimeter calcPerimeter() const override {return multiply(*(shapeDimensions + int(Specifications::W)), 2.0) +
                                                multiply(*(shapeDimensions + int(Specifications::H)), 2.0);}
    // Calc area
    dim::area calcArea() const override {return multiply(*(shapeDimensions + int(Specifications::W)),
                                                    *(shapeDimensions + int(Specifications::H)));}

    void draw() override;

    void move(const QPoint &shift) override;

    void setPosition() override;


private:
    QPoint position;

public:
    enum class Specifications{X1, Y1, W, H};
    std::string DimensionLabels[NUM_RECTANGLE_SPECS]{"x1", "y1", "Width", "Height"};
};















#endif /*RECTANGLE_H_*/
