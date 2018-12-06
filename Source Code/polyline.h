/*!
 * \class Polyline
 * \brief  The class managing a polyline.
 */

#ifndef POLYLINE_H_
#define POLYLINE_H_

#include "shape.h"

//! Polyline Global Constant
/*! Placeholder - a polyline has a dynamic number of specifications. This value is never used.
 */
const int NUM_POLYLINE_SPECS = -1;

/*! Derived from abstract base class Shape.
 * Polylines can have an infinite number of points when written by hand into an input file.
 * When polylines are added via the application, they have a maximum of 10 points.
 */
class Polyline: public Shape
{
public:

    //! Default constructor
    Polyline() {}

    //! Alternate constructor
    /*! Passes in all polyline data to be implemented upon construction.
     * \sa MainWindow::on_polylineSave_clicked()
     * \param shapeId the ID number of the new polyline
     * \param shapeType the string representing a polyline
     * \param numDimensions the number of dimensions the new polyline has
     * \param *shapeDimensions the pointer to the array of polyline dimensions
     */
    Polyline(int shapeId, std::string shapeType, int numDimensions, dim::specs* shapeDimensions)
        :Shape(shapeId, shapeType, numDimensions, shapeDimensions) {setPosition();}

    //! Destructor
    /*! Overrides the virtual destructor of base class Shape
     */
    ~Polyline() override {}

    //! Draws the polyline according to stored specifications.
    /*! Overrides the pure virtual function from the base class to draw a polyline.
     */
    void draw() override;

    //! Moves the polyline by a certain offset along the x and y axes.
    /*! Overrides the pure virtual function from the base class to move a polyline.
     * \param shift the QPoint containing both x and y offsets from the original polyline location
     */
    void move (const QPoint &shift) override;

    //! Calculates the perimeter of the polyline.
    /*! Overrides the pure virtual function from the base class to calculate the perimeter of a polyline.
     */
    dim::perimeter calcPerimeter() const override;

    //! Overrides the pure virtual function from the base class to return 0.
    /*! \returns Zero (a polyline has no area).
     */
    dim::area calcArea() const override {return 0;}

    //! Updates the shape dimensions array with the current polyline dimensions.
    /*! This function is called whenever the polyline is moved to account for shifts in its dimensions.
     * Overrides the virtual function from the base class.
     * \param shift the QPoint containing both x and y offsets from the original polyline location
     * \sa Polyline::move()
     */
    void setShapeDimensions(const QPoint &shift) override;

    //! Sets the items in the vector of QPoints to the positions of the points on the polyline.
    /*! Overrides the pure virtual function from the base class to set the position of a polyline.
     */
    void setPosition() override;

    //! Prints the polyline specifications.
    /*! Stores the entire set of polyline specifications as a string to be printed to an output file via the AllShapes class.
     * Overrides the virtual function from the base class.
     * \sa AllShapes::printAll()
     */
    std::string print() const override;


private:
    std::vector<QPoint> points; /*!< the vector containing all points on the polyline */

};

#endif /*POLYLINE_H_*/
