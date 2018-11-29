#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "vector.h"
#include "shape.h"

bool perimeterCompare(Shape* bestShape, Shape* currentShape);

bool areaCompare(Shape* bestShape, Shape* currentShape);

bool idCompare(Shape* bestShape, Shape* currentShape);

void selectionSort(myVector::vector<Shape*> &vector, bool(*compareFunction)(Shape*, Shape*));

#endif // SELECTIONSORT_H
