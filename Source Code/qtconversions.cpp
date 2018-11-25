#include "qtconversions.h"
#include <iostream>
int findString(const std::string stringAr[], const int AR_SIZE, const std::string theString)
{
    int i{0};
    bool notSame{true};

    notSame = stringAr[i] != theString;

    // EXCEPTION HERE
    while(i < AR_SIZE && notSame)
    {
        ++i;
        notSame = stringAr[i] != theString;
    }

    if(notSame)
    {
        return -1;
    }
    else
    {
        return i;
    }
}

int findStringCustom(const std::string stringAr[], const int actualVal[], const int AR_SIZE, const std::string theString)
{
    int i{0};
    bool notSame{true};

    notSame = stringAr[i] != theString;

    // EXCEPTION HERE
    while(i < AR_SIZE && notSame)
    {
        ++i;
        notSame = stringAr[i] != theString;
    }

    if(notSame)
    {
        return -1;
    }
    else
    {
        return actualVal[i];
    }
}

std::string getColorAsString(QColor color)
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
    else if(color == Qt::darkGreen)
        colorStr = globalColorString[3];   //other green
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

std::string getPenStyleAsString(Qt::PenStyle penStyle)
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

std::string getCapStyleAsString(Qt::PenCapStyle capStyle)
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

std::string getJoinStyleAsString(Qt::PenJoinStyle joinStyle)
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

std::string getBrushStyleAsString(Qt::BrushStyle brushStyle)
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

std::string getTextAlignmentAsString(Qt::AlignmentFlag align)
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

std::string getFontStyleAsString(QFont::Style style)
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

std::string getFontWeightAsString(QFont::Weight weight)
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


Qt::GlobalColor convertToGlobalColor(std::string thisString) {return Qt::GlobalColor(findStringCustom(globalColorString, colorsAr, COLORS, thisString));}

Qt::PenStyle convertToPenStyle(std::string thisString) {return Qt::PenStyle(findString(penStyleString, PEN_STYLES, thisString));}

Qt::PenCapStyle convertToPenCapStyle(std::string thisString) {return Qt::PenCapStyle(findString(penCapStyleString, CAP_STYLES, thisString));}

Qt::PenJoinStyle convertToPenJoinStyle(std::string thisString) {return Qt::PenJoinStyle(findString(penJoinStyleString, JOIN_STYLES, thisString));}

Qt::BrushStyle convertToBrushStyle(std::string thisString) {return Qt::BrushStyle(findStringCustom(brushStyleString, brushStylesAr, BRUSH_STYLES, thisString));}

Qt::AlignmentFlag convertToAlignmentFlag(std::string thisString) {return Qt::AlignmentFlag(findString(textAlignmentString, TEXT_ALIGNS, thisString));}

QFont::Style convertToQFontStyle(std::string thisString) {return QFont::Style(findString(textFontStyleString, FONT_STYLES, thisString));}

QFont::Weight convertToQFontWeight(std::string thisString) {return QFont::Weight(findStringCustom(textFontWeightString, textWeightsAr, FONT_WEIGHTS, thisString));}


