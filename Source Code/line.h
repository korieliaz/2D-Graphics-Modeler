/*!
 * \brief   Line Header File - Team Mittens USA
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

#ifndef LINE_H_
#define LINE_H_

#include <QPaintDevice>
#include <QPen>
#include <QPoint>
#include "shape.h"

//! Line Global Constant
/*! The number of dimensions a line has
 * X1, Y1, X2, Y2
 */
const int NUM_LINE_SPECS = 4;

//! The class managing a line.
/*! Derived from abstract base class Shape.
 */
class Line: public Shape
{
public:

    //! Default constructor
    /*! Sets both points of the line to a default location
     */
    Line() : point1{0,0}, point2{0,0} {}

    //! Alternate constructor
    /*! Passes in all line data to be implemented upon construction.
     * Initializes the line and base class data via a base member initialization list.
     * Sets the QPoint values of the two points on the line.
     * \sa MainWindow::on_lineSave_clicked()
     * \sa Line::setPosition()
     * \param shapeId the ID number of the new line
     * \param shapeType the string representing a line
     * \param numDimensions the number of dimensions a line has
     * \param *shapeDimensions the pointer to the array of line dimensions
     */
    Line(int shapeId, std::string shapeType, int numDimensions, dim::specs* shapeDimensions)
          :Shape(shapeId, shapeType, numDimensions, shapeDimensions)
          {setPosition();}

    //! Destructor
    /*! Overrides the virtual destructor of base class Shape
     */
    ~Line() override {}

    //! Draws the line according to stored specifications.
    /*! Overrides the pure virtual function from the base class to draw a line.
     */
    void draw() override;

    //! Moves the line by a certain offset along the x and y axes.
    /*! Overrides the pure virtual function from the base class to move a line.
     * \param shift the QPoint containing both x and y offsets from the original line location
     */
    void move(const QPoint &shift) override;

    //! Calculates the length of the line.
    /*! Overrides the pure virtual function from the base class to calculate the length of a line.
     */
    dim::perimeter calcPerimeter() const override;

    //! Overrides the pure virtual function from the base class to return 0.
    /*! \returns Zero (a line has no area).
     */
    dim::area calcArea() const override {return 0;}

    //! Updates the shape dimensions array with the current line dimensions.
    /*! This function is called whenever the line is moved to account for shifts in its dimensions.
     * Overrides the virtual function from the base class.
     * \param shift the QPoint containing both x and y offsets from the original line location
     * \sa Line::move()
     */
    void setShapeDimensions(const QPoint &shift) override;

    //! Sets the QPoint data members to the positions of the two points on the line.
    /*! Overrides the pure virtual function from the base class to set the position of a line.
     */
    void setPosition() override;

    //! Prints the line specifications.
    /*! Stores the entire set of line specifications as a string to be printed to an output file via the AllShapes class.
     * Overrides the virtual function from the base class.
     * \sa AllShapes::printAll()
     */
    std::string print() const override;

private:
    QPoint point1;  /*!< the position of the first point in the line */
    QPoint point2;  /*!< the position of the second point in the line */

public:
    //! The enumeration representing the meaning of each slot in the array of line dimensions.
    enum class Specifications{
                                X1, /*!< the x coordinate of the first point */
                                Y1, /*!< the y coordinate of the first point */
                                X2, /*!< the x coordinate of the second point */
                                Y2  /*!< the y coordinate of the second point */
                             };
};

#endif /*LINE_H_*/




