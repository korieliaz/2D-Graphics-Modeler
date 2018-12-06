/*!
 * \class Rectangle
 * \brief   The class managing a rectangle.
*/

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "shape.h"

//! Rectangle Global Constant
/*! The number of dimensions a rectangle has
 * X1, Y1, W (width), H (height)
 */
const int NUM_RECTANGLE_SPECS = 4;

/*! Derived from abstract base class Shape.
 */
class Rectangle: public Shape
{
public:

    //! Default constructor
    /*! Sets the position of the top left of the rectangle to a default location
     */
    Rectangle() : position{0,0} {}

    //! Alternate constructor
    /*! Passes in all rectangle data to be implemented upon construction.
     * Initializes the rectangle and base class data via a base member initialization list.
     * Sets the QPoint value of the top left of the rectangle
     * \sa MainWindow::on_rectangleSave_clicked()
     * \sa Rectangle::setPosition()
     * \param shapeId the ID number of the new rectangle
     * \param shapeType the string representing a rectangle
     * \param numDimensions the number of dimensions a rectangle has
     * \param *shapeDimensions the pointer to the array of rectangle dimensions
     */
    Rectangle(int shapeId, std::string shapeType, int numDimensions, dim::specs* shapeDimensions)
          :Shape(shapeId, shapeType, numDimensions, shapeDimensions)
          {setPosition();}

    //! Destructor
    /*! Overrides the virtual destructor of base class Shape
     */
    ~Rectangle() override {}

    //! Draws the rectangle according to stored specifications.
    /*! Overrides the pure virtual function from the base class to draw a rectangle.
     */
    void draw() override;

    //! Moves the rectangle by a certain offset along the x and y axes.
    /*! Overrides the pure virtual function from the base class to move a rectangle.
     * \param shift the QPoint containing both x and y offsets from the original rectangle location
     */
    void move(const QPoint &shift) override;

    //! Calculates the perimeter of the rectangle.
    /*! Overrides the pure virtual function from the base class to calculate the perimeter of a rectangle.
     * Inline function: Adds all four sides together.
     * \sa multiply(T A, U B)
     */
    dim::perimeter calcPerimeter() const override {return multiply(*(shapeDimensions + int(Specifications::W)), 2.0) +
                                                multiply(*(shapeDimensions + int(Specifications::H)), 2.0);}

    //! Calculates the area of the rectangle.
    /*! Overrides the pure virtual function from the base class to calculate the area of a rectangle.
     * Inline function: Multiplies the width and the height together.
     * \sa multiply(T A, U B)
     */
    dim::area calcArea() const override {return multiply(*(shapeDimensions + int(Specifications::W)),
                                                    *(shapeDimensions + int(Specifications::H)));}

    //! Sets the QPoint data member to the position of the top left corner of the rectangle.
    /*! Overrides the pure virtual function from the base class to set the position of a rectangle.
     */
    void setPosition() override;


private:
    QPoint position;    /*!< the position of the top left corner of the rectangle */

public:
    //! The enumeration representing the meaning of each slot in the array of rectangle dimensions.
    enum class Specifications{
                                X1, /*!< the x coordinate of the top left corner */
                                Y1, /*!< the y coordinate of the top left corner */
                                W,  /*!< the width of the rectangle (length along x axis) */
                                H   /*!< the height of the rectangle (length along y axis) */
                             };
};

#endif /*RECTANGLE_H_*/
