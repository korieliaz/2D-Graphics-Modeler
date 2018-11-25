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

void canvas::getShape(Shape* currentShape)
{
    currentShape -> draw();
    update();
}

void canvas::setPainter(QPainter &painter, std::string shapeType)
{

}

void canvas::paintEvent(QPaintEvent * /*event*/)
{
//    QPainter painter(this);
//    painter.setPen(Qt::green);
//    painter.setBrush(Qt::blue);
//    painter.drawRect(200, 200, 100, 100);

    for(myVector::vector<Shape*>::iterator it = v_Shapes.begin(); it != v_Shapes.end(); ++it)
    {
        (*it) -> getPainter().begin(this);
        (*it) -> getPainter().setRenderHint(QPainter::Antialiasing, true);
        (*it) -> getPainter().save();
        (*it) -> draw();
        (*it) -> getPainter().restore();
        (*it) -> getPainter().end();
    }

//    QPainter localPainter(this);
//    localPainter.setPen(palette().dark().color());
//    localPainter.setBrush(Qt::NoBrush);
//    localPainter.drawRect(QRect(0, 0, width() - 1, height() - 1));
}
