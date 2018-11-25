#include "allshapes.h"
#include <sstream>

void AllShapes::addShapesFromFile()
{
    shapeCount = shapeParser.parseShapes(v_Shapes, device);
}

void AllShapes::newShape(Shape *newShape)
{
    v_Shapes.push_back(newShape);
}

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

ShapeLabels::eShapes whatShape(std::string thisName)
{
    int i{0};

    while(thisName != ShapeLabels::SHAPES_LIST[i])
    {
        ++i;
    }

    return ShapeLabels::eShapes(i);
}

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


void AllShapes::printAll()
{
     fstream fout("shapes.txt", ios::out);

//     for(Shape *it : v_Shapes)
//     {
//         fout << it -> print();

//         if(it != *(v_Shapes.end()))
//         {
//             fout << endl;
//         }
//     }

     myVector::vector<Shape*>::iterator it = v_Shapes.begin();
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
