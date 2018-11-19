#ifndef TEXT_H_
#define TEXT_H_

#include <QPaintDevice>
#include <QPoint>
#include <QString>
#include "Shape.h"

const int NUM_TEXT_SPECS = 4;

class Text: public Shape
{
public:
    // Default
    Text();

    // CREATE SHAPE_DIMENSIONS ARRAY BEFORE FEEDING INTO CONSTRUCTOR
    Text(int shapeId, std::string shapeType, int numDimensions, dim::specs* shapeDimensions)
          :Shape(shapeId, shapeType, numDimensions, shapeDimensions)
          {}

    ~Text() override {}

    // Return label for this spec index
    std::string getSpec(int specNum) const override {return DimensionLabels[specNum];}

    // Calc perimeter
    dim::perimeter calcPerimeter() const override {return 0;}
    // Calc area
    dim::area calcArea() const override {return 0;}

    void draw() override;

    void move(const QPoint &shift) override {position += shift;}

    void setAlignment(Qt::AlignmentFlag flag) {alignFlag = flag;}

    void setFont(const QFont &font) {this -> font = font;}

    void setPosition();

    void setText(const std::string& text) {this -> text = text;}

    std::string print() const override;


private:
    enum class Specifications{X1, Y1, W, H};
    std::string DimensionLabels[NUM_TEXT_SPECS]{"x1", "y1", "Width", "Height"};

    QPoint position;
    QFont font;
    std::string text;
    Qt::AlignmentFlag alignFlag;
};















#endif /*TEXT_H_*/
//    std::string textString;
