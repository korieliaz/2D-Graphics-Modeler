#include "selectionsort.h"

//! Compares the current largest perimeter to the perimeter of the current Shape in the vector.
bool perimeterCompare(Shape* bestShape, Shape* currentShape)
{
    return (bestShape -> calcPerimeter() > currentShape -> calcPerimeter());
}

//! Compares the current largest area to the area of the current Shape in the vector.
bool areaCompare(Shape* bestShape, Shape* currentShape)
{
    return (bestShape -> calcArea() > currentShape -> calcArea());
}

//! Compares the current largest ID to the ID of the current Shape in the vector.
bool idCompare(Shape* bestShape, Shape* currentShape)
{
    /*! Throws an exception if two ID's are the same. */
    try
    {
        if(*currentShape == *bestShape)
        {
            throw shapeException("\n***ERROR - TWO SHAPES CANNOT HAVE THE SAME ID***\n\n");
        }
    }
    catch(shapeException idEx)
    {
        cout << idEx.what();
    }

    return (*currentShape < *bestShape);
}

//! Performs a sort of the vector based on ID, perimeter, or area. */
void selectionSort(myVector::vector<Shape*> &vector, bool(*compareFunction)(Shape*, Shape*))
{
    int i_best{0};

    for(int i_start{0}; i_start < vector.size(); ++i_start)
    {
        i_best = i_start;

        for(int i_current = i_start + 1; i_current < vector.size(); ++i_current)
        {
            if(compareFunction(vector[i_best], vector[i_current]))
            {
                i_best = i_current;
            }
        }

        std::swap(vector[i_start], vector[i_best]);
    }
}
