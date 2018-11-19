#include "AllShapes.h"
#include <sstream>

void AllShapes::addShapes()
{
    shapeParser.parseShapes(v_Shapes);
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

void AllShapes::printAll()
{
     fstream fout("shapes.txt", ios::out);

     for(Shape *it : v_Shapes)
     {
         fout << it -> print();
         fout << endl;
     }

     fout.close();
}

int AllShapes::findShape(int id)
{
    myVector::vector<Shape*>::iterator it = v_Shapes.begin();
    bool found = false;
    int i{0};

    while(it != v_Shapes.end() && !found)
    {
        if((*it) -> getID() == id)
        {
            found = true;
        }
        else
        {
            it++;
            i++;
        }
     }

    return i;
}

void AllShapes::deleteShape(int idLoc)
{
    try
    {
        if(idLoc != v_Shapes.size())
        {
            v_Shapes.erase(v_Shapes.begin() + idLoc);
        }
        else
        {
            throw shapeException("\n***ERROR - COULD NOT FIND SHAPE TO BE DELETED***\n\n");
        }
    }
    catch(shapeException deleteEx)
    {
        cout << deleteEx.what();
    }

}
