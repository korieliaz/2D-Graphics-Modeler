#ifndef POLYLINE_H_
#define POLYLINE_H_

#include "shape.h"

const int NUM_POLYLINE_SPECS = -1;

class Polyline: public Shape
{
public:
    // Default
    Polyline() {}

    // CREATE SHAPE_DIMENSIONS ARRAY BEFORE FEEDING INTO CONSTRUCTOR
    Polyline(int shapeId, std::string shapeType, int numDimensions, dim::specs* shapeDimensions);

    ~Polyline() override {}

    void setPosition() override;

    // Calc perimeter
    dim::perimeter calcPerimeter() const override;
    // Calc area
    dim::area calcArea() const override {return 0;}

    void draw() override;

    void move (const QPoint &shift) override;

    std::string print() const override;


private:
    std::vector<QPoint> points;

};

#endif /*POLYLINE_H_*/
