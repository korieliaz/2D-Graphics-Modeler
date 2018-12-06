/*!
 * \file qtconversions.h
 * \brief   Provides constants, arrays, and functions used in converting basic data types (int, string) to Qt compatible types.
 * \note The constants in this file represent the number of Qt values used in each aspect of shape rendering (QColor, QPen, QBrush, QFont).
 * These values are sizes of string arrays carrying the string equivalent of each relevant Qt value.
 * This allows for quick conversion when retrieving data from the shapes input file.
 * \note The string arrays in this file contain the string equivalents of all Qt pen, brush, and font values that are represented in this application.
 * \note These functions convert between C++ and Qt specific data types and values to allow for easier readability and code coordination.
*/

#ifndef QTSTRINGS_H
#define QTSTRINGS_H

#include <QPen>
#include <QBrush>
#include <QFont>
#include <string>
using std::string;


const int COLORS = 9;       /*!< the number of colors supported by the application */
const int PEN_STYLES = 6;   /*!< the number of pen styles supported by the application */
const int CAP_STYLES = 3;   /*!< the number of pen cap styles supported by the application */
const int JOIN_STYLES = 3;  /*!< the number of pen join styles supported by the application */
const int BRUSH_STYLES = 4; /*!< the number of brush styles supported by the application */
const int TEXT_ALIGNS = 5;  /*!< the number of text alignments supported by the application */
const int FONT_STYLES = 3;  /*!< the number of font styles supported by the application */
const int FONT_WEIGHTS = 4; /*!< the number of font weights supported by the application */

//! Array containing all supported QColor values.
const string globalColorString[COLORS]
{
    "white",
    "black",
    "red",
    "green",
    "blue",
    "cyan",
    "magenta",
    "yellow",
    "gray"
};

//! Array containing all supported Qt::PenStyle values.
const string penStyleString[PEN_STYLES]
{
    "NoPen",
    "SolidLine",
    "DashLine",
    "DotLine",
    "DashDotLine",
    "DashDotDotLine"
};

//! Array containing all supported Qt::PenCapStyle values.
const string penCapStyleString[CAP_STYLES]
{
    "FlatCap",
    "SquareCap",
    "RoundCap"
};

//! Array containing all supported Qt::PenJoinStyle values.
const string penJoinStyleString[JOIN_STYLES]
{
    "MiterJoin",
    "BevelJoin",
    "RoundJoin"
};

//! Array containing all supported Qt::BrushStyle values.
const string brushStyleString[BRUSH_STYLES]
{
    "SolidPattern",
    "HorPattern",
    "VerPattern",
    "NoBrush"
};

//! Array containing all supported Qt::AlignmentFlag values.
const string textAlignmentString[TEXT_ALIGNS]
{
    "AlignLeft",
    "AlignRight",
    "AlignTop",
    "AlignBottom",
    "AlignCenter"
};

//! Array containing all supported QFont::Style values.
const string textFontStyleString[FONT_STYLES]
{
    "StyleNormal",
    "StyleItalic",
    "StyleOblique"
};

//! Array containing all supported QFont::Weight values.
const string textFontWeightString[FONT_WEIGHTS]
{
    "Thin",
    "Light",
    "Normal",
    "Bold"
};

//! Array containing all Qt specific enumeration values for supported colors.
const int colorsAr[COLORS] =
{
    3,
    2,
    7,
    14,
    9,
    10,
    11,
    12,
    5
};

//! Array containing all Qt specific enumeration values for supported brush styles.
const int brushStylesAr[BRUSH_STYLES] =
{
    1,
    9,
    10,
    0
};

//! Array containing all Qt specific enumeration values for supported font weights.
const int textWeightsAr[FONT_WEIGHTS] =
{
    0,
    25,
    50,
    75
};


//! Finds the string in the Qt string array and returns its Qt specific enumeration value.
/*! \param stringAr[] the array of strings related to the string being located
 * \param AR_SIZE the size of the arrray of strings related to the string being located
 * \param theString the string being located
 * \returns The Qt specific enumeration value of the string being located.
 */
int findString(const std::string stringAr[], const int AR_SIZE, const std::string theString);

//! Finds the string in the Qt string array and returns its Qt specific enumeration value.
/*! Used when the enumeration value does not correspond to a natural incrementing pattern.
 * Used specifically when finding the enumeration value of a QColor, Qt::BrushStyle, or QFont::Weight.
 * \param stringAr[] the array of strings related to the string being located
 * \param actualVal[] the array of enumeration values related to the item being located
 * \param AR_SIZE the size of the arrray of strings related to the string being located
 * \param theString the string being located
 * \returns The Qt specific enumeration value of the string being located.
 */
int findStringCustom(const std::string stringAr[], const int actualVal[], const int AR_SIZE, const std::string theString);

//! Converts a string equivalent of a QColor to an actual Qt::GlobalColor type.
/*! \param thisString the string equivalent of a QColor
 * \sa Parser::parseShapes()
 */
Qt::GlobalColor convertToGlobalColor(string thisString);

//! Converts a string equivalent of a Qt::PenStyle to an actual Qt::PenStyle type.
/*! \param thisString the string equivalent of a Qt::PenStyle
 * \sa Parser::parseShapes()
 */
Qt::PenStyle convertToPenStyle(string thisString);

//! Converts a string equivalent of a Qt::PenCapStyle to an actual Qt::PenCapStyle type.
/*! \param thisString the string equivalent of a Qt::PenCapStyle
 * \sa Parser::parseShapes()
 */
Qt::PenCapStyle convertToPenCapStyle(string thisString);

//! Converts a string equivalent of a Qt::PenJoinStyle to an actual Qt::PenJoinStyle type.
/*! \param thisString the string equivalent of a Qt::PenJoinStyle
 * \sa Parser::parseShapes()
 */
Qt::PenJoinStyle convertToPenJoinStyle(string thisString);

//! Converts a string equivalent of a Qt::BrushStyle to an actual Qt::BrushStyle type.
/*! \param thisString the string equivalent of a Qt::BrushStyle
 * \sa Parser::parseShapes()
 */
Qt::BrushStyle convertToBrushStyle(string thisString);

//! Converts a string equivalent of a Qt::AlignmentFlag to an actual Qt::AlignmentFlag type.
/*! \param thisString the string equivalent of a Qt::AlignmentFlag
 * \sa Parser::parseShapes()
 */
Qt::AlignmentFlag convertToAlignmentFlag(string thisString);

//! Converts a string equivalent of a QFont::Style to an actual QFont::Style type.
/*! \param thisString the string equivalent of a QFont::PenStyle
 * \sa Parser::parseShapes()
 */
QFont::Style convertToQFontStyle(string thisString);

//! Converts a string equivalent of a QFont::Weight to an actual QFont::Weight type.
/*! \param thisString the string equivalent of a QFont::Weight
 * \sa Parser::parseShapes()
 */
QFont::Weight convertToQFontWeight(string thisString);

//! Converts a QColor to its string equivalent.
/*! \param color the QColor value that needs to be converted back to a representative string
 * \sa Shape::print()
 */
string getColorAsString(QColor color);

//! Converts a Qt::PenStyle to its string equivalent.
/*! \param penStyle the Qt::PenStyle value that needs to be converted back to a representative string
 * \sa Shape::print()
 */
string getPenStyleAsString(Qt::PenStyle penStyle);

//! Converts a Qt::PenCapStyle to its string equivalent.
/*! \param capStyle the Qt::PenCapStyle value that needs to be converted back to a representative string
 * \sa Shape::print()
 */
string getCapStyleAsString(Qt::PenCapStyle capStyle);

//! Converts a Qt::PenJoinStyle to its string equivalent.
/*! \param joinStyle the Qt::PenJoinStyle value that needs to be converted back to a representative string
 * \sa Shape::print()
 */
string getJoinStyleAsString(Qt::PenJoinStyle joinStyle);

//! Converts a Qt::BrushStyle to its string equivalent.
/*! \param brushStyle the Qt::BrushStyle value that needs to be converted back to a representative string
 * \sa Shape::print()
 */
string getBrushStyleAsString(Qt::BrushStyle brushStyle);

//! Converts a Qt::AlignmentFlag to its string equivalent.
/*! \param align the Qt::AlignmentFlag value that needs to be converted back to a representative string
 * \sa Text::print()
 */
string getTextAlignmentAsString(Qt::AlignmentFlag align);

//! Converts a QFont::Style to its string equivalent.
/*! \param style the QFont::Style value that needs to be converted back to a representative string
 * \sa Text::print()
 */
string getFontStyleAsString(QFont::Style style);

//! Converts a QFont::Weight to its string equivalent.
/*! \param weight the QFont::Weight value that needs to be converted back to a representative string
 * \sa Text::print()
 */
string getFontWeightAsString(QFont::Weight weight);

#endif // QTSTRINGS_H
