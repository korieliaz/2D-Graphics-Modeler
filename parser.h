#ifndef PARSER_H
#define PARSER_H

#include "libraries.h"
#include "shape_list.h"
#include "qtconversions.h"
#include "shapeexception.h"
#include <sstream>

using namespace std;

class Parser
{
    public:
        Parser() {}
        ~Parser() {}

        string getStringFromFile(fstream &file);
        int parseShapes(myVector::vector<Shape*> &v_shapes, QPaintDevice *device);
        Shape* getShapePtr(std::string shapeType, QPaintDevice *device);
};

#endif // PARSER_H
