#ifndef PARSER_H
#define PARSER_H

#include "libraries.h"
#include "Shape_List.h"
#include "qtconversions.h"
#include "shapeexception.h"
#include <fstream>
#include <sstream>

using namespace std;

class Parser
{
    public:
        string getStringFromFile(fstream &file);
        void parseShapes(myVector::vector<Shape*> &v_shapes);
        Shape* getShapePtr(std::string shapeType);

        void closeFile(fstream &);
};

#endif // PARSER_H
