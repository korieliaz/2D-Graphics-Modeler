/*!
 * \brief   QtConversions Header File - Team Mittens USA
 * \brief   Provides constants, arrays, and functions used in converting basic data types (int, string) to Qt compatible types.
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

#ifndef QTSTRINGS_H
#define QTSTRINGS_H

#include <QPen>
#include <QBrush>
#include <QFont>
#include <string>
using std::string;

//! Qt Conversion Constants
/*! \note These constants represent the number of Qt values used in each aspect of shape rendering (QColor, QPen, QBrush, QFont).
 * \note These values are sizes of string arrays carrying the string equivalent of each relevant Qt value.
 * \note This allows for quick conversion when retrieving data from the shapes input file.
 * \sa Parser::parseShapes()
 */
const int COLORS = 9;       /*!< the number of colors supported by the application */
const int PEN_STYLES = 6;   /*!< the number of pen styles supported by the application */
const int CAP_STYLES = 3;   /*!< the number of pen cap styles supported by the application */
const int JOIN_STYLES = 3;  /*!< the number of pen join styles supported by the application */
const int BRUSH_STYLES = 4; /*!< the number of brush styles supported by the application */
const int TEXT_ALIGNS = 5;  /*!< the number of text alignments supported by the application */
const int FONT_STYLES = 3;  /*!< the number of font styles supported by the application */
const int FONT_WEIGHTS = 4; /*!< the number of font weights supported by the application */

//! Qt Conversion String Arrays
/*! \note These string arrays contain the string equivalents of all Qt pen, brush, and font values that are represented in this application.
 */

//! Array containing all supported QColors.
const string globalColorString[COLORS] {
                                        "white",    /*!< QColor::white */
                                        "black",    /*!< QColor::black */
                                        "red",      /*!< QColor::red */
                                        "green",    /*!< QColor::green or QColor::darkgreen */
                                        "blue",     /*!< QColor::blue */
                                        "cyan",     /*!< QColor::cyan */
                                        "magenta",  /*!< QColor::magenta */
                                        "yellow",   /*!< QColor::yellow */
                                        "gray"      /*!< QColor::gray */
                                        };

//! Array containing all supported pen styles.
const string penStyleString[PEN_STYLES]{
                                        "NoPen",            /*!< Qt::PenStyle::NoPen */
                                        "SolidLine",        /*!< Qt::PenStyle::SolidLine */
                                        "DashLine",         /*!< Qt::PenStyle::DashLine */
                                        "DotLine",          /*!< Qt::PenStyle::DotLine */
                                        "DashDotLine",      /*!< Qt::PenStyle::DashDotLine */
                                        "DashDotDotLine"    /*!< Qt::PenStyle::DashDotDotLine */
                                       };

//! Array containing all supported pen cap styles.
const string penCapStyleString[CAP_STYLES]{
                                            "FlatCap",      /*!< Qt::PenCapStyle::FlatCap */
                                            "SquareCap",    /*!< Qt::PenCapStyle::SquareCap */
                                            "RoundCap"      /*!< Qt::PenCapStyle::RoundCap */
                                          };

//! Array containing all supported pen join styles.
const string penJoinStyleString[JOIN_STYLES]{
                                            "MiterJoin", /*!< Qt::PenJoinStyle::MiterJoin */
                                            "BevelJoin", /*!< Qt::PenJoinStyle::BevelJoin */
                                            "RoundJoin"  /*!< Qt::PenJoinStyle::RoundJoin */
                                            };

//! Array containing all supported brush styles.
const string brushStyleString[BRUSH_STYLES] {
                                            "SolidPattern", /*!< Qt::BrushStyle::SolidPattern */
                                            "HorPattern",   /*!< Qt::BrushStyle::HorPattern */
                                            "VerPattern",   /*!< Qt::BrushStyle::VerPattern */
                                            "NoBrush"       /*!< Qt::BrushStyle::NoBrush */
                                            };

//! Array containing all supported text alignments.
const string textAlignmentString[TEXT_ALIGNS] {
                                                "AlignLeft",    /*!< Qt::AlignmentFlag::AlignLeft */
                                                "AlignRight",   /*!< Qt::AlignmentFlag::AlignRight */
                                                "AlignTop",     /*!< Qt::AlignmentFlag::AlignTop */
                                                "AlignBottom",  /*!< Qt::AlignmentFlag::AlignBottom */
                                                "AlignCenter"   /*!< Qt::AlignmentFlag::AlignCenter */
                                              };

//! Array containing all supported text font styles.
const string textFontStyleString[FONT_STYLES] {
                                                "StyleNormal",  /*!< QFont::Style::StyleNormal */
                                                "StyleItalic",  /*!< QFont::Style::StyleItalic */
                                                "StyleOblique"  /*!< QFont::Style::StyleOblique */
                                              };

//! Array containing all supported text font weights.
const string textFontWeightString[FONT_WEIGHTS] {
                                                "Thin",     /*!< QFont::Weight::Thin */
                                                "Light",    /*!< QFont::Weight::Light */
                                                "Normal",   /*!< QFont::Weight::Normal */
                                                "Bold"      /*!< QFont::Weight::Bold */
                                                };

//! Array containing all Qt specific enumeration values for supported colors.
const int colorsAr[COLORS] = {
                                3,  /*!< QColor::white */
                                2,  /*!< QColor::black */
                                7,  /*!< QColor::red */
                                14, /*!< QColor::green */
                                9,  /*!< QColor::blue */
                                10, /*!< QColor::cyan */
                                11, /*!< QColor::magenta */
                                12, /*!< QColor::yellow */
                                5   /*!< QColor::gray */
                             };

//! Array containing all Qt specific enumeration values for supported brush styles.
const int brushStylesAr[BRUSH_STYLES] = {
                                        1,  /*!< Qt::BrushStyle::SolidPattern */
                                        9,  /*!< Qt::BrushStyle::HorPattern */
                                        10, /*!< Qt::BrushStyle::VerPattern */
                                        0   /*!< Qt::BrushStyle::NoBrush */
                                        };

//! Array containing all Qt specific enumeration values for supported font weights.
const int textWeightsAr[FONT_WEIGHTS] = {
                                        0,  /*!< QFont::Weight::Thin */
                                        25, /*!< QFont::Weight::Light */
                                        50, /*!< QFont::Weight::Normal */
                                        75  /*!< QFont::Weight::Bold */
                                        };

//! Qt Conversion Helper Functions
/*! \note These functions convert between C++ and Qt specific data types and values to allow for easier readability and code coordination.
 */

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
