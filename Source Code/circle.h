/*!
 * \class   Circle
 * \brief   The class managing a circle.
*/


#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <QPaintDevice>
#include <QPoint>
#include "shape.h"

//! Circle Global Constant
/*! The number of dimensions a circle has
 * X1, Y1, Radius
 */
const int NUM_CIRCLE_SPECS = 3;

/*! Derived from abstract base class Shape.
 */
class Circle: public Shape
{
public:

    //! Default constructor
    /*! Sets the position of the top left of the circle to a default location
     */
    Circle() : position{0,0} {}

    //! Alternate constructor
    /*! Passes in all circle data to be implemented upon construction.
     * Initializes the circle and base class data via a base member initialization list.
     * Sets the QPoint value of the top left of the circle
     * \sa MainWindow::on_circleSave_clicked()
     * \sa Circle::setPosition()
     * \param shapeId the ID number of the new circle
     * \param shapeType the string representing a circle
     * \param numDimensions the number of dimensions a circle has
     * \param *shapeDimensions the pointer to the array of circle dimensions
     */
    Circle(int shapeId, std::string shapeType, int numDimensions, dim::specs* shapeDimensions)
          :Shape(shapeId, shapeType, numDimensions, shapeDimensions)
          {setPosition();}

    //! Destructor
    /*! Overrides the virtual destructor of base class Shape
     */
    ~Circle() override {}

    //! Draws the circle according to stored specifications.
    /*! Overrides the pure virtual function from the base class to draw a circle.
     */
    void draw() override;

    //! Moves the circle by a certain offset along the x and y axes.
    /*! Overrides the pure virtual function from the base class to move a circle.
     * \param shift the QPoint containing both x and y offsets from the original circle location
     */
    void move(const QPoint &shift) override;

    //! Calculates the perimeter of the circle.
    /*! Overrides the pure virtual function from the base class to calculate the perimeter of a circle.
     */
    dim::perimeter calcPerimeter() const override;

    //! Calculates the area of the circle.
    /*! Overrides the pure virtual function from the base class to calculate the area of a circle.
     */
    dim::area calcArea() const override;

    //! Sets the QPoint data member to the position of the top left corner of the circle.
    /*! Overrides the pure virtual function from the base class to set the position of a circle.
     */
    void setPosition() override;

private:
    QPoint position; /*!< the position of the top left corner of the circle */

public:
    //! The enumeration representing the meaning of each slot in the array of circle dimensions.
    enum class Specifications{
                                X1,     /*!< the x coordinate of the top left corner */
                                Y1,     /*!< the y coordinate of the top left corner */
                                RADIUS  /*!< the radius of the circle */
                             };
};

#endif /*CIRCLE_H_*/
