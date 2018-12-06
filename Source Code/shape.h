/*!
 * \class Shape
 * \brief   The abstract base class managing a shape.
 * \brief   Line, Polyline, Polygon, Rectangle, Square, Ellipse, Circle, and Text are derived classes.
 * \brief   This class represents the abstract base class that serves as the parent for all eight Shape derived classes.
*/

#ifndef SHAPE_H_
#define SHAPE_H_

#include "libraries.h"
#include "custommath.h"

const int NUM_SHAPES = 8;           /*!< The total number of shapes represented in the application: Line, Polyline, Polygon, Rectangle, Square, Ellipse, Circle, Text */
const int NUM_STATIC_SHAPES = 6;    /*!< The total number of shapes without dynamic shape dimensions: Line, Rectangle, Square, Ellipse, Circle, Text */

const int MIN_TEXT_POINT = -1;      /*!< The minimum text point size */
const int MAX_TEXT_POINT = 50;      /*!< The maximum text point size */


/*! \namespace ShapeLabels
 * \brief Contains enumerations and arrays that represent locations in QPoints and in arrays of shape dimensions.
 */
namespace ShapeLabels
{
    //! The enumeration containing all shape types.
    /*! This enumeration is used when traversing the SHAPES_LIST string array.
     * This simplifies data gathering in the parser.
     * \sa Parser::parseShapes()
     */
    enum eShapes{
                LINE,       /*!< Represents a line string in the SHAPES_LIST string array. */
                POLYLINE,   /*!< Represents a polyline string in the SHAPES_LIST string array. */
                POLYGON,    /*!< Represents a polygon string in the SHAPES_LIST string array. */
                RECTANGLE,  /*!< Represents a rectangle string in the SHAPES_LIST string array. */
                SQUARE,     /*!< Represents a square string in the SHAPES_LIST string array. */
                ELLIPSE,    /*!< Represents a ellipse string in the SHAPES_LIST string array. */
                CIRCLE,     /*!< Represents a circle string in the SHAPES_LIST string array. */
                TEXT        /*!< Represents a text string in the SHAPES_LIST string array. */
                };

    //! The enumeration containing a universal set of X1 and Y1 points.
    /*! The points x1 and y1 are included in every shape and represent the top left corner of that shape or its bounding rectangle.
     * This simplifies the action of setting shape dimensions in the shapeDimensions array when a shape is moved.
     * \sa setShapeDimensions()
     */
    enum Dimensions{
                    X1, /*!< Represents the top left x coordinate of a shape. */
                    Y1  /*!< Represents the top left y coordinate of a shape. */
                   };

    //! The integer array representing the number of dimensions in shapes with a fixed number of dimensions.
    /*! This array applies to all shape types except for Polyline and Polygon, which have a dynamic number of dimensions.
     * There are 4 Line dimensions: X1, Y1, X2, Y2.
     * There are 4 Rectangle dimensions: X1, Y1, W, H.
     * There are 3 Square dimensions: X1, Y1, L.
     * There are 4 Ellipse dimensions: X1, Y1, A, B.
     * There are 3 Circle dimensions: X1, Y1, RADIUS.
     * There are 4 Text dimensions: X1, Y1, W, H.
     */
    const int NUM_SHAPE_DIMENSIONS[NUM_STATIC_SHAPES]
    {
        4,
        4,
        3,
        4,
        3,
        4
    };

    //! The string array representing all shape types.
    /*! This array is used in tandem with the eShapes enumeration to parse through the input file and interpret string literals as actual shape types.
     * \sa Parser::parseShapes()
     */
    const std::string SHAPES_LIST[NUM_SHAPES]
    {
        "Line",
        "Polyline",
        "Polygon",
        "Rectangle",
        "Square",
        "Ellipse",
        "Circle",
        "Text"
    };
}

/*! This class has five pure virtual functions: draw, move, calcPerimeter, calcArea, and setPosition.
 * These functions are overriden individually throughout all derived classes.
 */
class Shape
{
public:

    //! Default constructor
    /*! Sets the shape specifications to default values.
     * Creates a new dynamic array of shape dimensions based on the number of dimensions the relevant derived shape has.
     * \sa Parser::getShapePtr()
     */
    Shape(): shapeId{0}, shapeType{"Nullbody"}, numDimensions{0}, shapeDimensions{new dim::specs[numDimensions]}, text{"Nullbody"} {}

    //! Alternate constructor
    /*! Passes in all shape data to be implemented upon construction.
     * Initializes static shape data to passed in values via a base member initialization list.
     * Creates a dynamic array of shape dimensions and sets each value to the corresponding value from the passed in array.
     * \sa MainWindow::on_lineSave_clicked()
     * \sa MainWindow::on_polylineSave_clicked()
     * \sa MainWindow::on_polygonSave_clicked()
     * \sa MainWindow::on_rectangleSave_clicked()
     * \sa MainWindow::on_squareSave_clicked()
     * \sa MainWindow::on_ellipseSave_clicked()
     * \sa MainWindow::on_circleSave_clicked()
     * \sa MainWindow::on_textSave_clicked()
     * \param shapeId the ID number of the new ellipse
     * \param shapeType the string representing a shape type
     * \param numDimensions the number of dimensions the shape has
     * \param *shapeDimensions the pointer to the array of shape dimensions
     */
    Shape(int shapeId, std::string shapeType, int numDimensions, dim::specs* shapeDimensions);

    //! Removes functionality of a copy constructor.
    Shape(const Shape &otherShape) = delete;

    //! Removes functionality of a copy assignment operator.
    const Shape& operator=(const Shape &otherShape) = delete;

    //! Virtual destructor.
    /*! Marked virtual since the Shape class has virtual and pure virtual functions.
     * Deletes the pointer to the dynamic array of shape dimensions upon program termination.
     * All data that is elected to be saved is printed to the shape input file.
     */
    virtual ~Shape(){delete[] shapeDimensions;}

    //! Overloaded equality operator.
    /*! Used when comparing shape ID numbers.
     * \param shape the Shape object being compared to the invoking object
     * \sa idCompare(Shape* bestShape, Shape* currentShape)
     */
    bool operator==(const Shape& shape) const {return shapeId == shape.shapeId;}

    //! Overloaded less than operator.
    /*! Used when comparing shape ID numbers.
     * \param shape the Shape object being compared to the invoking object
     * \sa idCompare(Shape* bestShape, Shape* currentShape)
     */
    bool operator<(const Shape& shape) const {return shapeId < shape.shapeId;}

    //! Overloaded greater than operator.
    /*! Used when comparing shape ID numbers.
     * \param shape the Shape object being compared to the invoking object
     * \sa AllShapes::setCurrentID()
     */
    bool operator>(const Shape& shape) const {return shapeId > shape.shapeId;}

    //! Pure virtual function that draws a shape.
    /*! This function is overriden by all derived classes to draw specific shapes with specific dimensions, QPen, and QBrush settings.
     * \sa canvas::paintEvent();
     */
    virtual void draw() = 0;

    //! Pure virtual function that moves a shape.
    /*! This function is overriden by all derived classes to move specific shapes.
     * Moving is defined as shifting the top left corner by a certain amount of x and y to a new location.
     * If the user enters a negative number, the shape shifts left/down.
     * If the user enters a positive number, the shape shifts right/up.
     * \sa AllShapes::moveShape()
     */
    virtual void move(const QPoint &shift) = 0;

    //! Pure virtual function that finds the perimeter of a shape.
    /*! This function is overriden by all derived classes to find the perimeter of a specific shape.
     * Perimeter is interpreted as length by lines and polylines. Every shape will have a non-zero perimeter except for the text box.
     * \sa MainWindow::sortPerimeterTable()
     */
    virtual dim::perimeter calcPerimeter() const = 0;

    //! Pure virtual function that finds the area of a shape.
    /*! This function is overriden by all derived classes to find the area of a specific shape.
     * Every shape will have a non-zero area except for the line, polyline, and text shapes.
     * \sa MainWindow::sortAreaTable()
     */
    virtual dim::area calcArea() const = 0;

    //! Sets the QPoint data member(s) to the position of the shape.
    /*! This function is overriden by all derived classes to set the position of each shape in the rendering area.
     */
    virtual void setPosition() = 0;

    //! Sets the base shape information.
    /*! Used when populating the shape vector in the parser class.
     * Also used when editing a shape's values via the front end.
     * \sa AllShapes::editShape()
     * \sa Parser::parseShapes()
     * \param shapeId the shape's ID number
     * \param shapeType the string literal representing the type of shape being created
     * \param numDimensions the number of dimensions the currently selected shape has
     * \param otherDimensions the pointer to an array of dimensions being copied into this Shape object's array of dimensions
     */
    void setBaseInfo(int shapeId, std::string shapeType, int numDimensions, dim::specs* otherDimensions);

    //! Sets the QPen values.
    /*! Inline function: sets the pen color, width, style, cap style, and join style.
     * \param pen the populated QPen object
     */
    void setPen(const QPen &pen) {this -> pen = pen;}

    //! Sets the QBrush values.
    /*! Inline function: sets the brush color and style.
     * \param brush the populated QBrush object
     */
    void setBrush(const QBrush &brush) {this -> brush = brush;}

    //! Sets the shape ID.
    /*! Inline function: sets the ID of the current shape object.
     * \param id the new ID to be assigned to the shape
     */
    void setID(int id) {shapeId = id;}

    //! Sets an individual shape dimension.
    /*! Inline function: sets the specified dimension to the passed in value.
     * \param dimensionIndex the location of the specified dimension in the current shape object's dimension array
     * \param newDimension the new dimension to be assigned to the specified location
     */
    void setShapeDimension(int dimensionIndex, dim::specs newDimension) {shapeDimensions[dimensionIndex] = newDimension;}

    //! Gets the shape type of the current shape object.
    /*! Inline function: returns the string literal representing the current shape object's shape type.
     * \returns the current shape type
     */
    std::string getType() {return shapeType;}

    //! Gets the QBrush of the current shape object.
    /*! Inline function: returns the QBrush object representing the current shape object.
     * \returns the current QBrush object by reference
     * \sa MainWindow::setCurrentShapeInfo()
     */
    QBrush &getBrush() {return brush;}

    //! Gets the ID number of the current shape object.
    /*! Inline function: returns the ID number representing the current shape object.
     * Used to sort the vector, locate certain shapes, and populate the sorted shape tables in the front end of the application.
     * \returns the current ID number
     * \sa MainWindow
     * \sa AllShapes
     */
    int getID() const {return shapeId;}

    //! Gets the QPainter object representing the current shape object.
    /*! Inline function: returns the QPainter object representing the current shape object.
     * Allows Qt to draw the shape being rendered onto the promoted canvas widget.
     * \returns the current QPainter object by reference
     * \sa canvas::paintEvent()
     */
    QPainter &getPainter() {return painter;}

    //! Gets the QPen of the current shape object.
    /*! Inline function: returns the QPen object representing the current shape object.
     * \returns the current QPen object by reference
     * \sa MainWindow::setCurrentShapeInfo()
     */
    QPen &getPen() {return pen;}

    //! Gets the pointer to the array of shape dimensions for the current shape object.
    /*! Inline function: returns the pointer to the array of shape dimensions representing the current shape object.
     * \returns the pointer to the array of shape dimensions.
     * \sa MainWindow::setCurrentShapeInfo()
     */
    dim::specs* getDimensions() {return shapeDimensions;}

    //! Gets the number of dimensions the current shape object has.
    /*! Inline function: returns the size of the array of shape dimensions representing the current shape object.
     * \returns the size of the array of shape dimensions.
     * \sa MainWindow::setCurrentShapeInfo()
     */
    int getNumDimensions() {return numDimensions;}

    //! Virtual function that sets the shape dimensions to new values after the Shape object is moved.
    /*! This function resets the values in the shapeDimensions array for shapes when they are moved.
     * This function is overriden in the derived shape classes to account for their unique shape dimensions.
     * \param shift the amount by which a shape is shifted along the x and y axes
     */
    virtual void setShapeDimensions(const QPoint &shift);

    //! Virtual function that prints all shape properties as a single string.
    /*! This function prints all values stored in the shape as a single string in the format of the input file.
     * Overriden by Line, Polyline, and Text due to their differences in shape properties.
     * \sa AllShapes::printAll()
     */
    virtual std::string print() const;

    //! This function is specific to the derived class Text.
    //! Sets the actual text of the text box.
    /*! Inline function: sets the text of the text box with the passed in string.
     * \param newText the text to be visible in the Text object
     */
    void setText(const std::string newText) {text = newText;}

    //! This function is specific to the derived class Text.
    //! Sets the QFont values.
    /*! Inline function: sets the font family, style, and weight.
     * \param font the populated QFont object
     */
    void setFont(const QFont &font) {this -> font = font;}

    //! This function is specific to the derived class Text.
    //! Sets the alignment of the text in the text box.
    /*! Inline function: sets the alignment of the text in the text box.
     * \param flag the alignment setting for the text in the text box
     */
    void setAlignment(Qt::AlignmentFlag flag) {alignFlag = flag;}

    //! This function is specific to the derived class Text.
    //! Gets the text of the current Text object.
    /*! Inline function: returns the text that is visible for the Text object.
     * \returns the current text as a string
     * \sa MainWindow::setCurrentShapeInfo()
     */
    std::string getText() {return text;}

    //! This function is specific to the derived class Text.
    //! Gets the QFont of the current shape object.
    /*! Inline function: returns the QFont object representing the Text object.
     * \returns the current QFont object by reference
     * \sa MainWindow::setCurrentShapeInfo()
     */
    QFont &getFont() {return font;}

    //! This function is specific to the derived class Text.
    //! Gets the QFont of the current shape object.
    /*! Inline function: returns the QFont object representing the Text object.
     * \returns the current QFont object by reference
     * \sa MainWindow::setCurrentShapeInfo()
     */
    Qt::AlignmentFlag getFlag() {return alignFlag;}


protected:
    int shapeId;                    /*!< the ID number representing the shape object */
    std::string shapeType;          /*!< the string representing the shape type */
    int numDimensions;              /*!< the number of dimensions the shape object has */
    dim::specs* shapeDimensions;    /*!< the pointer to the dynamic array of shape dimensions */

    QPainter painter;   /*!< the QPainter object holding QPen and QBrush properties */
    QPen pen;           /*!< the QPen object holding pen properties */
    QBrush brush;       /*!< the QBrush object holding brush properties */

    QFont font;                     /*!< the QFont object holding font properties */
    std::string text;               /*!< the string of text displayed by the Text object */
    Qt::AlignmentFlag alignFlag;    /*!< the alignment setting of the text displayed by the Text object */

};

#endif /*SHAPE_H_*/
