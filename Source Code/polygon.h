#ifndef POLYGON_H_
#define POLYGON_H_

#include <QPaintDevice>
#include <QPoint>
#include "shape.h"

const int NUM_POLYGON_SPECS = -1;

class Polygon: public Shape
{
public:
    // Default
    Polygon();

    // CREATE SHAPE_DIMENSIONS ARRAY BEFORE FEEDING INTO CONSTRUCTOR
    Polygon(int shapeId, std::string shapeType, int numDimensions, dim::specs* shapeDimensions);

    ~Polygon() override {delete[] points;}

    // Calc perimeter
    dim::perimeter calcPerimeter() const override;
    // Calc area
    dim::area calcArea() const override;

    void draw() override;

    void move(const QPoint &shift) override;

    void setPosition() override;



private:
    QPoint *points;

};















#endif /*POLYGON_H_*/
