/*!
 * \file selectionsort.h
 * \brief   Provides a custom bank of templated selection sort algorithms that compare shape perimeters, areas, and ID numbers and sort them from least to greatest.
 * \brief   Each comparison function is passed into the main selectionSort function via a function pointer.
*/

#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "vector.h"
#include "shape.h"
#include "shapeexception.h"

//! Compares shape perimeters.
/*! Used to sort the shape vector from smallest perimeter to largest perimeter.
 * Lines and polylines interpret perimeter as total length. Their lengths are factored into this comparison.
 * \param bestShape a pointer to the Shape with the current largest perimeter.
 * \param currentShape a pointer to the current Shape in the vector that is being compared
 * \returns A boolean expression
 * \returns TRUE: currentShape's perimeter is greater than bestShape's perimeter
 * \returns FALSE: currentShape's perimeter is less than or equal to bestShape's perimeter
 * \sa MainWindow::sortPerimeterTable()
 */
bool perimeterCompare(Shape* bestShape, Shape* currentShape);

//! Compares shape areas.
/*! Used to sort the shape vector from smallest area to largest area.
 * Lines, polylines, and text boxes are set to area 0.
 * \param bestShape a pointer to the Shape with the current largest area.
 * \param currentShape a pointer to the current Shape in the vector that is being compared
 * \returns A boolean expression
 * \returns TRUE: currentShape's area is greater than bestShape's area
 * \returns FALSE: currentShape's area is less than or equal to bestShape's area
 * \sa MainWindow::sortAreaTable()
 */
bool areaCompare(Shape* bestShape, Shape* currentShape);

//! Compares shape ID's.
/*! Used to sort the shape vector from smallest ID to largest ID.
 * Makes use of two overloaded operators for Shape: == and <
 * If two shapes have the same ID numbers, this function will throw an exception and output an error message.
 * Code to prevent this from happening is included in the AllShapes class. The exception is kept in the case of future modifications and testing.
 * \sa AllShapes::setCurrentID
 * \param bestShape a pointer to the Shape with the current largest ID.
 * \param currentShape a pointer to the current Shape in the vector that is being compared
 * \returns A boolean expression
 * \returns TRUE: currentShape's ID is greater than bestShape's ID
 * \returns FALSE: currentShape's ID is less than or equal to bestShape's ID
 * \sa MainWindow::sortIDTable()
 */
bool idCompare(Shape* bestShape, Shape* currentShape);

//! Performs a selection sort on the passed in Shape vector.
/*! Uses a function pointer to a specific comparison function to determine how the Shape vector will be sorted.
 * \param vector the Shape vector, passed in by reference
 * \param compareFunction(Shape*, Shape*) the function pointer to the comparison function
 * \sa MainWindow::sortPerimeterTable()
 * \sa MainWindow::sortAreaTable()
 * \sa MainWindow::sortIDTable()
 */
void selectionSort(myVector::vector<Shape*> &vector, bool(*compareFunction)(Shape*, Shape*));

#endif // SELECTIONSORT_H
