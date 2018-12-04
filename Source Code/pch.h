/*!
 * \brief   PCH Header File - Team Mittens USA
 * \brief   Pre-Compiled Headers: expedites compile time.
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

#ifndef PCH_H
#define PCH_H

//! Allows use of the QWidget library.
#include <QWidget>

//! Allows use of the libraries included in the libraries.h header file.
#include "libraries.h"

//! Allows use of the custom vector.
#include "vector.h"

//! Allows use of the custom selection sort algorithms.
#include "selectionsort.h"

//! Allows use of the custom math functions.
#include "custommath.h"

//! Allows use of the overriden std::exception class.
#include "shapeexception.h"

//! Allows use of the class containing conversion functions, arrays, and enumerations between Qt and C++.
#include "qtconversions.h"

#endif // PCH_H
