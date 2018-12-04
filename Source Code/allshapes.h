/*!
 * \brief   AllShapes Header File - Team Mittens USA
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

#ifndef ALLSHAPES_H_
#define ALLSHAPES_H_

#include "libraries.h"
#include "shape_list.h"
#include "parser.h"

//! A controller class that manages the shape vector, parser, and the add, edit, and delete functions.
/*! An object of the Parser class is implemented and used in this class via composition.
 * This allows the AllShapes class to navigate the text file containing all shape properties and fill the shapes vector.
 * An object of this class is implemented and used in the MainWindow class via composition.
 * This allows the front end to access and indirectly manipulate the shape vector when adding, editing, or deleting shapes.
 * \sa MainWindow::MainWindow()
*/
class AllShapes
{
    public:

        //! Default constructor
        /*! \param device the pointer to a QPaintDevice that allows Qt to render shapes
         * Also initializes shapeCount, currentId, and the device to their appropriate values.
        */
        AllShapes(QPaintDevice *device) : shapeCount{0}, currentID{0}, device{device} {}

        //! Destructor
        ~AllShapes(){}

        //! Adds shapes from a text file using the composed shapeParser object.
        /*! Reads in shape values from the shapes file and populates the vector of shape pointers.
         * \sa Parser::parseShapes()
        */
        void addShapesFromFile();

        //! Sets the current max ID number from the largest shape ID currently in the vector.
        /*! Ensures each shape will have its own unique ID number.
        */
        void setCurrentID();

        //! Adds a new shape to the shape vector.
        /*! \param newShape the pointer to the new Shape object
         * Used when the user creates a new shape via the front end.
         * \sa MainWindow::on_lineSave_clicked()
         * \sa MainWindow::on_polylineSave_clicked()
         * \sa MainWindow::on_polygonSave_clicked()
         * \sa MainWindow::on_rectangleSave_clicked()
         * \sa MainWindow::on_squareSave_clicked()
         * \sa MainWindow::on_ellipseSave_clicked()
         * \sa MainWindow::on_circleSave_clicked()
         * \sa MainWindow::on_textSave_clicked()
        */
        void newShape(Shape *newShape);

        //! (1 of 3) Edits a shape in the shape vector.
        /*! Overloaded function (1 of 3) - edits a shape without a QBrush or QFont element
         * Shapes using this version of the function: Line, Polyline
         * \param id the ID number of the shape being edited
         * \param NUM_SPECS the number of specifications the shape being edited has
         * \param *dims the array of shape dimensions
         * \param pen the QPen settings of the edited shape
         * \sa MainWindow::on_editLineSave_clicked()
         * \sa MainWindow::on_editPolylineSave_clicked()
        */
        void editShape(int id, const int NUM_SPECS, dim::specs *dims, const QPen &pen);

        //! (2 of 3) Edits a shape in the shape vector.
        /*! Overloaded function (2 of 3) - edits a shape with a QBrush element
         * Shapes using this version of the function: Polygon, Rectangle, Square, Ellipse, Circle
         * \param id the ID number of the shape being edited
         * \param NUM_SPECS the number of specifications the shape being edited has
         * \param *dims the array of shape dimensions
         * \param pen the QPen settings of the edited shape
         * \param brush the QBrush settings of the edited shape
         * \sa MainWindow::on_editPolygonSave_clicked()
         * \sa MainWindow::on_editRectangleSave_clicked()
         * \sa MainWindow::on_editSquareSave_clicked()
         * \sa MainWindow::on_editEllipseSave_clicked()
         * \sa MainWindow::on_editCircleSave_clicked()
        */
        void editShape(int id, const int NUM_SPECS, dim::specs *dims, const QPen &pen, const QBrush &brush);

        //! (3 of 3) Edits a shape in the shape vector.
        /*! Overloaded function (3 of 3) - edits a shape with a QFont element
         * Shapes using this version of the function: Text
         * \param id the ID number of the shape being edited
         * \param NUM_SPECS the number of specifications the shape being edited has
         * \param *dims the array of shape dimensions
         * \param pen the QPen settings of the edited shape
         * \param font the QFont settings of the edited shape
         * \param flag the alignment setting of the edited shape
         * \param text the actual string displayed in the rendering area
         * \sa MainWindow::on_editTextSave_clicked()
        */
        void editShape(int id, const int NUM_SPECS, dim::specs *dims, const QPen &pen, const QFont &font, Qt::AlignmentFlag flag, string text);

        //! Moves a shape in the shape vector.
        /*! Moves a shape by shifting its x and y coordinates.
         * All shapes have this functionality.
         * \param id the ID number of the shape being moved
         * \param shift the QPoint containing the x and y shifts for the current shape
         * \sa MainWindow::on_moveUpdateButton_clicked()
        */
        void moveShape(int id, const QPoint &shift);

        //! Finds a shape in the shape vector and returns its shape type as a string.
        /*! \param id the ID number of the shape being located
         * \returns The shape type as a string.
        */
        string findShape(int id);

        //! Finds a shape in the shape vector and returns a pointer to its location.
        /*! \param id the ID number of the shape being located
         * \returns A pointer to the located shape.
        */
        Shape* findShapePtr(int id);

        //! Gets the current size of the shape vector.
        /*! \returns The size of the shape vector.
        */
        int getShapeCount() {return v_Shapes.size();}

        //! Gets the entire shape vector and returns it by reference.
        /*! \returns The entire shape vector by reference.
        */
        myVector::vector<Shape*>& getVector() {return v_Shapes;}

        //! Increments the current shape count and the current greatest ID number.
        /*! Used when adding a new shape to the vector. Makes sure no two shapes will have the same ID.
         * \returns The incremented current greatest ID number, to be assigned to a new shape.
        */
        int incrementShapeCount() {++shapeCount; return ++currentID;}

        //! Deletes a shape from the shape vector.
        /*! \param id the ID number of the shape being deleted
         * \sa MainWindow::on_deleteShapeButton_clicked()
        */
        void deleteShape(int id);

        //! Prints all data from the shape vector to the shapes database.
        void printAll();

private:
        myVector::vector<Shape*> v_Shapes;  /*!< The custom vector of Shape pointers. */
        Parser shapeParser;                 /*!< COMPOSITION - Object of class Parser used to parse the shapes file. */
        int shapeCount;                     /*!< The current number of shapes in the vector. */
        int currentID;                      /*!< The current largest ID number in the vector. */
        QPaintDevice *device;               /*!< The pointer to a QPaintDevice that allows rendering of shapes. */
};

#endif /*ALLSHAPES_H_*/
