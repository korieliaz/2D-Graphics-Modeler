/*!
 * \brief   AllShapes CPP File - Team Mittens USA
 * \authors Kori Eliaz          <korieliaz@outlook.com>
 * \authors Trevor Dunham       <trevor_d@outlook.com>
 * \authors Michael Sinclair    <masinclair2@gmail.com>
 * \authors Brian Ferguson      <bferguson@gmail.com>
 * \authors Mariah Harris       <mariahh2017@gmail.com>
 * \authors Ali Bingol          <mythologyali@gmail.com>
 * \authors Peter Win           <peterzin@gmail.com>
 * \authors Braden Wurlitzer    <wurlitzerb@gmail.com>
 * \date    Fall 2018
 * \copyright Team Mittens USA
 * \copyright CS1C w/ Professor John Kath
 * \copyright Saddleback College
*/

#include "allshapes.h"
#include <sstream>

//! Adds shapes from the input file.
void AllShapes::addShapesFromFile()
{
    shapeCount = shapeParser.parseShapes(v_Shapes, device);

    setCurrentID();
}

//! Sets the current largest ID number in the vector.
void AllShapes::setCurrentID()
{
    int current{0};

    for(int i = 0; i < v_Shapes.size(); i++)
    {
        if(v_Shapes[i+1] > v_Shapes[i])
        {
            current = v_Shapes[i]->getID();
        }
    }

    currentID = current;
}

//! Adds a new shape to the vector.
void AllShapes::newShape(Shape *newShape)
{
    v_Shapes.push_back(newShape);
}

//! (1 of 3) Edits the properties of a line or polyline in the vector.
void AllShapes::editShape(int id, const int NUM_SPECS, dim::specs *dims, const QPen &pen)
{
    myVector::vector<Shape*>::iterator it = v_Shapes.begin();
    bool found = false;

    while(it != v_Shapes.end() && !found)
    {
        if((*it) -> getID() == id)
        {
            found = true;
            (*it)->setBaseInfo(id, findShape(id), NUM_SPECS, dims);
            (*it)->setPosition();
            (*it)->setPen(pen);
        }
        else
        {
            it++;
        }
     }
}

//! (2 of 3) Edits the properties of a polygon, rectangle, square, ellipse, or circle in the vector.
void AllShapes::editShape(int id, const int NUM_SPECS, dim::specs *dims, const QPen &pen, const QBrush &brush)
{
    myVector::vector<Shape*>::iterator it = v_Shapes.begin();
    bool found = false;

    while(it != v_Shapes.end() && !found)
    {
        if((*it) -> getID() == id)
        {
            found = true;
            (*it)->setBaseInfo(id, findShape(id), NUM_SPECS, dims);
            (*it)->setPosition();
            (*it)->setPen(pen);
            (*it)->setBrush(brush);
        }
        else
        {
            it++;
        }
    }
}

//! (3 of 3) Edits the properties of a text box in the vector.
void AllShapes::editShape(int id, const int NUM_SPECS, dim::specs *dims, const QPen &pen, const QFont &font, Qt::AlignmentFlag flag, string text)
{
    myVector::vector<Shape*>::iterator it = v_Shapes.begin();
    bool found = false;

    while(it != v_Shapes.end() && !found)
    {
        if((*it) -> getID() == id)
        {
            found = true;
            (*it)->setBaseInfo(id, findShape(id), NUM_SPECS, dims);
            (*it)->setPosition();
            (*it)->setPen(pen);
            (*it)->setFont(font);
            (*it)->setAlignment(flag);
            (*it)->setText(text);
        }
        else
        {
            it++;
        }
    }
}

//! Moves a shape by a certain x and y shift.
void AllShapes::moveShape(int id, const QPoint &shift)
{
    myVector::vector<Shape*>::iterator it = v_Shapes.begin();
    bool found = false;

    while(it != v_Shapes.end() && !found)
    {
        if((*it) -> getID() == id)
        {
            found = true;
            (*it)->move(shift);
        }
        else
        {
            it++;
        }
    }
}

//! Finds a shape by its ID number and returns its shape type as a string.
string AllShapes::findShape(int id)
{
    myVector::vector<Shape*>::iterator it = v_Shapes.begin();
    bool found = false;
    string shapeType{""};

    while(it != v_Shapes.end() && !found)
    {
        if((*it) -> getID() == id)
        {
            found = true;
            shapeType = (*it)->getType();
        }
        else
        {
            it++;
        }
     }

    return shapeType;
}

//! Finds a shape by its ID number and returns a pointer to its location in the vector.
Shape* AllShapes::findShapePtr(int id)
{
    myVector::vector<Shape*>::iterator it = v_Shapes.begin();
    bool found = false;
    Shape* p_Shape{nullptr};

    while(it != v_Shapes.end() && !found)
    {
        if((*it) -> getID() == id)
        {
            found = true;
            p_Shape = (*it);
        }
        else
        {
            it++;
        }
     }

    return p_Shape;
}

//! Deletes a shape from the vector.
void AllShapes::deleteShape(int id)
{
    myVector::vector<Shape*>::iterator it = v_Shapes.begin();
    bool found = false;

    while(it != v_Shapes.end() && !found)
    {
        if((*it) -> getID() == id)
        {
            found = true;
            v_Shapes.erase(it);
        }
        else
        {
            it++;
        }
     }
}

//! Prints all the shapes' information to the output file.
void AllShapes::printAll()
{
     fstream fout("shapes.txt", ios::out);

     myVector::vector<Shape*>::const_iterator it = v_Shapes.begin();
     int i{0};

     while(it != v_Shapes.end())
     {
         fout << (*it) -> print();

         if(i < (v_Shapes.size() - 1))
         {
             fout << endl;
             ++i;
         }

         it++;
     }

     fout.close();
}
