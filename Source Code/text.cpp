#include "text.h"
#include <sstream>
#include <qtconversions.h>

//! Sets the QPainter object to draw a text box according to the Text object's specifications.
void Text::draw()
{
    painter.setPen(pen);
    painter.setFont(font);
    painter.drawText(position.x(), position.y(), shapeDimensions[int(Specifications::W)], shapeDimensions[int(Specifications::H)], alignFlag, QString::fromStdString(text));
    painter.setPen(Qt::black);

    QFont font;
    font.setPointSize(8);
    painter.setPen(QFont::Style::StyleNormal);
    painter.setFont(font);
    painter.drawText(position.x() + shapeDimensions[int(Specifications::W)]/2, position.y() + shapeDimensions[int(Specifications::H)], 20, 20, Qt::AlignLeft, QString::number(shapeId));
}

//! Shifts the position of the text box.
void Text::move(const QPoint &shift)
{
    position += shift;
    setShapeDimensions(shift);
}

//! Sets the position of the text box.
void Text::setPosition()
{
    position = {shapeDimensions[int(Specifications::X1)], shapeDimensions[int(Specifications::Y1)]};
}

//! Overrides the default print function for text specific information.
std::string Text::print() const
{
    using std::endl;
    std::ostringstream oss;

    oss << "ShapeId: " << shapeId << endl;
    oss << "ShapeType: " << shapeType << endl;
    oss << "ShapeDimensions: ";
    for(int i = 0; i < numDimensions; ++i)
    {
         oss << shapeDimensions[i];

         if(i < numDimensions - 1)
         {
             oss << ", ";
         }
    }
    oss << endl;
    oss << "TextString: " << text << endl;
    oss << "TextColor: " << getColorAsString(pen.color()) << endl;
    oss << "TextAlignment: " << getTextAlignmentAsString(alignFlag) << endl;
    oss << "TextPointSize: " << font.pointSize() << endl;
    oss << "TextFontFamily: " << (font.family()).toStdString() << endl;
    oss << "TextFontStyle: " << getFontStyleAsString(font.style()) << endl;
    oss << "TextFontWeight: " << getFontWeightAsString(QFont::Weight(font.weight())) << endl;

    return oss.str();
}
