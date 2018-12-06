/*!
 * \class Polygon
 * \brief   The class managing a polygon.
*/

#ifndef POLYGON_H_
#define POLYGON_H_

#include <QPaintDevice>
#include <QPoint>
#include "shape.h"

//! Polygon Global Constant
/*! Placeholder - a polygon has a dynamic number of specifications. This value is never used.
 */
const int NUM_POLYGON_SPECS = -1;

/*! Derived from abstract base class Shape.
 * Polygons can have an infinite number of sides when written by hand into an input file.
 * When polygons are added via the application, they have a maximum of 10 sides.
 */
class Polygon: public Shape
{
public:

    //! Default constructor
    Polygon() {}

    //! Alternate constructor
    /*! Passes in all polygon data to be implemented upon construction.
     * \sa MainWindow::on_polygonSave_clicked()
     * \param shapeId the ID number of the new polygon
     * \param shapeType the string representing a polygon
     * \param numDimensions the number of dimensions the new polygon has
     * \param *shapeDimensions the pointer to the array of polygon dimensions
     */
    Polygon(int shapeId, std::string shapeType, int numDimensions, dim::specs* shapeDimensions)
        :Shape(shapeId, shapeType, numDimensions, shapeDimensions) {setPosition();}

    //! Destructor
    /*! Overrides the virtual destructor of base class Shape
     */
    ~Polygon() override {}

    //! Draws the polygon according to stored specifications.
    /*! Overrides the pure virtual function from the base class to draw a polygon.
     */
    void draw() override;

    //! Moves the polygon by a certain offset along the x and y axes.
    /*! Overrides the pure virtual function from the base class to move a polygon.
     * \param shift the QPoint containing both x and y offsets from the original polygon location
     */
    void move(const QPoint &shift) override;

    //! Calculates the perimeter of the polygon.
    /*! Overrides the pure virtual function from the base class to calculate the perimeter of a polygon.
     */
    dim::perimeter calcPerimeter() const override;

    //! Calculates the area of the polygon.
    /*! Overrides the pure virtual function from the base class to calculate the area of a polygon.
     */
    dim::area calcArea() const override;

    //! Updates the shape dimensions array with the current polygon dimensions.
    /*! This function is called whenever the polygon is moved to account for shifts in its dimensions.
     * Overrides the virtual function from the base class.
     * \param shift the QPoint containing both x and y offsets from the original polygon location
     * \sa Polygon::move()
     */
    void setShapeDimensions(const QPoint &shift) override;

    //! Sets the QPoint vector's values to the positions of all points on the polygon.
    /*! Overrides the pure virtual function from the base class to set the position of a polygon.
     */
    void setPosition() override;


private:
    std::vector<QPoint> points; /*!< the vector containing all points on the polygon */

};















#endif /*POLYGON_H_*/
