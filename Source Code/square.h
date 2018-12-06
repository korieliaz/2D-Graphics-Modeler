/*!
 * \class Square
 * \brief   The class managing a square.
*/

#ifndef SQUARE_H_
#define SQUARE_H_

#include "shape.h"

//! Square Global Constant
/*! The number of dimensions a square has
 * X1, Y1, Length of a side (L)
 */
const int NUM_SQUARE_SPECS = 3;

/*! Derived from abstract base class Shape.
 */
class Square: public Shape
{
public:
    //! Default constructor
    /*! Sets the position of the top left of the square to a default location
     */
    Square() : position{0,0} {}

    //! Alternate constructor
    /*! Passes in all square data to be implemented upon construction.
     * Initializes the square and base class data via a base member initialization list.
     * Sets the QPoint value of the top left of the square
     * \sa MainWindow::on_squareSave_clicked()
     * \sa Square::setPosition()
     * \param shapeId the ID number of the new square
     * \param shapeType the string representing a square
     * \param numDimensions the number of dimensions a square has
     * \param *shapeDimensions the pointer to the array of square dimensions
     */
    Square(int shapeId, std::string shapeType, int numDimensions, dim::specs* shapeDimensions)
          :Shape(shapeId, shapeType, numDimensions, shapeDimensions)
          {setPosition();}

    //! Destructor
    /*! Overrides the virtual destructor of base class Shape
     */
    ~Square() override {}

    //! Draws the square according to stored specifications.
    /*! Overrides the pure virtual function from the base class to draw a square.
     */
    void draw() override;

    //! Moves the square by a certain offset along the x and y axes.
    /*! Overrides the pure virtual function from the base class to move a square.
     * \param shift the QPoint containing both x and y offsets from the original square location
     */
    void move(const QPoint &shift) override;

    //! Calculates the perimeter of the square.
    /*! Overrides the pure virtual function from the base class to calculate the perimeter of a square.
     * Inline function: multiplies the length of a side by 4 since all four sides of a square are equivalent.
     */
    dim::perimeter calcPerimeter() const override {return multiply(*(shapeDimensions + int(Specifications::L)), 4.0);}

    //! Calculates the area of the square.
    /*! Overrides the pure virtual function from the base class to calculate the area of a square.
     * Inline function: squares the length of a side since all four sides of a square are equivalent.
     */
    dim::area calcArea() const override {return multiply(*(shapeDimensions + int(Specifications::L)),
                                                         *(shapeDimensions + int(Specifications::L)));}

    //! Sets the QPoint data member to the position of the top left corner of the square.
    /*! Overrides the pure virtual function from the base class to set the position of a square.
     */
    void setPosition() override;


private:
    QPoint position;    /*!< the position of the top left corner of the square */

public:
    //! The enumeration representing the meaning of each slot in the array of square dimensions.
    enum class Specifications{
                                X1, /*!< the x coordinate of the top left corner */
                                Y1, /*!< the y coordinate of the top right corner */
                                L   /*!< the length of a side */
                             };
};

#endif /*SQUARE_H_*/
