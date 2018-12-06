#include "shape.h"
#include "qtconversions.h"
#include <sstream>
using std::endl;

//! Alternate constructor
Shape::Shape(int shapeId, std::string shapeType, int numDimensions, dim::specs *shapeDimensions)
    : shapeId{shapeId}, shapeType{shapeType}, numDimensions{numDimensions}
{
    this -> shapeDimensions = new dim::specs[numDimensions];

    for(int i = 0; i < numDimensions; ++i)
    {
        this -> shapeDimensions[i] = shapeDimensions[i];
    }
}

//! Sets shape information
void Shape::setBaseInfo(int shapeId, std::string shapeType, int numDimensions, dim::specs* otherDimensions)
{
    /*! Deletes former data if it has to be overriden */
    if(this -> shapeDimensions != nullptr)
    {
        delete[] this -> shapeDimensions;
        shapeDimensions = nullptr;
    }

    this -> shapeId = shapeId;
    this -> shapeType = shapeType;
    this -> numDimensions = numDimensions;

    shapeDimensions = new dim::specs[numDimensions];

    for(int i = 0; i < numDimensions; ++i)
    {
        shapeDimensions[i] = otherDimensions[i];
    }
}

/*! Sets shape dimensions in the shapeDimensions array after a shape has been moved */
void Shape::setShapeDimensions(const QPoint &shift)
{
    shapeDimensions[ShapeLabels::X1] += shift.x();
    shapeDimensions[ShapeLabels::Y1] += shift.y();
}

/*! Default print method for a shape */
std::string Shape::print() const
{
     std::ostringstream oss;

     oss << "ShapeId: " << shapeId << endl;
     oss << "ShapeType: " << shapeType << endl;
     oss << "ShapeDimensions: ";
     for(int i = 0; i < numDimensions; ++i)
     {
         oss << shapeDimensions[i];
         if(i < numDimensions - 1)
         {
             oss << ", ";
         }
     }
     oss << endl;

     oss << "PenColor: " << getColorAsString(pen.color()) << endl;
     oss << "PenWidth: " << pen.width() << endl;
     oss << "PenStyle: " << getPenStyleAsString(pen.style()) << endl;
     oss << "PenCapStyle: " << getCapStyleAsString(pen.capStyle()) << endl;
     oss << "PenJoinStyle: " << getJoinStyleAsString(pen.joinStyle()) << endl;
     oss << "BrushColor: " << getColorAsString(brush.color()) << endl;
     oss << "BrushStyle: " << getBrushStyleAsString(brush.style()) << endl;

     return oss.str();
}
