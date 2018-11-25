#ifndef SQUARE_H_
#define SQUARE_H_

#include "shape.h"

const int NUM_SQUARE_SPECS = 3;

class Square: public Shape
{
public:
    // Default
    Square() : position{0,0} {}

    // CREATE SHAPE_DIMENSIONS ARRAY BEFORE FEEDING INTO CONSTRUCTOR
    Square(int shapeId, std::string shapeType, int numDimensions, dim::specs* shapeDimensions)
          :Shape(shapeId, shapeType, numDimensions, shapeDimensions)
          {setPosition();}

    ~Square() override {}

    // Return label for this spec index
    std::string getSpec(int specNum) const override {return DimensionLabels[specNum];}

    // Calc perimeter
    dim::perimeter calcPerimeter() const override {return multiply(*(shapeDimensions + int(Specifications::L)), 4.0);}
    // Calc area
    dim::area calcArea() const override {return multiply(*(shapeDimensions + int(Specifications::L)),
                                                         *(shapeDimensions + int(Specifications::L)));}

    void draw() override;

    void move(const QPoint &shift) override;

    void setPosition() override;


private:
    QPoint position;

public:
    enum class Specifications{X1, Y1, L};
    std::string DimensionLabels[NUM_SQUARE_SPECS]{"x1", "y1", "Length"};
};















#endif /*SQUARE_H_*/
