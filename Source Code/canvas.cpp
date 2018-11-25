#include "canvas.h"

canvas::canvas(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(1000, 500);
    setMaximumSize(1000, 500);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

void canvas::getShapes(myVector::vector<Shape*> shapes)
{
    v_Shapes = shapes;
    update();
}

void canvas::paintEvent(QPaintEvent * /*event*/)
{
    for(myVector::vector<Shape*>::iterator it = v_Shapes.begin(); it != v_Shapes.end(); ++it)
    {
        (*it) -> getPainter().begin(this);
        (*it) -> getPainter().setRenderHint(QPainter::Antialiasing, true);
        (*it) -> getPainter().save();
        (*it) -> draw();
        (*it) -> getPainter().restore();
        (*it) -> getPainter().end();
    }
}
