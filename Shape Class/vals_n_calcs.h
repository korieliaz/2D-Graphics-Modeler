#ifndef VALS_N_CALCS_H_
#define VALS_N_CALCS_H_

#include <cmath>

namespace dim
{
    typedef int coord;
    typedef int side;
    typedef int radius;
    typedef int axis;

    typedef int specs;

    typedef double area;
    typedef double perimeter;

    const double PI = 3.1415953589793;

}
// --------------------------------------------------------------------------

// MULTIPLY, TAKES UP TO FOUR VALUES OF ANY KIND
// Two vals
template<typename T, typename U>
dim::specs multiply(T A, U B){return A * B;}
// Three vals
template<typename T, typename U, typename V>
dim::specs multiply(T A, U B, V C){return A * B * C;}
// Four vals
template<typename T, typename U, typename V, typename W>
dim::specs multiply(T A, U B, V C, W D){return A * B * C * D;}
// --------------------------------------------------------------------------

// DISTANCE BETWEEN POINTS
template <typename T>
double distance(T x0, T x1, T y0, T y1)
{
    return sqrt(pow(float(x1 - x0),2.0) + pow(float(y1 - y0),2.0));
}
// --------------------------------------------------------------------------

// DETERMINANT OF A 2x2 MATRIX
template <typename T>
double determinant(T x0, T x1, T y0, T y1)
{
    return (x0 * y1) - (x1 * y0);
}

#endif /*VALS_N_CALCS_H_*/
