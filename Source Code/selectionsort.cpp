#include "selectionsort.h"

bool perimeterCompare(Shape* bestShape, Shape* currentShape)
{
    return (bestShape -> calcPerimeter() > currentShape -> calcPerimeter());
}

bool areaCompare(Shape* bestShape, Shape* currentShape)
{
    return (bestShape -> calcArea() > currentShape -> calcArea());
}

bool idCompare(Shape* bestShape, Shape* currentShape)
{
    return (*currentShape < *bestShape);
}

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
