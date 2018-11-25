#ifndef QTSTRINGS_H
#define QTSTRINGS_H

#include <QPen>
#include <QBrush>
#include <QFont>
#include <string>
using std::string;

const int COLORS = 9;
const int PEN_STYLES = 6;
const int CAP_STYLES = 3;
const int JOIN_STYLES = 3;
const int BRUSH_STYLES = 4;
const int TEXT_ALIGNS = 5;
const int FONT_STYLES = 3;
const int FONT_WEIGHTS = 4;

const string globalColorString[COLORS] {"white", "black", "red", "green", "blue", "cyan", "magenta", "yellow", "gray"};
const string penStyleString[PEN_STYLES]{"NoPen", "SolidLine", "DashLine", "DotLine", "DashDotLine", "DashDotDotLine"};
const string penCapStyleString[CAP_STYLES]{"FlatCap", "SquareCap", "RoundCap"};
const string penJoinStyleString[JOIN_STYLES]{"MiterJoin", "BevelJoin", "RoundJoin"};
const string brushColorString[COLORS] {"white", "black", "red", "green", "blue", "cyan", "magenta", "yellow", "gray"};
const string brushStyleString[BRUSH_STYLES] {"SolidPattern", "HorPattern", "VerPattern", "NoBrush"};
const string textColorString[COLORS] {"white", "black", "red", "green", "blue", "cyan", "magenta", "yellow", "gray"};
const string textAlignmentString[TEXT_ALIGNS] {"AlignLeft", "AlignRight", "AlignTop", "AlignBottom", "AlignCenter"};
const string textFontStyleString[FONT_STYLES] {"StyleNormal", "StyleItalic", "StyleOblique"};
const string textFontWeightString[FONT_WEIGHTS] {"Thin", "Light", "Normal", "Bold"};

const int colorsAr[COLORS] = {3, 2, 7, 14, 9, 10, 11, 12, 5};
const int brushStylesAr[BRUSH_STYLES] = {1, 9, 10, 0};
const int textWeightsAr[FONT_WEIGHTS] = {0, 25, 50, 75};

int findString(const std::string stringAr[], const int AR_SIZE, const std::string theString);
int findStringCustom(const std::string stringAr[], const int actualVal[], const int AR_SIZE, const std::string theString);

// HELPER FUNCTIONS
Qt::GlobalColor convertToGlobalColor(string thisString);
Qt::PenStyle convertToPenStyle(string thisString);
Qt::PenCapStyle convertToPenCapStyle(string thisString);
Qt::PenJoinStyle convertToPenJoinStyle(string thisString);
Qt::BrushStyle convertToBrushStyle(string thisString);
Qt::AlignmentFlag convertToAlignmentFlag(string thisString);
QFont::Style convertToQFontStyle(string thisString);
QFont::Weight convertToQFontWeight(string thisString);

string getColorAsString(QColor color);

string getPenStyleAsString(Qt::PenStyle penStyle);

string getCapStyleAsString(Qt::PenCapStyle capStyle);

string getJoinStyleAsString(Qt::PenJoinStyle joinStyle);

string getBrushStyleAsString(Qt::BrushStyle brushStyle);

string getTextAlignmentAsString(Qt::AlignmentFlag align);

string getFontStyleAsString(QFont::Style style);

string getFontWeightAsString(QFont::Weight weight);

#endif // QTSTRINGS_H
