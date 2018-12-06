/*!
 * \file    custommath.h
 * \brief   Custom templated math functions including multiplication, distance, and determinant.
*/

#ifndef CUSTOMMATH_H_
#define CUSTOMMATH_H_

#include <cmath>

/*! \namespace <dim>
 * \brief Holds all typedef dimensions of a shape allowing for increased readability.
 */
namespace dim
{
    typedef int coord;  /*!< a coordinate point */
    typedef int side;   /*!< a side length */
    typedef int radius; /*!< a radius */
    typedef int axis;   /*!< a major/minor axis */

    typedef int specs;  /*!< the number of shape specifications */

    typedef double area;    /*!< the area of a shape */
    typedef double perimeter;   /*!< the perimeter of a shape */

    const double PI = 3.1415953589793;  /*!< the constant PI, to 13 decimal places */
}

//! Templated function that multiplies 2 values of any two types.
/*! Overloaded function (1 of 3) - Multiples 2 values together.
 * \param A a value of type T to be multipled
 * \param B a value of type U to be multiplied
 * \returns the product of A and B
 */
template<typename T, typename U>
dim::specs multiply(T A, U B){return A * B;}

//! Templated function that multiplies 3 values of any three types.
/*! Overloaded function (2 of 3) - Multiples 3 values together.
 * \param A a value of type T to be multipled
 * \param B a value of type U to be multiplied
 * \param C a value of type V to be multipled
 * \returns the product of A, B, and C
 */
template<typename T, typename U, typename V>
dim::specs multiply(T A, U B, V C){return A * B * C;}

//! Templated function that multiplies 4 values of any four types.
/*! Overloaded function (3 of 3) - Multiples 4 values together.
 * \param A a value of type T to be multipled
 * \param B a value of type U to be multiplied
 * \param C a value of type V to be multipled
 * \param D a value of type W to be multiplied
 * \returns the product of A, B, C, and D
 */
template<typename T, typename U, typename V, typename W>
dim::specs multiply(T A, U B, V C, W D){return A * B * C * D;}

//! Templated function that calculates the distance between two points
/*! Point 1: (x0, y0)
 * Point 2: (x1, y1)
 * All parameters must be of the same type.
 * \param x0 the x coordinate of the first point
 * \param x1 the x coordinate of the second point
 * \param y0 the y coordinate of the first point
 * \param y1 the y coordinate of the second point
 * \returns the distance between the two points
 */
template <typename T>
double distance(T x0, T x1, T y0, T y1)
{
    return sqrt(pow(float(x1 - x0),2.0) + pow(float(y1 - y0),2.0));
}

//! Templated function that calculates the determinant of a 2x2 matrix
/*! Used to determine the area of a polygon
 * A visual representation of the matrix is as follows:
 *
 * | x0   y0 |
 * |         |
 * | x1   y1 |
 *
 * All parameters must be of the same type.
 * \param x0 the x coordinate of a point
 * \param y0 the y coordinate of a point
 * \param x1 the x coordinate of another point
 * \param y1 the y coordinate of another point
 * \returns the determinant of the 2x2 matrix made of these 4 coordinates
 */
template <typename T>
double determinant(T x0, T x1, T y0, T y1)
{
    return ((x0 * y1) - (x1 * y0));
}

#endif /*CUSTOMMATH_H_*/
