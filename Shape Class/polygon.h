#ifndef POLYGON_H_
#define POLYGON_H_

#include <QPaintDevice>
#include <QPoint>
#include "Shape.h"

const int NUM_POLYGON_SPECS = -1;

class Polygon: public Shape
{
public:
    // Default
    Polygon(){points = new QPoint[numDimensions];}

    // CREATE SHAPE_DIMENSIONS ARRAY BEFORE FEEDING INTO CONSTRUCTOR
    Polygon(int shapeId, std::string shapeType, int numDimensions, dim::specs* shapeDimensions)
          :Shape(shapeId, shapeType, numDimensions, shapeDimensions)
          {points = new QPoint [numDimensions];}

    ~Polygon() override {delete[] points;}

    // Return label for this spec index
    std::string getSpec(int specNum) const override;

    // Calc perimeter
    dim::perimeter calcPerimeter() const override;
    // Calc area
    dim::area calcArea() const override;

    void draw() override;

    void move(const QPoint &shift) override;

    void setPoints();



private:
    QPoint *points;

};















#endif /*POLYGON_H_*/
