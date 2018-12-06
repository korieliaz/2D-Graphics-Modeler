/*!
 *  \class  Ellipse
 *  \brief  The class managing an ellipse.
*/

#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#include "shape.h"

//! Ellipse Global Constant
/*! The number of dimensions an ellipse has
 * X1, Y1, Semi-major axis (A), Semi-minor axis (B)
 */
const int NUM_ELLIPSE_SPECS = 4;

/*! Derived from abstract base class Shape.
 */
class Ellipse: public Shape
{
public:

    //! Default constructor
    /*! Sets the position of the top left of the ellipse to a default location
     */
    Ellipse() : position{0,0} {}

    //! Alternate constructor
    /*! Passes in all ellipse data to be implemented upon construction.
     * Initializes the ellipse and base class data via a base member initialization list.
     * Sets the QPoint value of the top left of the ellipse
     * \sa MainWindow::on_ellipseSave_clicked()
     * \sa Ellipse::setPosition()
     * \param shapeId the ID number of the new ellipse
     * \param shapeType the string representing a ellipse
     * \param numDimensions the number of dimensions an ellipse has
     * \param *shapeDimensions the pointer to the array of ellipse dimensions
     */
    Ellipse(int shapeId, std::string shapeType, int numDimensions, dim::specs* shapeDimensions)
          :Shape(shapeId, shapeType, numDimensions, shapeDimensions)
          {setPosition();}

    //! Destructor
    /*! Overrides the virtual destructor of base class Shape
     */
    ~Ellipse() override{}

    //! Draws the ellipse according to stored specifications.
    /*! Overrides the pure virtual function from the base class to draw an ellipse.
     */
    void draw() override;

    //! Moves the ellipse by a certain offset along the x and y axes.
    /*! Overrides the pure virtual function from the base class to move an ellipse.
     * \param shift the QPoint containing both x and y offsets from the original ellipse location
     */
    void move(const QPoint &shift) override;

    //! Calculates the perimeter of the ellipse.
    /*! Overrides the pure virtual function from the base class to calculate the perimeter of an ellipse.
     */
    dim::perimeter calcPerimeter() const override;

    //! Calculates the area of the ellipse.
    /*! Overrides the pure virtual function from the base class to calculate the area of an ellipse.
     */
    dim::area calcArea() const override;

    //! Sets the QPoint data member to the position of the top left corner of the ellipse.
    /*! Overrides the pure virtual function from the base class to set the position of an ellipse.
     */
    void setPosition() override;

private:
    QPoint position; /*!< the position of the top left corner of the ellipse */

public:
    //! The enumeration representing the meaning of each slot in the array of ellipse dimensions.
    enum class Specifications{
                                X1, /*!< the x coordinate of the top left corner */
                                Y1, /*!< the y coordinate of the top left corner */
                                A,  /*!< the semi-major axis of the ellipse */
                                B   /*!< the semi-minor axis of the ellipse */
                             };
};

#endif /*ELLIPSE_H_*/


