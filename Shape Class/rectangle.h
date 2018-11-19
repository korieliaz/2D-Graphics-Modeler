#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

const int NUM_RECTANGLE_SPECS = 4;

class Rectangle: public Shape
{
public:
    // Defualt
    Rectangle();

    // CREATE SHAPE_DIMENSIONS ARRAY BEFORE FEEDING INTO CONSTRUCTOR
    Rectangle(int shapeId, std::string shapeType, int numDimensions, dim::specs* shapeDimensions)
          :Shape(shapeId, shapeType, numDimensions, shapeDimensions)
          {}

    ~Rectangle() override {}

    // Return label for this spec index
    std::string getSpec(int specNum) const override {return DimensionLabels[specNum];}

    // Calc perimeter
    dim::perimeter calcPerimeter() const override {return multiply(*(shapeDimensions + int(Specifications::L)), 2.0) +
                                                multiply(*(shapeDimensions + int(Specifications::W)), 2.0);}
    // Calc area
    dim::area calcArea() const override {return multiply(*(shapeDimensions + int(Specifications::L)),
                                                    *(shapeDimensions + int(Specifications::W)));}

    void draw() override;

    void move(const QPoint &shift) override;

    void setPosition();


private:
    enum class Specifications{X1, Y1, W, H};
    std::string DimensionLabels[NUM_RECTANGLE_SPECS]{"x1", "y1", "Width", "Height"};

    QPoint position;
};















#endif /*RECTANGLE_H_*/
