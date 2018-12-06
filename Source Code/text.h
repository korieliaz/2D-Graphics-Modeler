/*!
 * \class Text
 * \brief  The class managing a text box.
*/

#ifndef TEXT_H_
#define TEXT_H_

#include <QPaintDevice>
#include <QPoint>
#include <QString>
#include "shape.h"

//! Text Global Constant
/*! The number of dimensions a text box has
 * X1, Y1, Width (W), Height (H)
 */
const int NUM_TEXT_SPECS = 4;

/*! Derived from abstract base class Shape.
 */
class Text: public Shape
{
public:

    //! Default constructor
    /*! Sets the position of the top left of the text box to a default location
     */
    Text() : position{0,0}{}

    //! Alternate constructor
    /*! Passes in all text data to be implemented upon construction.
     * Initializes the text and base class data via a base member initialization list.
     * Sets the QPoint value of the top left of the text box
     * \sa MainWindow::on_textSave_clicked()
     * \sa Text::setPosition()
     * \param shapeId the ID number of the new text box
     * \param shapeType the string representing a text box
     * \param numDimensions the number of dimensions a text box has
     * \param *shapeDimensions the pointer to the array of text box dimensions
     * \param newFont the initialized QFont object
     * \param newText the text to be displayed in the text box
     * \param newFlag the alignment of the text in the text box
     */
    Text(int shapeId, std::string shapeType, int numDimensions, dim::specs* shapeDimensions, QFont newFont, std::string newText, Qt::AlignmentFlag newFlag)
          :Shape(shapeId, shapeType, numDimensions, shapeDimensions)
          {setPosition(); setAlignment(newFlag); setFont(newFont); setText(newText);}

    //! Destructor
    /*! Overrides the virtual destructor of base class Shape
     */
    ~Text() override {}

    //! Draws the text box according to stored specifications.
    /*! Overrides the pure virtual function from the base class to draw a text box.
     */
    void draw() override;

    //! Moves the text box by a certain offset along the x and y axes.
    /*! Overrides the pure virtual function from the base class to move a text box.
     * \param shift the QPoint containing both x and y offsets from the original text box location
     */
    void move(const QPoint &shift) override;

    //! Sets the perimeter of the text box to 0.
    /*! Overrides the pure virtual function from the base class to set the perimeter of a text box.
     */
    dim::perimeter calcPerimeter() const override {return 0;}

    //! Sets the area of the text box to 0.
    /*! Overrides the pure virtual function from the base class to set the area of a text box.
     */
    dim::area calcArea() const override {return 0;}

    //! Sets the QPoint data member to the position of the top left corner of the text box.
    /*! Overrides the pure virtual function from the base class to set the position of a text box.
     */
    void setPosition() override;

    //! Prints the text box specifications.
    /*! Stores the entire set of text box specifications as a string to be printed to an output file via the AllShapes class.
     * Overrides the virtual function from the base class.
     * \sa AllShapes::printAll()
     */
    std::string print() const override;


private:
    QPoint position;    /*!< the position of the top left corner of the text box */

public:
    //! The enumeration representing the meaning of each slot in the array of text dimensions.
    enum class Specifications{
                                X1, /*!< the x coordinate of the top left corner */
                                Y1, /*!< the y coordinate of the top left corner */
                                W,  /*!< the width of the textbox (length across the x axis) */
                                H   /*!< the height of the textbox (length across the y axis) */
                             };
};

#endif /*TEXT_H_*/
//    std::string textString;
