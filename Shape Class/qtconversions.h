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

int findString(const std::string stringAr[], const int AR_SIZE, const std::string theString)
{
    int i{0};
    bool notSame{true};

    // EXCEPTION HERE
    do
    {
        notSame = stringAr[i] != theString;
        ++i;

    }while(i < AR_SIZE && notSame);

    if(notSame)
    {
        return -1;
    }
    return i;
}

// HELPER FUNCTIONS
Qt::GlobalColor convertToGlobalColor(string thisString) {return Qt::GlobalColor(findString(globalColorString, COLORS, thisString));}
Qt::PenStyle convertToPenStyle(string thisString) {return Qt::PenStyle(findString(penStyleString, PEN_STYLES, thisString));}
Qt::PenCapStyle convertToPenCapStyle(string thisString) {return Qt::PenCapStyle(findString(penCapStyleString, CAP_STYLES, thisString));}
Qt::PenJoinStyle convertToPenJoinStyle(string thisString) {return Qt::PenJoinStyle(findString(penJoinStyleString, JOIN_STYLES, thisString));}
Qt::BrushStyle convertToBrushStyle(string thisString) {return Qt::BrushStyle(findString(brushStyleString, BRUSH_STYLES, thisString));}
Qt::AlignmentFlag convertToAlignmentFlag(string thisString) {return Qt::AlignmentFlag(findString(textAlignmentString, TEXT_ALIGNS, thisString));}
QFont::Style convertToQFontStyle(string thisString) {return QFont::Style(findString(textFontStyleString, FONT_STYLES, thisString));}
QFont::Weight convertToQFontWeight(string thisString) {return QFont::Weight(findString(textFontWeightString, FONT_WEIGHTS, thisString));}

string getColorAsString(QColor color)
{
    string colorStr;

    if(color == Qt::white)
        colorStr = globalColorString[0];    //white
    else if(color == Qt::black)
        colorStr = globalColorString[1];    //black
    else if(color == Qt::red)
        colorStr = globalColorString[2];    //red
    else if(color == Qt::green)
        colorStr = globalColorString[3];    //green
    else if(color == Qt::blue)
        colorStr = globalColorString[4];    //blue
    else if(color == Qt::cyan)
        colorStr = globalColorString[5];    //cyan
    else if(color == Qt::magenta)
        colorStr = globalColorString[6];    //magenta
    else if(color == Qt::yellow)
        colorStr = globalColorString[7];    //yellow
    else
        colorStr = globalColorString[8];    //gray

    return colorStr;
}

string getPenStyleAsString(Qt::PenStyle penStyle)
{
    string penStyleStr;

    if(penStyle == Qt::NoPen)
        penStyleStr = penStyleString[0];    //NoPen
    else if(penStyle == Qt::SolidLine)
        penStyleStr = penStyleString[1];    //SolidLine
    else if(penStyle == Qt::DashLine)
        penStyleStr = penStyleString[2];    //DashLine
    else if(penStyle == Qt::DotLine)
        penStyleStr = penStyleString[3];    //DotLine
    else if(penStyle == Qt::DashDotLine)
        penStyleStr = penStyleString[4];    //DashDotLine
    else
        penStyleStr = penStyleString[5];    //DashDotDotLine

    return penStyleStr;
}

string getCapStyleAsString(Qt::PenCapStyle capStyle)
{
    string capStyleStr;

    if(capStyle == Qt::FlatCap)
        capStyleStr = penCapStyleString[0]; //FlatCap
    else if(capStyle == Qt::SquareCap)
        capStyleStr = penCapStyleString[1]; //SquareCap
    else
        capStyleStr = penCapStyleString[2]; //RoundCap

    return capStyleStr;
}

string getJoinStyleAsString(Qt::PenJoinStyle joinStyle)
{
    string joinStyleStr;

    if(joinStyle == Qt::MiterJoin)
        joinStyleStr = penJoinStyleString[0];   //MiterJoin
    else if(joinStyle == Qt::BevelJoin)
        joinStyleStr = penJoinStyleString[1];   //BevelJoin
    else
        joinStyleStr = penJoinStyleString[2];   //RoundJoin

    return joinStyleStr;
}

string getBrushStyleAsString(Qt::BrushStyle brushStyle)
{
    string brushStyleStr;

    if(brushStyle == Qt::SolidPattern)
        brushStyleStr = brushStyleString[0];    //SolidPattern
    else if(brushStyle == Qt::HorPattern)
        brushStyleStr = brushStyleString[1];    //HorPattern
    else if(brushStyle == Qt::VerPattern)
        brushStyleStr = brushStyleString[2];    //VerPattern
    else
        brushStyleStr = brushStyleString[3];    //NoBrush

    return brushStyleStr;
}

string getTextAlignmentAsString(Qt::AlignmentFlag align)
{
    string alignStr;

    if(align == Qt::AlignLeft)
        alignStr = textAlignmentString[0];  //AlignLeft
    else if(align == Qt::AlignRight)
        alignStr = textAlignmentString[1];  //AlignRight
    else if(align == Qt::AlignTop)
        alignStr = textAlignmentString[2];  //AlignTop
    else if(align == Qt::AlignBottom)
        alignStr = textAlignmentString[3];  //AlignBottom
    else
        alignStr = textAlignmentString[4];  //AlignCenter

    return alignStr;
}

string getFontStyleAsString(QFont::Style style)
{
    string styleStr;

    if(style == QFont::StyleNormal)
        styleStr = textFontStyleString[0];  //StyleNormal
    else if(style == QFont::StyleItalic)
        styleStr = textFontStyleString[1];  //StyleItalic
    else
        styleStr = textFontStyleString[2];  //StyleOblique

    return styleStr;
}

string getFontWeightAsString(QFont::Weight weight)
{
    string weightStr;

    if(weight == QFont::Thin)
        weightStr = textFontWeightString[0];    //Thin
    else if(weight == QFont::Light)
        weightStr = textFontWeightString[1];    //Light
    else if(weight == QFont::Normal)
        weightStr = textFontWeightString[2];    //Normal
    else
        weightStr = textFontWeightString[3];    //Bold

    return weightStr;
}

#endif // QTSTRINGS_H
