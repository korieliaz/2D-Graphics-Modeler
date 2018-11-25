#ifndef SHAPE_H_
#define SHAPE_H_

#include "libraries.h"
#include "vals_n_calcs.h"

const int NUM_SHAPES = 8;
const int NUM_STATIC_SHAPES = 6;

const int MIN_TEXT_POINT = -1;
const int MAX_TEXT_POINT = 50;


namespace ShapeLabels
{
    enum eShapes{LINE, POLYLINE, POLYGON, RECTANGLE, SQUARE, ELLIPSE, CIRCLE, TEXT};
    const int NUM_SHAPE_DIMENSIONS[NUM_STATIC_SHAPES]{4, 4, 3, 4, 3, 4};
    const std::string SHAPES_LIST[NUM_SHAPES]{"Line", "Polyline", "Polygon", "Rectangle", "Square", "Ellipse", "Circle", "Text"};
}

class Shape
{
public:
    // Default
    Shape(QPaintDevice *device = nullptr):
          shapeId{0},
          shapeType{"Nullbody"},
          numDimensions{0},
          shapeDimensions{new dim::specs[numDimensions]},
          text{"Nullbody"}
          {}
    // Constructor overload
    Shape(
          int shapeId,
          std::string shapeType,
          int numDimensions,
          dim::specs* shapeDimensions
          ):
          shapeId{shapeId},
          shapeType{shapeType},
          numDimensions{numDimensions}
          {
            this -> shapeDimensions = new dim::specs[numDimensions];

            for(int i = 0; i < numDimensions; ++i)
            {
                this -> shapeDimensions[i] = shapeDimensions[i];
            }
          }

    // REMOVES FUNCTIONALITY OF COPY CONSTRUCTOR/ASSIGNMENT FOR ALL SHAPES
    Shape(const Shape &otherShape) = delete;
    const Shape& operator=(const Shape &otherShape) = delete;

    virtual ~Shape(){delete[] shapeDimensions;}

//-------------------------------------------------------------------------------------
    // OPERATOR OVERLOADS
    bool operator==(const Shape& shape) const {return shapeId == shape.shapeId;}
    bool operator<(const Shape& shape) const {return shapeId < shape.shapeId;}
    bool operator>(const Shape& shape) const {return shapeId > shape.shapeId;}
//-------------------------------------------------------------------------------------

    // Set Functions
    void setBaseInfo(int shapeId, std::string shapeType, int numDimensions, dim::specs* otherDimensions);

    void setPen(const QPen &pen) {this -> pen = pen;}

    void setBrush(const QBrush &brush) {this -> brush = brush;}

    void setID(int id) {shapeId = id;}

    // Set shape dimension
    void setShapeDimension(int dimensionIndex, dim::specs newDimension) {shapeDimensions[dimensionIndex] = newDimension;}

    // Get Functions
    std::string getType() {return shapeType;}

    QBrush &getBrush() {return brush;}

    int getID() const {return shapeId;}

    QPainter &getPainter() {return painter;}

    QPen &getPen() {return pen;}

    void setText(const std::string newText) {text = newText;}

    void setAlignment(Qt::AlignmentFlag flag) {alignFlag = flag;}

    void setFont(const QFont &font) {this -> font = font;}

    // Pure Virtual Functions
    // Draw
    virtual void draw() = 0;

    // Move
    virtual void move(const QPoint &shift) = 0;

    // Perimeter
    virtual dim::perimeter calcPerimeter() const = 0;

    // Area
    virtual dim::area calcArea() const = 0;

    // Set Position
    virtual void setPosition() = 0;

    dim::specs* getDimensions() {return shapeDimensions;}

    int getNumDimensions() {return numDimensions;}

    QFont &getFont() {return font;}

    Qt::AlignmentFlag getFlag() {return alignFlag;}

    std::string getText() {return text;}

    // Virtual Functions
    // Print
    virtual std::string print() const;


protected:
    int shapeId;
    std::string shapeType;
    int numDimensions;

    // Points to dynamic array of shape specifications
    dim::specs* shapeDimensions;

    QPainter painter;
    QPen pen;
    QBrush brush;

    QFont font;
    std::string text;
    Qt::AlignmentFlag alignFlag;

};

#endif /*SHAPE_H_*/
