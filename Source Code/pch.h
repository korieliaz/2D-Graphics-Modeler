/*!
 * \file pch.h
 * \brief  Lists the pre-compiled header files for the application. Expedites compile time.
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
