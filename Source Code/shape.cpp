#include "shape.h"
#include "qtconversions.h"
#include <sstream>
using std::endl;

void Shape::setBaseInfo(int shapeId, std::string shapeType, int numDimensions, dim::specs* otherDimensions)
{
    // DELETES FORMER DATA IF IT HAS TO BE OVERRIDEN
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
