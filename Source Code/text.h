#ifndef TEXT_H_
#define TEXT_H_

#include <QPaintDevice>
#include <QPoint>
#include <QString>
#include "shape.h"

const int NUM_TEXT_SPECS = 4;

class Text: public Shape
{
public:
    // Default
    Text() : position{0,0}{}

    // CREATE SHAPE_DIMENSIONS ARRAY BEFORE FEEDING INTO CONSTRUCTOR
    Text(int shapeId, std::string shapeType, int numDimensions, dim::specs* shapeDimensions, QFont newFont, std::string newText, Qt::AlignmentFlag newFlag)
          :Shape(shapeId, shapeType, numDimensions, shapeDimensions)
          {setPosition(); setAlignment(newFlag); setFont(newFont); setText(newText);}

    ~Text() override {}

    // Calc perimeter
    dim::perimeter calcPerimeter() const override {return 0;}
    // Calc area
    dim::area calcArea() const override {return 0;}

    void draw() override;

    void move(const QPoint &shift) override {position += shift;}

    void setPosition() override;

    std::string print() const override;


private:
    QPoint position;


public:
    enum class Specifications{X1, Y1, W, H};
    std::string DimensionLabels[NUM_TEXT_SPECS]{"x1", "y1", "Width", "Height"};
};















#endif /*TEXT_H_*/
//    std::string textString;
