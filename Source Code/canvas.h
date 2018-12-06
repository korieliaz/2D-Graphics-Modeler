/*!
 * \class   canvas
 * \brief   The class managing the canvas/rendering area.
*/

#ifndef CANVAS_H
#define CANVAS_H

#include <QPen>
#include <QWidget>
#include "vector.h"
#include "shape.h"

/*! The rendering area widget is promoted to class canvas; this is allowed since canvas is inherited from QWidget.
 * This promotion allows shapes to be rendered on the canvas using member functions located here.
 */
class canvas : public QWidget
{
public:

    //! Constructor
    /*! \param parent the QWidget pointer, default initialized to null
     */
    explicit canvas(QWidget *parent = nullptr);

    //! Gets shapes from the shape vector
    /*! Allows for shape information to be rendered to the canvas.
     * \param shapes the shape vector
     */
    void getShapes(myVector::vector<Shape*> shapes);

protected:

    //! Overrides Qt's default paint event to allow for shape rendering.
    /*! Every time something is changed in the front end, the rendering area will reflect the implementation in this function.
     * \param event the pointer to the current QPaintEvent
     */
    void paintEvent(QPaintEvent *event) override;

private:
    myVector::vector<Shape *> v_Shapes; /*!< the custom vector of shapes */
};


#endif // CANVAS_H
