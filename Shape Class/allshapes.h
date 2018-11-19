#ifndef ALLSHAPES_H_
#define ALLSHAPES_H_

#include "libraries.h"
#include "Shape_List.h"
#include "Parser.h"

class AllShapes
{
    public:
        AllShapes(){}

        ~AllShapes(){}

        void addShapes();

        ShapeLabels::eShapes whatShape(std::string);

        int findShape(int id);

        void deleteShape(int idLoc);

        void printAll();

        // USER INPUTS
        int getSelection();



    // public slots:
    // Button presses, menus go here



    private:
        myVector::vector<Shape*> v_Shapes;
        Parser shapeParser;
};



















#endif /*ALLSHAPES_H_*/
