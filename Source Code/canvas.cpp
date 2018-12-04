/*!
 * \brief   Canvas CPP File - Team Mittens USA
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
#include "canvas.h"

//! Constructor
/*! Sets the canvas's pointer.
 * Sets minimum and maximum canvas sizes.
 * Sets the color of the canvas to white. */
canvas::canvas(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(1000, 500);
    setMaximumSize(1000, 500);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

//! Gets the shape vector and assigns it to the local shape vector.
void canvas::getShapes(myVector::vector<Shape*> shapes)
{
    v_Shapes = shapes;
    update();
}

//! Renders all shapes to the canvas.
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
