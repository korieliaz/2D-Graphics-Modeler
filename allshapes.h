#ifndef ALLSHAPES_H_
#define ALLSHAPES_H_

#include "libraries.h"
#include "shape_list.h"
#include "parser.h"

class AllShapes
{
    public:
        AllShapes(QPaintDevice *device) : shapeCount{0}, device{device} {}

        ~AllShapes(){}

        void addShapesFromFile();

        void newShape(Shape *newShape);

        void editShape(int id, const int NUM_SPECS, dim::specs *dims, const QPen &pen);

        void editShape(int id, const int NUM_SPECS, dim::specs *dims, const QPen &pen, const QBrush &brush);

        void editShape(int id, const int NUM_SPECS, dim::specs *dims, const QPen &pen, const QFont &font, Qt::AlignmentFlag flag, string text);

        void moveShape(int id, const QPoint &shift);

        string findShape(int id);

        Shape* findShapePtr(int id);

        int getShapeCount() {return v_Shapes.size();}

        myVector::vector<Shape*>& getVector() {return v_Shapes;}

        int incrementShapeCount() {return ++shapeCount;}

        void deleteShape(int id);

        void printAll();

private:
        myVector::vector<Shape*> v_Shapes;
        Parser shapeParser;
        int shapeCount;
        QPaintDevice *device;
};



















#endif /*ALLSHAPES_H_*/
