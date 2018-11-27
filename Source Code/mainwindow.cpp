/****************************************************************
 * 2-D GRAPHICS MODELER
 * ==============================================================
 * Models custom shapes according to user specifications
 * --------------------------------------------------------------
 * Functions:
 *  Add     - Add new shape
 *  Edit    - Change shape specifications
 *  Render  - Display all shapes
 *  Delete  - Delete a shape
 * --------------------------------------------------------------
 * Shapes:
 *  Line        - Line from (X0,Y0) to (X1,Y1)
 *  Polyline    - Series of lines from (X0,Y0) to (X1,Y1) ...
 *                (X(n-1),Y(n-1)) to (Xn,Yn)
 *  Polygon     - Solid made of series of regular or irregular
 *                sides, designated by points - (X0,Y0) to (X1,Y1)
 *                ... (Xn,Yn) to (X0,Y0)
 *  Rectangle   - Rectangle with user designated height,
 *                width
 *  Square      - Square with user designated width
 *  Ellipse     - Ellipse with user designated major, minor
 *                axes (radii)
 *  Circle      - Circle with user designated radius
 *  Text        - Text with user defined text box and text
 *
 * ==============================================================
 *  Programmers:
 * **************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvas.h"
#include <QMessageBox>
#include <QtWidgets>
#include <QTableWidget>

/****************************************************************
 * MAIN WINDOW CONSTRUCTOR
 * ==============================================================
 * Creates new main window, sets up for user input
 * --------------------------------------------------------------
 * IN
 * ------------------------
 *        parent : pointer to main window
 * **************************************************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),        // Passes parent pointer to main window
    ui(new Ui::MainWindow),     // Creates new main window
    allShapes(ui->renderArea)   // Passes canvas pointer to render shapes
{
    // FILE IO - Populates allShape's shape vector from file backup
    allShapes.addShapesFromFile();
    // UI - Sets up
    ui->setupUi(this);
    ui -> renderArea -> getShapes(allShapes.getVector());
    ui -> contactUs -> hide();

    // SET TO USER LEVEL ACCESS FOR CONSTRUCTOR
    ui -> userAdd -> hide();
    ui -> adminAdd -> show();
    ui -> userEdit -> hide();
    ui -> adminEdit -> show();

    ui -> editShapeSpecs -> hide();
    ui -> xShiftBox -> setEnabled(false);
    ui -> yShiftBox -> setEnabled(false);

    on_addShapeType_currentIndexChanged("--");

    ui -> editShapeID -> addItems(set_getShapeIds());
    ui -> deleteShapeID -> addItems(set_getShapeIds());

    updateShapeTables();

}
/****************************************************************
 * DESTRUCTOR
 * ==============================================================
 * Deletes ui pointer
 * **************************************************************/
MainWindow::~MainWindow()
{
    delete ui;
}

/****************************************************************
 * UPDATE SHAPE TABLES
 * ==============================================================
 * Updates shape tables, calls sort functions to sort
 * --------------------------------------------------------------
 * Sorts by:
 *  ID
 *  Area
 *  Perimeter
 * **************************************************************/
void MainWindow::updateShapeTables()
{
    ui -> shapeIDTable->setRowCount(allShapes.getShapeCount());
    sortIDTable();
    ui ->areaTable -> setRowCount(allShapes.getShapeCount());
    sortAreaTable();
    ui -> perimeterTable -> setRowCount(allShapes.getShapeCount());
    sortPerimeterTable();
}

/****************************************************************
 * Sort ID table
 * ==============================================================
 * Sorts vector by ID, sets values in ID-sorted table
 * **************************************************************/
void MainWindow::sortIDTable()
{
    myVector::vector<Shape *> sortedVector = allShapes.getVector();

    selectionSort(sortedVector, idCompare);

    for(int i = 0; i < allShapes.getVector().size(); ++i)
    {
        ui->shapeIDTable->setItem(i, TYPE, new QTableWidgetItem(QString::fromStdString((sortedVector[i]->getType()))));
        ui->shapeIDTable->setItem(i, ID, new QTableWidgetItem(QString::number(sortedVector[i]->getID())));
        ui->shapeIDTable->setItem(i, PERIMETER, new QTableWidgetItem(QString::number(sortedVector[i]->calcPerimeter())));
        ui->shapeIDTable->setItem(i, AREA, new QTableWidgetItem(QString::number(sortedVector[i]->calcArea())));
    }
}

/******************************************************************
 * Sort Perimeter table
 * ================================================================
 * Sorts vector by perimeter, sets values in perimeter-sorted table
 * ****************************************************************/
void MainWindow::sortPerimeterTable()
{
    myVector::vector<Shape *> sortedVector = allShapes.getVector();

    selectionSort(sortedVector, perimeterCompare);

    for(int i = 0; i < allShapes.getVector().size(); ++i)
    {
        ui->perimeterTable->setItem(i, TYPE, new QTableWidgetItem(QString::fromStdString((sortedVector[i]->getType()))));
        ui->perimeterTable->setItem(i, ID, new QTableWidgetItem(QString::number(sortedVector[i]->getID())));
        ui->perimeterTable->setItem(i, PERIMETER, new QTableWidgetItem(QString::number(sortedVector[i]->calcPerimeter())));
    }
}

/******************************************************************
 * Sort Area table
 * ================================================================
 * Sorts vector by area, sets values in area-sorted table
 * ****************************************************************/
void MainWindow::sortAreaTable()
{
    myVector::vector<Shape *> sortedVector = allShapes.getVector();

    selectionSort(sortedVector, areaCompare);

    for(int i = 0; i < allShapes.getVector().size(); ++i)
    {
        ui->areaTable->setItem(i, TYPE, new QTableWidgetItem(QString::fromStdString((sortedVector[i]->getType()))));
        ui->areaTable->setItem(i, ID, new QTableWidgetItem(QString::number(sortedVector[i]->getID())));
        ui->areaTable->setItem(i, (AREA-1), new QTableWidgetItem(QString::number(sortedVector[i]->calcArea())));
    }
}

/******************************************************************
 * DISABLE ADD TAB POLYLINE SPINBOXES
 * ================================================================
 * Disables polyline spinboxes until number of line points is set
 * ****************************************************************/
void MainWindow::disablePolylineSpinBoxes()
{
    ui -> addPolylinex1 -> setEnabled(false);
    ui -> addPolyliney1 -> setEnabled(false);
    ui -> addPolylinex2 -> setEnabled(false);
    ui -> addPolyliney2 -> setEnabled(false);
    ui -> addPolylinex3 -> setEnabled(false);
    ui -> addPolyliney3 -> setEnabled(false);
    ui -> addPolylinex4 -> setEnabled(false);
    ui -> addPolyliney4 -> setEnabled(false);
    ui -> addPolylinex5 -> setEnabled(false);
    ui -> addPolyliney5 -> setEnabled(false);
    ui -> addPolylinex6 -> setEnabled(false);
    ui -> addPolyliney6 -> setEnabled(false);
    ui -> addPolylinex7 -> setEnabled(false);
    ui -> addPolyliney7 -> setEnabled(false);
    ui -> addPolylinex8 -> setEnabled(false);
    ui -> addPolyliney8 -> setEnabled(false);
    ui -> addPolylinex9 -> setEnabled(false);
    ui -> addPolyliney9 -> setEnabled(false);
    ui -> addPolylinex10 -> setEnabled(false);
    ui -> addPolyliney10 -> setEnabled(false);
}

/******************************************************************
 * DISABLE EDIT TAB POLYLINE SPINBOXES
 * ================================================================
 * Disables polyline spinboxes until number of line points is set
 * ****************************************************************/
void MainWindow::disableEditPolylineSpinBoxes()
{
    ui -> editPolylinex1 -> setEnabled(false);
    ui -> editPolyliney1 -> setEnabled(false);
    ui -> editPolylinex2 -> setEnabled(false);
    ui -> editPolyliney2 -> setEnabled(false);
    ui -> editPolylinex3 -> setEnabled(false);
    ui -> editPolyliney3 -> setEnabled(false);
    ui -> editPolylinex4 -> setEnabled(false);
    ui -> editPolyliney4 -> setEnabled(false);
    ui -> editPolylinex5 -> setEnabled(false);
    ui -> editPolyliney5 -> setEnabled(false);
    ui -> editPolylinex6 -> setEnabled(false);
    ui -> editPolyliney6 -> setEnabled(false);
    ui -> editPolylinex7 -> setEnabled(false);
    ui -> editPolyliney7 -> setEnabled(false);
    ui -> editPolylinex8 -> setEnabled(false);
    ui -> editPolyliney8 -> setEnabled(false);
    ui -> editPolylinex9 -> setEnabled(false);
    ui -> editPolyliney9 -> setEnabled(false);
    ui -> editPolylinex10 -> setEnabled(false);
    ui -> editPolyliney10 -> setEnabled(false);
}

/******************************************************************
 * DISABLE ADD TAB POLYGON SPINBOXES
 * ================================================================
 * Disables polygon spinboxes until number of line points is set
 * ****************************************************************/
void MainWindow::disablePolygonSpinBoxes()
{
    ui -> addPolygonx1 -> setEnabled(false);
    ui -> addPolygony1 -> setEnabled(false);
    ui -> addPolygonx2 -> setEnabled(false);
    ui -> addPolygony2 -> setEnabled(false);
    ui -> addPolygonx3 -> setEnabled(false);
    ui -> addPolygony3 -> setEnabled(false);
    ui -> addPolygonx4 -> setEnabled(false);
    ui -> addPolygony4 -> setEnabled(false);
    ui -> addPolygonx5 -> setEnabled(false);
    ui -> addPolygony5 -> setEnabled(false);
    ui -> addPolygonx6 -> setEnabled(false);
    ui -> addPolygony6 -> setEnabled(false);
    ui -> addPolygonx7 -> setEnabled(false);
    ui -> addPolygony7 -> setEnabled(false);
    ui -> addPolygonx8 -> setEnabled(false);
    ui -> addPolygony8 -> setEnabled(false);
    ui -> addPolygonx9 -> setEnabled(false);
    ui -> addPolygony9 -> setEnabled(false);
    ui -> addPolygonx10 -> setEnabled(false);
    ui -> addPolygony10 -> setEnabled(false);
}

/******************************************************************
 * DISABLE EDIT TAB POLYGON SPINBOXES
 * ================================================================
 * Disables polygon spinboxes until number of line points is set
 * ****************************************************************/
void MainWindow::disableEditPolygonSpinBoxes()
{
    ui -> editPolygonx1 -> setEnabled(false);
    ui -> editPolygony1 -> setEnabled(false);
    ui -> editPolygonx2 -> setEnabled(false);
    ui -> editPolygony2 -> setEnabled(false);
    ui -> editPolygonx3 -> setEnabled(false);
    ui -> editPolygony3 -> setEnabled(false);
    ui -> editPolygonx4 -> setEnabled(false);
    ui -> editPolygony4 -> setEnabled(false);
    ui -> editPolygonx5 -> setEnabled(false);
    ui -> editPolygony5 -> setEnabled(false);
    ui -> editPolygonx6 -> setEnabled(false);
    ui -> editPolygony6 -> setEnabled(false);
    ui -> editPolygonx7 -> setEnabled(false);
    ui -> editPolygony7 -> setEnabled(false);
    ui -> editPolygonx8 -> setEnabled(false);
    ui -> editPolygony8 -> setEnabled(false);
    ui -> editPolygonx9 -> setEnabled(false);
    ui -> editPolygony9 -> setEnabled(false);
    ui -> editPolygonx10 -> setEnabled(false);
    ui -> editPolygony10 -> setEnabled(false);
}

/******************************************************************
 * RESET ADD LINE SPECIFICATIONS
 * ================================================================
 * Resets form specifications to zero or default combo box setting
 * ****************************************************************/
void MainWindow::clearAddLine()
{
    ui -> addLinex1 -> setValue(0);
    ui -> addLiney1 -> setValue(0);
    ui -> addLinex2 -> setValue(0);
    ui -> addLiney2 -> setValue(0);
    ui -> addLinePenColor -> setCurrentIndex(0);
    ui -> addLinePenWidth -> setValue(0);
    ui -> addLinePenStyle -> setCurrentIndex(0);
    ui -> addLineCapStyle -> setCurrentIndex(0);
    ui -> addLineJoinStyle -> setCurrentIndex(0);
    ui -> addShapeType -> setCurrentIndex(0);
}

/******************************************************************
 * RESET ADD POLYLINE SPECIFICATIONS
 * ================================================================
 * Resets form specifications to zero or default combo box setting
 * ****************************************************************/
void MainWindow::clearAddPolyline()
{
    ui -> addPolylineNumPoints -> setCurrentIndex(0);
    ui -> addPolylinePenColor -> setCurrentIndex(0);
    ui -> addPolylinePenWidth -> setValue(0);
    ui -> addPolylinePenStyle -> setCurrentIndex(0);
    ui -> addPolylineCapStyle -> setCurrentIndex(0);
    ui -> addPolylineJoinStyle -> setCurrentIndex(0);
    ui -> addPolylinex1 -> setValue(0);
    ui -> addPolyliney1 -> setValue(0);
    ui -> addPolylinex2 -> setValue(0);
    ui -> addPolyliney2 -> setValue(0);
    ui -> addPolylinex3 -> setValue(0);
    ui -> addPolyliney3 -> setValue(0);
    ui -> addPolylinex4 -> setValue(0);
    ui -> addPolyliney4 -> setValue(0);
    ui -> addPolylinex5 -> setValue(0);
    ui -> addPolyliney5 -> setValue(0);
    ui -> addPolylinex6 -> setValue(0);
    ui -> addPolyliney6 -> setValue(0);
    ui -> addPolylinex7 -> setValue(0);
    ui -> addPolyliney7 -> setValue(0);
    ui -> addPolylinex8 -> setValue(0);
    ui -> addPolyliney8 -> setValue(0);
    ui -> addPolylinex9 -> setValue(0);
    ui -> addPolyliney9 -> setValue(0);
    ui -> addPolylinex10 -> setValue(0);
    ui -> addPolyliney10 -> setValue(0);
    ui -> addShapeType -> setCurrentIndex(0);
}

/******************************************************************
 * RESET ADD POLYGON SPECIFICATIONS
 * ================================================================
 * Resets form specifications to zero or default combo box setting
 * ****************************************************************/
void MainWindow::clearAddPolygon()
{
    ui -> addPolygonNumPoints -> setCurrentIndex(0);
    ui -> addPolygonPenColor -> setCurrentIndex(0);
    ui -> addPolygonPenWidth -> setValue(0);
    ui -> addPolygonPenStyle ->setCurrentIndex(0);
    ui -> addPolygonCapStyle -> setCurrentIndex(0);
    ui -> addPolygonJoinStyle -> setCurrentIndex(0);
    ui -> addPolygonBrushColor ->setCurrentIndex(0);
    ui -> addPolygonBrushStyle -> setCurrentIndex(0);
    ui -> addPolygonx1 -> setValue(0);
    ui -> addPolygony1 -> setValue(0);
    ui -> addPolygonx2 -> setValue(0);
    ui -> addPolygony2 -> setValue(0);
    ui -> addPolygonx3 -> setValue(0);
    ui -> addPolygony3 -> setValue(0);
    ui -> addPolygonx4 -> setValue(0);
    ui -> addPolygony4 -> setValue(0);
    ui -> addPolygonx5 -> setValue(0);
    ui -> addPolygony5 -> setValue(0);
    ui -> addPolygonx6 -> setValue(0);
    ui -> addPolygony6 -> setValue(0);
    ui -> addPolygonx7 -> setValue(0);
    ui -> addPolygony7 -> setValue(0);
    ui -> addPolygonx8 -> setValue(0);
    ui -> addPolygony8 -> setValue(0);
    ui -> addPolygonx9 -> setValue(0);
    ui -> addPolygony9 -> setValue(0);
    ui -> addPolygonx10 -> setValue(0);
    ui -> addPolygony10 -> setValue(0);
    ui -> addShapeType -> setCurrentIndex(0);
}

/******************************************************************
 * RESET ADD RECTANGLE SPECIFICATIONS
 * ================================================================
 * Resets form specifications to zero or default combo box setting
 * ****************************************************************/
void MainWindow::clearAddRectangle()
{
    ui -> addRectanglePenColor -> setCurrentIndex(0);
    ui -> addRectanglePenWidth -> setValue(0);
    ui -> addRectanglePenStyle -> setCurrentIndex(0);
    ui -> addRectangleCapStyle -> setCurrentIndex(0);
    ui -> addRectangleJoinStyle -> setCurrentIndex(0);
    ui -> addRectangleBrushColor -> setCurrentIndex(0);
    ui -> addRectangleBrushStyle -> setCurrentIndex(0);
    ui -> addRectanglex1 -> setValue(0);
    ui -> addRectangley1 -> setValue(0);
    ui -> addRectanglew -> setValue(0);
    ui -> addRectangleh -> setValue(0);
    ui -> addShapeType -> setCurrentIndex(0);
}

/******************************************************************
 * RESET ADD SQUARE SPECIFICATIONS
 * ================================================================
 * Resets form specifications to zero or default combo box setting
 * ****************************************************************/
void MainWindow::clearAddSquare()
{
    ui -> addSquarePenColor->setCurrentIndex(0);
    ui -> addSquarePenColor ->setCurrentIndex(0);
    ui -> addSquarePenWidth ->setValue(0);
    ui -> addSquarePenStyle -> setCurrentIndex(0);
    ui -> addSquareCapStyle -> setCurrentIndex(0);
    ui -> addSquareJoinStyle -> setCurrentIndex(0);
    ui -> addSquareBrushColor -> setCurrentIndex(0);
    ui -> addSquareBrushStyle -> setCurrentIndex(0);
    ui -> addSquarex1 -> setValue(0);
    ui -> addSquarey1 -> setValue(0);
    ui -> addSquarel -> setValue(0);
    ui -> addShapeType -> setCurrentIndex(0);
}

/******************************************************************
 * RESET ADD ELLIPSE SPECIFICATIONS
 * ================================================================
 * Resets form specifications to zero or default combo box setting
 * ****************************************************************/
void MainWindow::clearAddEllipse()
{
    ui -> addEllipsePenColor->setCurrentIndex(0);
    ui -> addEllipsePenColor ->setCurrentIndex(0);
    ui -> addEllipsePenWidth ->setValue(0);
    ui -> addEllipsePenStyle -> setCurrentIndex(0);
    ui -> addEllipseCapStyle -> setCurrentIndex(0);
    ui -> addEllipseJoinStyle -> setCurrentIndex(0);
    ui -> addEllipseBrushColor -> setCurrentIndex(0);
    ui -> addEllipseBrushStyle -> setCurrentIndex(0);
    ui -> addEllipsex1 -> setValue(0);
    ui -> addEllipsey1 -> setValue(0);
    ui -> addEllipsea -> setValue(0);
    ui -> addEllipseb -> setValue(0);
    ui -> addShapeType -> setCurrentIndex(0);
}

/******************************************************************
 * RESET ADD CIRCLE SPECIFICATIONS
 * ================================================================
 * Resets form specifications to zero or default combo box setting
 * ****************************************************************/
void MainWindow::clearAddCircle()
{
    ui -> addCirclePenColor->setCurrentIndex(0);
    ui -> addCirclePenColor ->setCurrentIndex(0);
    ui -> addCirclePenWidth ->setValue(0);
    ui -> addCirclePenStyle -> setCurrentIndex(0);
    ui -> addCircleCapStyle -> setCurrentIndex(0);
    ui -> addCircleJoinStyle -> setCurrentIndex(0);
    ui -> addCircleBrushColor -> setCurrentIndex(0);
    ui -> addCircleBrushStyle -> setCurrentIndex(0);
    ui -> addCirclex1 -> setValue(0);
    ui -> addCircley1 -> setValue(0);
    ui -> addCircler -> setValue(0);
    ui -> addShapeType -> setCurrentIndex(0);
}

/******************************************************************
 * RESET ADD TEXT SPECIFICATIONS
 * ================================================================
 * Resets form specifications to zero or default combo box setting
 * ****************************************************************/
void MainWindow::clearAddText()
{
    ui -> addTextColor->setCurrentIndex(0);
    ui -> addTextAlignment ->setCurrentIndex(0);
    ui -> addTextFontFamily ->setCurrentIndex(0);
    ui -> addTextFontStyle -> setCurrentIndex(0);
    ui -> addTextFontWeight -> setCurrentIndex(0);
    ui -> addTextSize-> setValue(0);
    ui -> addTextx1 -> setValue(0);
    ui -> addTexty1 -> setValue(0);
    ui -> addTextw -> setValue(0);
    ui -> addTexth -> setValue(0);
    ui -> addTexttext -> clear();
    ui -> addShapeType -> setCurrentIndex(0);
}

/******************************************************************
 * RESET ALL ADD SPECIFICATIONS
 * ================================================================
 * Resets specifications for all forms
 * ****************************************************************/
void MainWindow::clearAdd()
{
    clearAddLine();
    clearAddPolyline();
    clearAddPolygon();
    clearAddRectangle();
    clearAddSquare();
    clearAddEllipse();
    clearAddCircle();
    clearAddText();
}

/******************************************************************
 * RESET EDIT LINE SPECIFICATIONS
 * ================================================================
 * Resets form specifications to zero or default combo box setting
 * ****************************************************************/
void MainWindow::clearEditLine()
{
    ui -> editLinex1 -> setValue(0);
    ui -> editLiney1 -> setValue(0);
    ui -> editLinex2 -> setValue(0);
    ui -> editLiney2 -> setValue(0);
    ui -> editLinePenColor -> setCurrentIndex(0);
    ui -> editLinePenWidth -> setValue(0);
    ui -> editLinePenStyle -> setCurrentIndex(0);
    ui -> editLineCapStyle -> setCurrentIndex(0);
    ui -> editLineJoinStyle -> setCurrentIndex(0);
}

/******************************************************************
 * RESET EDIT POLYLINE SPECIFICATIONS
 * ================================================================
 * Resets form specifications to zero or default combo box setting
 * ****************************************************************/
void MainWindow::clearEditPolyline()
{
    ui -> editPolylineNumPoints -> setCurrentIndex(0);
    ui -> editPolylinePenColor -> setCurrentIndex(0);
    ui -> editPolylinePenWidth -> setValue(0);
    ui -> editPolylinePenStyle -> setCurrentIndex(0);
    ui -> editPolylineCapStyle -> setCurrentIndex(0);
    ui -> editPolylineJoinStyle -> setCurrentIndex(0);
    ui -> editPolylinex1 -> setValue(0);
    ui -> editPolyliney1 -> setValue(0);
    ui -> editPolylinex2 -> setValue(0);
    ui -> editPolyliney2 -> setValue(0);
    ui -> editPolylinex3 -> setValue(0);
    ui -> editPolyliney3 -> setValue(0);
    ui -> editPolylinex4 -> setValue(0);
    ui -> editPolyliney4 -> setValue(0);
    ui -> editPolylinex5 -> setValue(0);
    ui -> editPolyliney5 -> setValue(0);
    ui -> editPolylinex6 -> setValue(0);
    ui -> editPolyliney6 -> setValue(0);
    ui -> editPolylinex7 -> setValue(0);
    ui -> editPolyliney7 -> setValue(0);
    ui -> editPolylinex8 -> setValue(0);
    ui -> editPolyliney8 -> setValue(0);
    ui -> editPolylinex9 -> setValue(0);
    ui -> editPolyliney9 -> setValue(0);
    ui -> editPolylinex10 -> setValue(0);
    ui -> editPolyliney10 -> setValue(0);
}

/******************************************************************
 * RESET EDIT POLYGON SPECIFICATIONS
 * ================================================================
 * Resets form specifications to zero or default combo box setting
 * ****************************************************************/
void MainWindow::clearEditPolygon()
{
    ui -> editPolygonNumPoints -> setCurrentIndex(0);
    ui -> editPolygonPenColor -> setCurrentIndex(0);
    ui -> editPolygonPenWidth -> setValue(0);
    ui -> editPolygonPenStyle ->setCurrentIndex(0);
    ui -> editPolygonCapStyle -> setCurrentIndex(0);
    ui -> editPolygonJoinStyle -> setCurrentIndex(0);
    ui -> editPolygonBrushColor ->setCurrentIndex(0);
    ui -> editPolygonBrushStyle -> setCurrentIndex(0);
    ui -> editPolygonx1 -> setValue(0);
    ui -> editPolygony1 -> setValue(0);
    ui -> editPolygonx2 -> setValue(0);
    ui -> editPolygony2 -> setValue(0);
    ui -> editPolygonx3 -> setValue(0);
    ui -> editPolygony3 -> setValue(0);
    ui -> editPolygonx4 -> setValue(0);
    ui -> editPolygony4 -> setValue(0);
    ui -> editPolygonx5 -> setValue(0);
    ui -> editPolygony5 -> setValue(0);
    ui -> editPolygonx6 -> setValue(0);
    ui -> editPolygony6 -> setValue(0);
    ui -> editPolygonx7 -> setValue(0);
    ui -> editPolygony7 -> setValue(0);
    ui -> editPolygonx8 -> setValue(0);
    ui -> editPolygony8 -> setValue(0);
    ui -> editPolygonx9 -> setValue(0);
    ui -> editPolygony9 -> setValue(0);
    ui -> editPolygonx10 -> setValue(0);
    ui -> editPolygony10 -> setValue(0);
}

/******************************************************************
 * RESET EDIT RECTANGLE SPECIFICATIONS
 * ================================================================
 * Resets form specifications to zero or default combo box setting
 * ****************************************************************/
void MainWindow::clearEditRectangle()
{
    ui -> editRectanglePenColor -> setCurrentIndex(0);
    ui -> editRectanglePenWidth -> setValue(0);
    ui -> editRectanglePenStyle -> setCurrentIndex(0);
    ui -> editRectangleCapStyle -> setCurrentIndex(0);
    ui -> editRectangleJoinStyle -> setCurrentIndex(0);
    ui -> editRectangleBrushColor -> setCurrentIndex(0);
    ui -> editRectangleBrushStyle -> setCurrentIndex(0);
    ui -> editRectanglex1 -> setValue(0);
    ui -> editRectangley1 -> setValue(0);
    ui -> editRectanglew -> setValue(0);
    ui -> editRectangleh -> setValue(0);
}

/******************************************************************
 * RESET EDIT SQUARE SPECIFICATIONS
 * ================================================================
 * Resets form specifications to zero or default combo box setting
 * ****************************************************************/
void MainWindow::clearEditSquare()
{
    ui -> editSquarePenColor->setCurrentIndex(0);
    ui -> editSquarePenColor ->setCurrentIndex(0);
    ui -> editSquarePenWidth ->setValue(0);
    ui -> editSquarePenStyle -> setCurrentIndex(0);
    ui -> editSquareCapStyle -> setCurrentIndex(0);
    ui -> editSquareJoinStyle -> setCurrentIndex(0);
    ui -> editSquareBrushColor -> setCurrentIndex(0);
    ui -> editSquareBrushStyle -> setCurrentIndex(0);
    ui -> editSquarex1 -> setValue(0);
    ui -> editSquarey1 -> setValue(0);
    ui -> editSquarel -> setValue(0);
}

/******************************************************************
 * RESET EDIT ELLIPSE SPECIFICATIONS
 * ================================================================
 * Resets form specifications to zero or default combo box setting
 * ****************************************************************/
void MainWindow::clearEditEllipse()
{
    ui -> editEllipsePenColor->setCurrentIndex(0);
    ui -> editEllipsePenColor ->setCurrentIndex(0);
    ui -> editEllipsePenWidth ->setValue(0);
    ui -> editEllipsePenStyle -> setCurrentIndex(0);
    ui -> editEllipseCapStyle -> setCurrentIndex(0);
    ui -> editEllipseJoinStyle -> setCurrentIndex(0);
    ui -> editEllipseBrushColor -> setCurrentIndex(0);
    ui -> editEllipseBrushStyle -> setCurrentIndex(0);
    ui -> editEllipsex1 -> setValue(0);
    ui -> editEllipsey1 -> setValue(0);
    ui -> editEllipsea -> setValue(0);
    ui -> editEllipseb -> setValue(0);
}

/******************************************************************
 * RESET EDIT CIRCLE SPECIFICATIONS
 * ================================================================
 * Resets form specifications to zero or default combo box setting
 * ****************************************************************/
void MainWindow::clearEditCircle()
{
    ui -> editCirclePenColor->setCurrentIndex(0);
    ui -> editCirclePenColor ->setCurrentIndex(0);
    ui -> editCirclePenWidth ->setValue(0);
    ui -> editCirclePenStyle -> setCurrentIndex(0);
    ui -> editCircleCapStyle -> setCurrentIndex(0);
    ui -> editCircleJoinStyle -> setCurrentIndex(0);
    ui -> editCircleBrushColor -> setCurrentIndex(0);
    ui -> editCircleBrushStyle -> setCurrentIndex(0);
    ui -> editCirclex1 -> setValue(0);
    ui -> editCircley1 -> setValue(0);
    ui -> editCircler -> setValue(0);
}

/******************************************************************
 * RESET EDIT TEXT SPECIFICATIONS
 * ================================================================
 * Resets form specifications to zero or default combo box setting
 * ****************************************************************/
void MainWindow::clearEditText()
{
    ui -> editTextColor->setCurrentIndex(0);
    ui -> editTextAlignment ->setCurrentIndex(0);
    ui -> editTextFontFamily ->setCurrentIndex(0);
    ui -> editTextFontStyle -> setCurrentIndex(0);
    ui -> editTextFontWeight -> setCurrentIndex(0);
    ui -> editTextSize-> setValue(0);
    ui -> editTextx1 -> setValue(0);
    ui -> editTexty1 -> setValue(0);
    ui -> editTextw -> clear();
    ui -> editTexth -> setValue(0);
    ui -> editTexttext -> clear();
}

/******************************************************************
 * RESET ALL EDIT SPECIFICATIONS
 * ================================================================
 * Resets specifications for all forms
 * ****************************************************************/
void MainWindow::clearEdit()
{
    clearEditLine();
    clearEditPolyline();
    clearEditPolygon();
    clearEditRectangle();
    clearEditSquare();
    clearEditEllipse();
    clearEditCircle();
    clearEditText();
}

/******************************************************************
 * LIST CURRENT SHAPE IDS
 * ================================================================
 * Returns QStringList of all current shape IDs
 * ****************************************************************/
QStringList MainWindow::set_getShapeIds()
{
    QStringList ids;
    int i{0};

    for(Shape *it : allShapes.getVector())
    {
        ids.insert(i, QString::number(it -> getID()));
        ++i;
    }

    return ids;
}

/******************************************************************
 * SET EDIT FIELDS WITH CURRENT SHAPE INFORMATION
 * ================================================================
 * Sets edit form fields with shape's current specifications
 * ****************************************************************/
void MainWindow::setCurrentShapeInfo()
{
    int shapeId = (ui->editShapeID->currentText()).toInt();
    Shape* p = allShapes.findShapePtr(shapeId);
    int i{0};

    QPen pen = p->getPen();
    QBrush brush = p->getBrush();

    if(allShapes.findShape(shapeId)=="Line")
    {
        ui ->editLinex1->setValue(p->getDimensions()[int(Line::Specifications::X1)]);
        ui ->editLiney1->setValue(p->getDimensions()[int(Line::Specifications::Y1)]);
        ui ->editLinex2->setValue(p->getDimensions()[int(Line::Specifications::X2)]);
        ui ->editLiney2->setValue(p->getDimensions()[int(Line::Specifications::Y2)]);

        ui ->editLinePenColor->setCurrentText(QString::fromStdString(getColorAsString(pen.color())));
        ui ->editLinePenWidth->setValue(pen.width());
        ui ->editLinePenStyle->setCurrentText(QString::fromStdString(getPenStyleAsString(pen.style())));
        ui ->editLineCapStyle->setCurrentText(QString::fromStdString(getCapStyleAsString(pen.capStyle())));
        ui ->editLineJoinStyle->setCurrentText(QString::fromStdString(getJoinStyleAsString(pen.joinStyle())));
    }
    else if(allShapes.findShape(shapeId)=="Polyline")
    {
        clearEditPolyline();

        int numPolylinePoints = p->getNumDimensions() / 2;
        ui->editPolylineNumPoints->setCurrentIndex(0);

        if(numPolylinePoints >= 1)
        {
            ui->editPolylinex1->setValue(p->getDimensions()[i]);
            ui->editPolyliney1->setValue(p->getDimensions()[i+1]);
            i += 2;
        }
        if(numPolylinePoints >= 2)
        {
            ui->editPolylinex2->setValue(p->getDimensions()[i]);
            ui->editPolyliney2->setValue(p->getDimensions()[i+1]);
            i += 2;
        }
        if(numPolylinePoints >= 3)
        {
            ui->editPolylinex3->setValue(p->getDimensions()[i]);
            ui->editPolyliney3->setValue(p->getDimensions()[i+1]);
            i += 2;
        }
        if(numPolylinePoints >= 4)
        {
            ui->editPolylinex4->setValue(p->getDimensions()[i]);
            ui->editPolyliney4->setValue(p->getDimensions()[i+1]);
            i += 2;
        }
        if(numPolylinePoints >= 5)
        {
            ui->editPolylinex5->setValue(p->getDimensions()[i]);
            ui->editPolyliney5->setValue(p->getDimensions()[i+1]);
            i += 2;
        }
        if(numPolylinePoints >= 6)
        {
            ui->editPolylinex6->setValue(p->getDimensions()[i]);
            ui->editPolyliney6->setValue(p->getDimensions()[i+1]);
            i += 2;
        }
        if(numPolylinePoints >= 7)
        {
            ui->editPolylinex7->setValue(p->getDimensions()[i]);
            ui->editPolyliney7->setValue(p->getDimensions()[i+1]);
            i += 2;
        }
        if(numPolylinePoints >= 8)
        {
            ui->editPolylinex8->setValue(p->getDimensions()[i]);
            ui->editPolyliney8->setValue(p->getDimensions()[i+1]);
            i += 2;
        }
        if(numPolylinePoints >= 9)
        {
            ui->editPolylinex9->setValue(p->getDimensions()[i]);
            ui->editPolyliney9->setValue(p->getDimensions()[i+1]);
            i += 2;
        }
        if(numPolylinePoints == 10)
        {
            ui->editPolylinex10->setValue(p->getDimensions()[i]);
            ui->editPolyliney10->setValue(p->getDimensions()[i+1]);
        }

        ui ->editPolylinePenColor->setCurrentText(QString::fromStdString(getColorAsString(pen.color())));
        ui ->editPolylinePenWidth->setValue(pen.width());
        ui ->editPolylinePenStyle->setCurrentText(QString::fromStdString(getPenStyleAsString(pen.style())));
        ui ->editPolylineCapStyle->setCurrentText(QString::fromStdString(getCapStyleAsString(pen.capStyle())));
        ui ->editPolylineJoinStyle->setCurrentText(QString::fromStdString(getJoinStyleAsString(pen.joinStyle())));
    }
    else if(allShapes.findShape(shapeId)=="Polygon")
    {
        clearEditPolygon();

        int numPolygonPoints = p->getNumDimensions() / 2;
        ui->editPolygonNumPoints->setCurrentIndex(0);

        if(numPolygonPoints >= 1)
        {
            ui->editPolygonx1->setValue(p->getDimensions()[i]);
            ui->editPolygony1->setValue(p->getDimensions()[i+1]);
            i += 2;
        }
        if(numPolygonPoints >= 2)
        {
            ui->editPolygonx2->setValue(p->getDimensions()[i]);
            ui->editPolygony2->setValue(p->getDimensions()[i+1]);
            i += 2;
        }
        if(numPolygonPoints >= 3)
        {
            ui->editPolygonx3->setValue(p->getDimensions()[i]);
            ui->editPolygony3->setValue(p->getDimensions()[i+1]);
            i += 2;
        }
        if(numPolygonPoints >= 4)
        {
            ui->editPolygonx4->setValue(p->getDimensions()[i]);
            ui->editPolygony4->setValue(p->getDimensions()[i+1]);
            i += 2;
        }
        if(numPolygonPoints >= 5)
        {
            ui->editPolygonx5->setValue(p->getDimensions()[i]);
            ui->editPolygony5->setValue(p->getDimensions()[i+1]);
            i += 2;
        }
        if(numPolygonPoints >= 6)
        {
            ui->editPolygonx6->setValue(p->getDimensions()[i]);
            ui->editPolygony6->setValue(p->getDimensions()[i+1]);
            i += 2;
        }
        if(numPolygonPoints >= 7)
        {
            ui->editPolygonx7->setValue(p->getDimensions()[i]);
            ui->editPolygony7->setValue(p->getDimensions()[i+1]);
            i += 2;
        }
        if(numPolygonPoints >= 8)
        {
            ui->editPolygonx8->setValue(p->getDimensions()[i]);
            ui->editPolygony8->setValue(p->getDimensions()[i+1]);
            i += 2;
        }
        if(numPolygonPoints >= 9)
        {
            ui->editPolygonx9->setValue(p->getDimensions()[i]);
            ui->editPolygony9->setValue(p->getDimensions()[i+1]);
            i += 2;
        }
        if(numPolygonPoints == 10)
        {
            ui->editPolygonx10->setValue(p->getDimensions()[i]);
            ui->editPolygony10->setValue(p->getDimensions()[i+1]);
        }

        ui ->editPolygonPenColor->setCurrentText(QString::fromStdString(getColorAsString(pen.color())));
        ui ->editPolygonPenWidth->setValue(pen.width());
        ui ->editPolygonPenStyle->setCurrentText(QString::fromStdString(getPenStyleAsString(pen.style())));
        ui ->editPolygonCapStyle->setCurrentText(QString::fromStdString(getCapStyleAsString(pen.capStyle())));
        ui ->editPolygonJoinStyle->setCurrentText(QString::fromStdString(getJoinStyleAsString(pen.joinStyle())));
        ui ->editPolygonBrushColor->setCurrentText(QString::fromStdString(getColorAsString(brush.color())));
        ui ->editPolygonBrushStyle->setCurrentText(QString::fromStdString(getBrushStyleAsString(brush.style())));
    }
    else if(allShapes.findShape(shapeId)=="Rectangle")
    {
        ui ->editRectanglex1->setValue(p->getDimensions()[int(Rectangle::Specifications::X1)]);
        ui ->editRectangley1->setValue(p->getDimensions()[int(Rectangle::Specifications::Y1)]);
        ui ->editRectanglew->setValue(p->getDimensions()[int(Rectangle::Specifications::W)]);
        ui ->editRectangleh->setValue(p->getDimensions()[int(Rectangle::Specifications::H)]);

        ui ->editRectanglePenColor->setCurrentText(QString::fromStdString(getColorAsString(pen.color())));
        ui ->editRectanglePenWidth->setValue(pen.width());
        ui ->editRectanglePenStyle->setCurrentText(QString::fromStdString(getPenStyleAsString(pen.style())));
        ui ->editRectangleCapStyle->setCurrentText(QString::fromStdString(getCapStyleAsString(pen.capStyle())));
        ui ->editRectangleJoinStyle->setCurrentText(QString::fromStdString(getJoinStyleAsString(pen.joinStyle())));

        ui ->editRectangleBrushColor->setCurrentText(QString::fromStdString(getColorAsString(brush.color())));
        ui ->editRectangleBrushStyle->setCurrentText(QString::fromStdString(getBrushStyleAsString(brush.style())));
    }
    else if(allShapes.findShape(shapeId)=="Square")
    {
        ui ->editSquarex1->setValue(p->getDimensions()[int(Square::Specifications::X1)]);
        ui ->editSquarey1->setValue(p->getDimensions()[int(Square::Specifications::Y1)]);
        ui ->editSquarel->setValue(p->getDimensions()[int(Square::Specifications::L)]);

        ui ->editSquarePenColor->setCurrentText(QString::fromStdString(getColorAsString(pen.color())));
        ui ->editSquarePenWidth->setValue(pen.width());
        ui ->editSquarePenStyle->setCurrentText(QString::fromStdString(getPenStyleAsString(pen.style())));
        ui ->editSquareCapStyle->setCurrentText(QString::fromStdString(getCapStyleAsString(pen.capStyle())));
        ui ->editSquareJoinStyle->setCurrentText(QString::fromStdString(getJoinStyleAsString(pen.joinStyle())));

        ui ->editSquareBrushColor->setCurrentText(QString::fromStdString(getColorAsString(brush.color())));
        ui ->editSquareBrushStyle->setCurrentText(QString::fromStdString(getBrushStyleAsString(brush.style())));
    }
    else if(allShapes.findShape(shapeId)=="Ellipse")
    {
        ui ->editEllipsex1->setValue(p->getDimensions()[int(Ellipse::Specifications::X1)]);
        ui ->editEllipsey1->setValue(p->getDimensions()[int(Ellipse::Specifications::Y1)]);
        ui ->editEllipsea->setValue(p->getDimensions()[int(Ellipse::Specifications::A)]);
        ui ->editEllipseb->setValue(p->getDimensions()[int(Ellipse::Specifications::B)]);

        ui ->editEllipsePenColor->setCurrentText(QString::fromStdString(getColorAsString(pen.color())));
        ui ->editEllipsePenWidth->setValue(pen.width());
        ui ->editEllipsePenStyle->setCurrentText(QString::fromStdString(getPenStyleAsString(pen.style())));
        ui ->editEllipseCapStyle->setCurrentText(QString::fromStdString(getCapStyleAsString(pen.capStyle())));
        ui ->editEllipseJoinStyle->setCurrentText(QString::fromStdString(getJoinStyleAsString(pen.joinStyle())));

        ui ->editEllipseBrushColor->setCurrentText(QString::fromStdString(getColorAsString(brush.color())));
        ui ->editEllipseBrushStyle->setCurrentText(QString::fromStdString(getBrushStyleAsString(brush.style())));
    }
    else if(allShapes.findShape(shapeId)=="Circle")
    {
        ui ->editCirclex1->setValue(p->getDimensions()[int(Circle::Specifications::X1)]);
        ui ->editCircley1->setValue(p->getDimensions()[int(Circle::Specifications::Y1)]);
        ui ->editCircler->setValue(p->getDimensions()[int(Circle::Specifications::RADIUS)]);

        ui ->editCirclePenColor->setCurrentText(QString::fromStdString(getColorAsString(pen.color())));
        ui ->editCirclePenWidth->setValue(pen.width());
        ui ->editCirclePenStyle->setCurrentText(QString::fromStdString(getPenStyleAsString(pen.style())));
        ui ->editCircleCapStyle->setCurrentText(QString::fromStdString(getCapStyleAsString(pen.capStyle())));
        ui ->editCircleJoinStyle->setCurrentText(QString::fromStdString(getJoinStyleAsString(pen.joinStyle())));

        ui ->editCircleBrushColor->setCurrentText(QString::fromStdString(getColorAsString(brush.color())));
        ui ->editCircleBrushStyle->setCurrentText(QString::fromStdString(getBrushStyleAsString(brush.style())));
    }
    else if(allShapes.findShape(shapeId)=="Text")
    {
        QFont font = p->getFont();

        ui ->editTextx1->setValue(p->getDimensions()[int(Text::Specifications::X1)]);
        ui ->editTexty1->setValue(p->getDimensions()[int(Text::Specifications::Y1)]);
        ui ->editTextw->setValue(p->getDimensions()[int(Text::Specifications::W)]);
        ui ->editTexth->setValue(p->getDimensions()[int(Text::Specifications::H)]);

        ui ->editTexttext->setText(QString::fromStdString(p->getText()));
        ui ->editTextColor->setCurrentText(QString::fromStdString(getColorAsString(pen.color())));
        ui ->editTextAlignment->setCurrentText(QString(p->getFlag()));
        ui ->editTextSize->setValue(font.pointSize());
        ui ->editTextFontFamily->setCurrentText(font.family());
        ui ->editTextFontStyle->setCurrentText(QString::fromStdString(getFontStyleAsString(font.style())));
        ui ->editTextFontWeight->setCurrentText(QString::fromStdString(getFontWeightAsString(QFont::Weight(font.weight()))));
    }
}

void MainWindow::on_addShapeType_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "Line"){
        ui -> addLine -> show();
        ui -> addPolygon -> hide();
        ui -> addPolyline -> hide();
        ui -> addRectangle -> hide();
        ui -> addSquare -> hide();
        ui -> addEllipse -> hide();
        ui -> addCircle -> hide();
        ui -> addText -> hide();}
    else if(arg1 == "Polyline"){
        ui -> addPolyline -> show();
        disablePolylineSpinBoxes();
        ui -> addPolygon -> hide();
        ui -> addLine -> hide();
        ui -> addRectangle -> hide();
        ui -> addSquare -> hide();
        ui -> addEllipse -> hide();
        ui -> addCircle -> hide();
        ui -> addText -> hide();}
    else if(arg1 == "Polygon"){
        ui -> addPolygon -> show();
        disablePolygonSpinBoxes();
        ui -> addLine -> hide();
        ui -> addPolyline -> hide();
        ui -> addRectangle -> hide();
        ui -> addSquare -> hide();
        ui -> addEllipse -> hide();
        ui -> addCircle -> hide();
        ui -> addText -> hide();}
    else if(arg1 == "Rectangle"){
        ui -> addRectangle -> show();
        ui -> addPolygon -> hide();
        ui -> addPolyline -> hide();
        ui -> addLine -> hide();
        ui -> addSquare -> hide();
        ui -> addEllipse -> hide();
        ui -> addCircle -> hide();
        ui -> addText -> hide();}
    else if(arg1 == "Square"){
        ui -> addSquare -> show();
        ui -> addLine -> hide();
        ui -> addPolyline -> hide();
        ui -> addRectangle -> hide();
        ui -> addPolygon -> hide();
        ui -> addEllipse -> hide();
        ui -> addCircle -> hide();
        ui -> addText -> hide();}
    else if(arg1 == "Ellipse"){
        ui -> addEllipse -> show();
        ui -> addPolygon -> hide();
        ui -> addPolyline -> hide();
        ui -> addRectangle -> hide();
        ui -> addSquare -> hide();
        ui -> addLine -> hide();
        ui -> addCircle -> hide();
        ui -> addText -> hide();}
    else if(arg1 == "Circle"){
        ui -> addCircle -> show();
        ui -> addPolygon -> hide();
        ui -> addPolyline -> hide();
        ui -> addRectangle -> hide();
        ui -> addSquare -> hide();
        ui -> addEllipse -> hide();
        ui -> addLine -> hide();
        ui -> addText -> hide();}
    else if(arg1 == "Text"){
        ui -> addText -> show();
        ui -> addPolygon -> hide();
        ui -> addPolyline -> hide();
        ui -> addRectangle -> hide();
        ui -> addSquare -> hide();
        ui -> addEllipse -> hide();
        ui -> addCircle -> hide();
        ui -> addLine -> hide();}
    else{
        ui -> addText -> hide();
        ui -> addPolygon -> hide();
        ui -> addPolyline -> hide();
        ui -> addRectangle -> hide();
        ui -> addSquare -> hide();
        ui -> addEllipse -> hide();
        ui -> addCircle -> hide();
        ui -> addLine -> hide();}
}

void MainWindow::on_lineSave_clicked()
{
    dim::specs lineDimensions[NUM_LINE_SPECS];

    lineDimensions[int(Line::Specifications::X1)] = ui -> addLinex1 -> value();
    lineDimensions[int(Line::Specifications::X2)] = ui -> addLinex2 -> value();
    lineDimensions[int(Line::Specifications::Y1)] = ui -> addLiney1 -> value();
    lineDimensions[int(Line::Specifications::Y2)] = ui -> addLiney2 -> value();

    dim::specs *dims = lineDimensions;

    Shape* p_Shape = new class::Line(allShapes.incrementShapeCount(), SHAPES_LIST[LINE], NUM_LINE_SPECS, dims);
    QPen pen;

    pen.setColor(QColor(ui -> addLinePenColor->currentText()));
    pen.setWidth(ui -> addLinePenWidth -> value());
    pen.setStyle(convertToPenStyle((ui -> addLinePenStyle -> currentText()).toStdString()));
    pen.setCapStyle(convertToPenCapStyle((ui -> addLineCapStyle -> currentText()).toStdString()));
    pen.setJoinStyle(convertToPenJoinStyle((ui -> addLineJoinStyle -> currentText()).toStdString()));

    p_Shape -> setPen(pen);
    allShapes.newShape(p_Shape);

    QMessageBox::information(this, "Save Successful", "New Line Added\nClick Update to View Changes", QMessageBox::Ok);

    clearAddLine();
}

void MainWindow::on_lineCancel_clicked()
{
    clearAddLine();
}

void MainWindow::on_editLineSave_clicked()
{
    dim::specs lineDimensions[NUM_LINE_SPECS];
    lineDimensions[int(Line::Specifications::X1)] = ui -> editLinex1 -> value();
    lineDimensions[int(Line::Specifications::X2)] = ui -> editLinex2 -> value();
    lineDimensions[int(Line::Specifications::Y1)] = ui -> editLiney1 -> value();
    lineDimensions[int(Line::Specifications::Y2)] = ui -> editLiney2 -> value();

    dim::specs *dims = lineDimensions;
    int shapeId;

    shapeId = (ui->editShapeID->currentText()).toInt();

    QPen pen;

    pen.setColor(QColor(ui -> editLinePenColor->currentText()));
    pen.setWidth(ui -> editLinePenWidth -> value());
    pen.setStyle(convertToPenStyle((ui -> editLinePenStyle -> currentText()).toStdString()));
    pen.setCapStyle(convertToPenCapStyle((ui -> editLineCapStyle -> currentText()).toStdString()));
    pen.setJoinStyle(convertToPenJoinStyle((ui -> editLineJoinStyle -> currentText()).toStdString()));

    allShapes.editShape(shapeId, NUM_LINE_SPECS, dims, pen);

    QMessageBox::information(this, "Edit Successful", "Line Updated\nChanges are now visible", QMessageBox::Ok);
    setCurrentShapeInfo();
}

void MainWindow::on_editLineCancel_clicked()
{
    setCurrentShapeInfo();
}

void MainWindow::on_polylineSave_clicked()
{
    int numPolylinePoints = ui -> addPolylineNumPoints -> currentIndex();
    int numPolylineSpecs = numPolylinePoints * 2;
    int i{0};
    dim::specs polylineDimensions[numPolylineSpecs];

    if(numPolylinePoints >= 1)
    {
        polylineDimensions[i] = ui -> addPolylinex1 -> value();
        polylineDimensions[i+1] = ui -> addPolyliney1 -> value();
        i += 2;
    }
    if(numPolylinePoints >= 2)
    {
        polylineDimensions[i] = ui -> addPolylinex2 -> value();
        polylineDimensions[i+1] = ui -> addPolyliney2 -> value();
        i += 2;
    }
    if(numPolylinePoints >= 3)
    {
        polylineDimensions[i] = ui -> addPolylinex3 -> value();
        polylineDimensions[i+1] = ui -> addPolyliney3 -> value();
        i += 2;
    }
    if(numPolylinePoints >= 4)
    {
        polylineDimensions[i] = ui -> addPolylinex4 -> value();
        polylineDimensions[i+1] = ui -> addPolyliney4 -> value();
        i += 2;
    }
    if(numPolylinePoints >= 5)
    {
        polylineDimensions[i] = ui -> addPolylinex5 -> value();
        polylineDimensions[i+1] = ui -> addPolyliney5 -> value();
        i += 2;
    }
    if(numPolylinePoints >= 6)
    {
        polylineDimensions[i] = ui -> addPolylinex6 -> value();
        polylineDimensions[i+1] = ui -> addPolyliney6 -> value();
        i += 2;
    }
    if(numPolylinePoints >= 7)
    {
        polylineDimensions[i] = ui -> addPolylinex7 -> value();
        polylineDimensions[i+1] = ui -> addPolyliney7 -> value();
        i += 2;
    }
    if(numPolylinePoints >= 8)
    {
        polylineDimensions[i] = ui -> addPolylinex8 -> value();
        polylineDimensions[i+1] = ui -> addPolyliney8 -> value();
        i += 2;
    }
    if(numPolylinePoints >= 9)
    {
        polylineDimensions[i] = ui -> addPolylinex9 -> value();
        polylineDimensions[i+1] = ui -> addPolyliney9 -> value();
        i += 2;
    }
    if(numPolylinePoints == 10)
    {
        polylineDimensions[i] = ui -> addPolylinex10 -> value();
        polylineDimensions[i+1] = ui -> addPolyliney10 -> value();
    }

    dim::specs *dims = polylineDimensions;

    Shape* p_Shape = new class::Polyline(allShapes.incrementShapeCount(), SHAPES_LIST[POLYLINE], numPolylineSpecs, dims);
    QPen pen;

    pen.setColor(QColor(ui -> addPolylinePenColor->currentText()));
    pen.setWidth(ui -> addPolylinePenWidth -> value());
    pen.setStyle(convertToPenStyle((ui -> addPolylinePenStyle -> currentText()).toStdString()));
    pen.setCapStyle(convertToPenCapStyle((ui -> addPolylineCapStyle -> currentText()).toStdString()));
    pen.setJoinStyle(convertToPenJoinStyle((ui -> addPolylineJoinStyle -> currentText()).toStdString()));

    p_Shape -> setPen(pen);
    allShapes.newShape(p_Shape);

    QMessageBox::information(this, "Save Successful", "New Polyline Added\nClick Update to View Changes", QMessageBox::Ok);
    clearAddPolyline();
}

void MainWindow::on_polylineCancel_clicked()
{
    clearAddPolyline();
}

void MainWindow::on_editPolylineSave_clicked()
{
    try
    {
        int numPolylinePoints = ui -> editPolylineNumPoints -> currentIndex();

        if(numPolylinePoints == 0)
        {
            throw(1);
        }

        int numPolylineSpecs = numPolylinePoints * 2;
        int i{0};
        dim::specs polylineDimensions[numPolylineSpecs];

        if(numPolylinePoints >= 1)
        {
            polylineDimensions[i] = ui -> editPolylinex1 -> value();
            polylineDimensions[i+1] = ui -> editPolyliney1 -> value();
            i += 2;
        }
        if(numPolylinePoints >= 2)
        {
            polylineDimensions[i] = ui -> editPolylinex2 -> value();
            polylineDimensions[i+1] = ui -> editPolyliney2 -> value();
            i += 2;
        }
        if(numPolylinePoints >= 3)
        {
            polylineDimensions[i] = ui -> editPolylinex3 -> value();
            polylineDimensions[i+1] = ui -> editPolyliney3 -> value();
            i += 2;
        }
        if(numPolylinePoints >= 4)
        {
            polylineDimensions[i] = ui -> editPolylinex4 -> value();
            polylineDimensions[i+1] = ui -> editPolyliney4 -> value();
            i += 2;
        }
        if(numPolylinePoints >= 5)
        {
            polylineDimensions[i] = ui -> editPolylinex5 -> value();
            polylineDimensions[i+1] = ui -> editPolyliney5 -> value();
            i += 2;
        }
        if(numPolylinePoints >= 6)
        {
            polylineDimensions[i] = ui -> editPolylinex6 -> value();
            polylineDimensions[i+1] = ui -> editPolyliney6 -> value();
            i += 2;
        }
        if(numPolylinePoints >= 7)
        {
            polylineDimensions[i] = ui -> editPolylinex7 -> value();
            polylineDimensions[i+1] = ui -> editPolyliney7 -> value();
            i += 2;
        }
        if(numPolylinePoints >= 8)
        {
            polylineDimensions[i] = ui -> editPolylinex8 -> value();
            polylineDimensions[i+1] = ui -> editPolyliney8 -> value();
            i += 2;
        }
        if(numPolylinePoints >= 9)
        {
            polylineDimensions[i] = ui -> editPolylinex9 -> value();
            polylineDimensions[i+1] = ui -> editPolyliney9 -> value();
            i += 2;
        }
        if(numPolylinePoints == 10)
        {
            polylineDimensions[i] = ui -> editPolylinex10 -> value();
            polylineDimensions[i+1] = ui -> editPolyliney10 -> value();
        }

        dim::specs *dims = polylineDimensions;
        QPen pen;
        int shapeId;

        shapeId = (ui->editShapeID->currentText()).toInt();

        pen.setColor(QColor(ui -> editPolylinePenColor->currentText()));
        pen.setWidth(ui -> editPolylinePenWidth -> value());
        pen.setStyle(convertToPenStyle((ui -> editPolylinePenStyle -> currentText()).toStdString()));
        pen.setCapStyle(convertToPenCapStyle((ui -> editPolylineCapStyle -> currentText()).toStdString()));
        pen.setJoinStyle(convertToPenJoinStyle((ui -> editPolylineJoinStyle -> currentText()).toStdString()));

        allShapes.editShape(shapeId, numPolylineSpecs, dims, pen);

        QMessageBox::information(this, "Edit Successful", "Polyline Updated\nChanges are now visible", QMessageBox::Ok);
        setCurrentShapeInfo();
    }
    catch(int)
    {
        QMessageBox::warning(this, "Invalid Number of Points", "Please choose a valid number of points (between 1 and 10)", QMessageBox::Ok);
        ui->editPolylineNumPoints->setCurrentIndex(0);
    }
}

void MainWindow::on_editPolylineCancel_clicked()
{
    setCurrentShapeInfo();
}

void MainWindow::on_polygonSave_clicked()
{
    int numPolygonPoints = ui -> addPolygonNumPoints -> currentIndex();

    int numPolygonSpecs = numPolygonPoints * 2;
    int i{0};
    dim::specs polygonDimensions[numPolygonSpecs];

    if(numPolygonPoints >= 1)
    {
        polygonDimensions[i] = ui -> addPolygonx1 -> value();
        polygonDimensions[i+1] = ui -> addPolygony1 -> value();
        i += 2;
    }
    if(numPolygonPoints >= 2)
    {
        polygonDimensions[i] = ui -> addPolygonx2 -> value();
        polygonDimensions[i+1] = ui -> addPolygony2 -> value();
        i += 2;
    }
    if(numPolygonPoints >= 3)
    {
        polygonDimensions[i] = ui -> addPolygonx3 -> value();
        polygonDimensions[i+1] = ui -> addPolygony3 -> value();
        i += 2;
    }
    if(numPolygonPoints >= 4)
    {
        polygonDimensions[i] = ui -> addPolygonx4 -> value();
        polygonDimensions[i+1] = ui -> addPolygony4 -> value();
        i += 2;
    }
    if(numPolygonPoints == 5)
    {
        polygonDimensions[i] = ui -> addPolygonx5 -> value();
        polygonDimensions[i+1] = ui -> addPolygony5 -> value();
        i += 2;
    }
    if(numPolygonPoints >= 6)
    {
        polygonDimensions[i] = ui -> addPolygonx6 -> value();
        polygonDimensions[i+1] = ui -> addPolygony6 -> value();
        i += 2;
    }
    if(numPolygonPoints >= 7)
    {
        polygonDimensions[i] = ui -> addPolygonx7 -> value();
        polygonDimensions[i+1] = ui -> addPolygony7 -> value();
        i += 2;
    }
    if(numPolygonPoints >= 8)
    {
        polygonDimensions[i] = ui -> addPolygonx8 -> value();
        polygonDimensions[i+1] = ui -> addPolygony8 -> value();
        i += 2;
    }
    if(numPolygonPoints >= 9)
    {
        polygonDimensions[i] = ui -> addPolygonx9 -> value();
        polygonDimensions[i+1] = ui -> addPolygony9 -> value();
        i += 2;
    }
    if(numPolygonPoints == 10)
    {
        polygonDimensions[i] = ui -> addPolygonx10 -> value();
        polygonDimensions[i+1] = ui -> addPolygony10 -> value();
    }

    dim::specs *dims = polygonDimensions;

    Shape* p_Shape = new class::Polygon(allShapes.incrementShapeCount(), SHAPES_LIST[POLYGON], numPolygonSpecs, dims);
    QPen pen;
    QBrush brush;

    pen.setColor(QColor(ui -> addPolygonPenColor->currentText()));
    pen.setWidth(ui -> addPolygonPenWidth -> value());
    pen.setStyle(convertToPenStyle((ui -> addPolygonPenStyle -> currentText()).toStdString()));
    pen.setCapStyle(convertToPenCapStyle((ui -> addPolygonCapStyle -> currentText()).toStdString()));
    pen.setJoinStyle(convertToPenJoinStyle((ui -> addPolygonJoinStyle -> currentText()).toStdString()));

    brush.setColor(QColor(ui -> addPolygonBrushColor -> currentText()));
    brush.setStyle(convertToBrushStyle((ui -> addPolygonBrushStyle -> currentText().toStdString())));

    p_Shape -> setPen(pen);
    p_Shape -> setBrush(brush);
    allShapes.newShape(p_Shape);

    QMessageBox::information(this, "Save Successful", "New Polygon Added\nClick Update to View Changes", QMessageBox::Ok);
    clearAddPolygon();
}

void MainWindow::on_polygonCancel_clicked()
{
    clearAddPolygon();
}

void MainWindow::on_editPolygonSave_clicked()
{
    try
    {
        int numPolygonPoints = ui -> editPolygonNumPoints -> currentIndex();

        if(numPolygonPoints == 0)
        {
            throw(1);
        }

        int numPolygonSpecs = numPolygonPoints * 2;
        int i{0};
        dim::specs polygonDimensions[numPolygonSpecs];

        if(numPolygonPoints >= 1)
        {
            polygonDimensions[i] = ui -> editPolygonx1 -> value();
            polygonDimensions[i+1] = ui -> editPolygony1 -> value();
            i += 2;
        }
        if(numPolygonPoints >= 2)
        {
            polygonDimensions[i] = ui -> editPolygonx2 -> value();
            polygonDimensions[i+1] = ui -> editPolygony2 -> value();
            i += 2;
        }
        if(numPolygonPoints >= 3)
        {
            polygonDimensions[i] = ui -> editPolygonx3 -> value();
            polygonDimensions[i+1] = ui -> editPolygony3 -> value();
            i += 2;
        }
        if(numPolygonPoints >= 4)
        {
            polygonDimensions[i] = ui -> editPolygonx4 -> value();
            polygonDimensions[i+1] = ui -> editPolygony4 -> value();
            i += 2;
        }
        if(numPolygonPoints == 5)
        {
            polygonDimensions[i] = ui -> editPolygonx5 -> value();
            polygonDimensions[i+1] = ui -> editPolygony5 -> value();
            i += 2;
        }
        if(numPolygonPoints >= 6)
        {
            polygonDimensions[i] = ui -> editPolygonx6 -> value();
            polygonDimensions[i+1] = ui -> editPolygony6 -> value();
            i += 2;
        }
        if(numPolygonPoints >= 7)
        {
            polygonDimensions[i] = ui -> editPolygonx7 -> value();
            polygonDimensions[i+1] = ui -> editPolygony7 -> value();
            i += 2;
        }
        if(numPolygonPoints >= 8)
        {
            polygonDimensions[i] = ui -> editPolygonx8 -> value();
            polygonDimensions[i+1] = ui -> editPolygony8 -> value();
            i += 2;
        }
        if(numPolygonPoints >= 9)
        {
            polygonDimensions[i] = ui -> editPolygonx9 -> value();
            polygonDimensions[i+1] = ui -> editPolygony9 -> value();
            i += 2;
        }
        if(numPolygonPoints == 10)
        {
            polygonDimensions[i] = ui -> editPolygonx10 -> value();
            polygonDimensions[i+1] = ui -> editPolygony10 -> value();
        }

        dim::specs *dims = polygonDimensions;
        int shapeId;
        QPen pen;
        QBrush brush;

        shapeId = (ui->editShapeID->currentText()).toInt();

        pen.setColor(QColor(ui -> editPolygonPenColor->currentText()));
        pen.setWidth(ui -> editPolygonPenWidth -> value());
        pen.setStyle(convertToPenStyle((ui -> editPolygonPenStyle -> currentText()).toStdString()));
        pen.setCapStyle(convertToPenCapStyle((ui -> editPolygonCapStyle -> currentText()).toStdString()));
        pen.setJoinStyle(convertToPenJoinStyle((ui -> editPolygonJoinStyle -> currentText()).toStdString()));

        brush.setColor(QColor(ui -> editPolygonBrushColor -> currentText()));
        brush.setStyle(convertToBrushStyle((ui -> editPolygonBrushStyle -> currentText().toStdString())));

        allShapes.editShape(shapeId, numPolygonSpecs, dims, pen, brush);

        QMessageBox::information(this, "Edit Successful", "Polygon Updated\nChanges are now visible", QMessageBox::Ok);
        setCurrentShapeInfo();
    }
    catch(int)
    {
        QMessageBox::warning(this, "Invalid Number of Points", "Please choose a valid number of points (between 1 and 10)", QMessageBox::Ok);
        ui->editPolygonNumPoints->setCurrentIndex(0);
    }
}

void MainWindow::on_editPolygonCancel_clicked()
{
    setCurrentShapeInfo();
}

void MainWindow::on_rectangleSave_clicked()
{
    dim::specs rectangleDimensions[NUM_RECTANGLE_SPECS];
    rectangleDimensions[int(Rectangle::Specifications::X1)] = ui -> addRectanglex1 -> value();
    rectangleDimensions[int(Rectangle::Specifications::Y1)] = ui -> addRectangley1 -> value();
    rectangleDimensions[int(Rectangle::Specifications::W)] = ui -> addRectanglew -> value();
    rectangleDimensions[int(Rectangle::Specifications::H)] = ui -> addRectangleh -> value();

    dim::specs *dims = rectangleDimensions;

    Shape* p_Shape = new class::Rectangle(allShapes.incrementShapeCount(), SHAPES_LIST[RECTANGLE], NUM_RECTANGLE_SPECS, dims);
    QPen pen;
    QBrush brush;

    pen.setColor(QColor(ui -> addRectanglePenColor->currentText()));
    pen.setWidth(ui -> addRectanglePenWidth -> value());
    pen.setStyle(convertToPenStyle((ui -> addRectanglePenStyle -> currentText()).toStdString()));
    pen.setCapStyle(convertToPenCapStyle((ui -> addRectangleCapStyle -> currentText()).toStdString()));
    pen.setJoinStyle(convertToPenJoinStyle((ui -> addRectangleJoinStyle -> currentText()).toStdString()));

    brush.setColor(QColor(ui -> addRectangleBrushColor -> currentText()));
    brush.setStyle(convertToBrushStyle((ui -> addRectangleBrushStyle -> currentText().toStdString())));

    p_Shape -> setPen(pen);
    p_Shape -> setBrush(brush);
    allShapes.newShape(p_Shape);

    QMessageBox::information(this, "Save Successful", "New Rectangle Added\nClick Update to View Changes", QMessageBox::Ok);
    clearAddRectangle();
}

void MainWindow::on_rectangleCancel_clicked()
{
    clearAddRectangle();
}

void MainWindow::on_editRectangleSave_clicked()
{
    dim::specs rectangleDimensions[NUM_RECTANGLE_SPECS];
    rectangleDimensions[int(Rectangle::Specifications::X1)] = ui -> editRectanglex1 -> value();
    rectangleDimensions[int(Rectangle::Specifications::Y1)] = ui -> editRectangley1 -> value();
    rectangleDimensions[int(Rectangle::Specifications::W)] = ui -> editRectanglew -> value();
    rectangleDimensions[int(Rectangle::Specifications::H)] = ui -> editRectangleh -> value();

    dim::specs *dims = rectangleDimensions;
    int shapeId;
    QPen pen;
    QBrush brush;

    shapeId = (ui->editShapeID->currentText()).toInt();

    pen.setColor(QColor(ui -> editRectanglePenColor->currentText()));
    pen.setWidth(ui -> editRectanglePenWidth -> value());
    pen.setStyle(convertToPenStyle((ui -> editRectanglePenStyle -> currentText()).toStdString()));
    pen.setCapStyle(convertToPenCapStyle((ui -> editRectangleCapStyle -> currentText()).toStdString()));
    pen.setJoinStyle(convertToPenJoinStyle((ui -> editRectangleJoinStyle -> currentText()).toStdString()));

    brush.setColor(QColor(ui -> editRectangleBrushColor -> currentText()));
    brush.setStyle(convertToBrushStyle((ui -> editRectangleBrushStyle -> currentText().toStdString())));

    allShapes.editShape(shapeId, NUM_RECTANGLE_SPECS, dims, pen, brush);
    QMessageBox::information(this, "Edit Successful", "Rectangle Updated\nChanges are now visible", QMessageBox::Ok);

    setCurrentShapeInfo();
}

void MainWindow::on_editRectangleCancel_clicked()
{
    setCurrentShapeInfo();
}

void MainWindow::on_squareSave_clicked()
{
    dim::specs squareDimensions[NUM_SQUARE_SPECS];
    squareDimensions[int(Square::Specifications::X1)] = ui -> addSquarex1 -> value();
    squareDimensions[int(Square::Specifications::Y1)] = ui -> addSquarey1 -> value();
    squareDimensions[int(Square::Specifications::L)] = ui -> addSquarel -> value();

    dim::specs *dims = squareDimensions;

    Shape* p_Shape = new class::Square(allShapes.incrementShapeCount(), SHAPES_LIST[SQUARE], NUM_SQUARE_SPECS, dims);
    QPen pen;
    QBrush brush;

    pen.setColor(QColor(ui -> addSquarePenColor->currentText()));
    pen.setWidth(ui -> addSquarePenWidth -> value());
    pen.setStyle(convertToPenStyle((ui -> addSquarePenStyle -> currentText()).toStdString()));
    pen.setCapStyle(convertToPenCapStyle((ui -> addSquareCapStyle -> currentText()).toStdString()));
    pen.setJoinStyle(convertToPenJoinStyle((ui -> addSquareJoinStyle -> currentText()).toStdString()));

    brush.setColor(QColor(ui -> addSquareBrushColor -> currentText()));
    brush.setStyle(convertToBrushStyle((ui -> addSquareBrushStyle -> currentText().toStdString())));

    p_Shape -> setPen(pen);
    p_Shape -> setBrush(brush);
    allShapes.newShape(p_Shape);

    QMessageBox::information(this, "Save Successful", "New Square Added\nClick Update to View Changes", QMessageBox::Ok);
    clearAddSquare();
}

void MainWindow::on_squareCancel_clicked()
{
    clearAddSquare();
}

void MainWindow::on_editSquareSave_clicked()
{
    dim::specs squareDimensions[NUM_SQUARE_SPECS];
    squareDimensions[int(Square::Specifications::X1)] = ui -> editSquarex1 -> value();
    squareDimensions[int(Square::Specifications::Y1)] = ui -> editSquarey1 -> value();
    squareDimensions[int(Square::Specifications::L)] = ui -> editSquarel -> value();

    dim::specs *dims = squareDimensions;
    int shapeId;
    QPen pen;
    QBrush brush;

    shapeId = (ui->editShapeID->currentText()).toInt();

    pen.setColor(QColor(ui -> editSquarePenColor->currentText()));
    pen.setWidth(ui -> editSquarePenWidth -> value());
    pen.setStyle(convertToPenStyle((ui -> editSquarePenStyle -> currentText()).toStdString()));
    pen.setCapStyle(convertToPenCapStyle((ui -> editSquareCapStyle -> currentText()).toStdString()));
    pen.setJoinStyle(convertToPenJoinStyle((ui -> editSquareJoinStyle -> currentText()).toStdString()));

    brush.setColor(QColor(ui -> editSquareBrushColor -> currentText()));
    brush.setStyle(convertToBrushStyle((ui -> editSquareBrushStyle -> currentText().toStdString())));

    allShapes.editShape(shapeId, NUM_SQUARE_SPECS, dims, pen, brush);

    QMessageBox::information(this, "Edit Successful", "Square Updated\nChanges are now visible", QMessageBox::Ok);
    setCurrentShapeInfo();
}

void MainWindow::on_editSquareCancel_clicked()
{
    setCurrentShapeInfo();
}

void MainWindow::on_ellipseSave_clicked()
{
    dim::specs ellipseDimensions[NUM_ELLIPSE_SPECS];
    ellipseDimensions[int(Ellipse::Specifications::X1)] = ui -> addEllipsex1 -> value();
    ellipseDimensions[int(Ellipse::Specifications::Y1)] = ui -> addEllipsey1 -> value();
    ellipseDimensions[int(Ellipse::Specifications::A)] = ui -> addEllipsea -> value();
    ellipseDimensions[int(Ellipse::Specifications::B)] = ui -> addEllipseb -> value();

    dim::specs *dims = ellipseDimensions;

    Shape* p_Shape = new class::Ellipse(allShapes.incrementShapeCount(), SHAPES_LIST[ELLIPSE], NUM_ELLIPSE_SPECS, dims);
    QPen pen;
    QBrush brush;

    pen.setColor(QColor(ui -> addEllipsePenColor->currentText()));
    pen.setWidth(ui -> addEllipsePenWidth -> value());
    pen.setStyle(convertToPenStyle((ui -> addEllipsePenStyle -> currentText()).toStdString()));
    pen.setCapStyle(convertToPenCapStyle((ui -> addEllipseCapStyle -> currentText()).toStdString()));
    pen.setJoinStyle(convertToPenJoinStyle((ui -> addEllipseJoinStyle -> currentText()).toStdString()));

    brush.setColor(QColor(ui -> addEllipseBrushColor -> currentText()));
    brush.setStyle(convertToBrushStyle((ui -> addEllipseBrushStyle -> currentText().toStdString())));

    p_Shape -> setPen(pen);
    p_Shape -> setBrush(brush);
    allShapes.newShape(p_Shape);

    QMessageBox::information(this, "Save Successful", "New Ellipse Added\nClick Update to View Changes", QMessageBox::Ok);
    clearAddEllipse();
}

void MainWindow::on_ellipseCancel_clicked()
{
    clearAddEllipse();
}

void MainWindow::on_editEllipseSave_clicked()
{
    dim::specs ellipseDimensions[NUM_ELLIPSE_SPECS];
    ellipseDimensions[int(Ellipse::Specifications::X1)] = ui -> editEllipsex1 -> value();
    ellipseDimensions[int(Ellipse::Specifications::Y1)] = ui -> editEllipsey1 -> value();
    ellipseDimensions[int(Ellipse::Specifications::A)] = ui -> editEllipsea -> value();
    ellipseDimensions[int(Ellipse::Specifications::B)] = ui -> editEllipseb -> value();

    dim::specs *dims = ellipseDimensions;

    int shapeId;
    QPen pen;
    QBrush brush;

    shapeId = (ui->editShapeID->currentText()).toInt();

    pen.setColor(QColor(ui -> editEllipsePenColor->currentText()));
    pen.setWidth(ui -> editEllipsePenWidth -> value());
    pen.setStyle(convertToPenStyle((ui -> editEllipsePenStyle -> currentText()).toStdString()));
    pen.setCapStyle(convertToPenCapStyle((ui -> editEllipseCapStyle -> currentText()).toStdString()));
    pen.setJoinStyle(convertToPenJoinStyle((ui -> editEllipseJoinStyle -> currentText()).toStdString()));

    brush.setColor(QColor(ui -> editEllipseBrushColor -> currentText()));
    brush.setStyle(convertToBrushStyle((ui -> editEllipseBrushStyle -> currentText().toStdString())));

    allShapes.editShape(shapeId, NUM_ELLIPSE_SPECS, dims, pen, brush);

    QMessageBox::information(this, "Edit Successful", "Ellipse Updated\nChanges are now visible", QMessageBox::Ok);
    setCurrentShapeInfo();
}

void MainWindow::on_editEllipseCancel_clicked()
{
    setCurrentShapeInfo();
}

void MainWindow::on_circleSave_clicked()
{
    dim::specs circleDimensions[NUM_CIRCLE_SPECS];
    circleDimensions[int(Circle::Specifications::X1)] = ui -> addCirclex1 -> value();
    circleDimensions[int(Circle::Specifications::Y1)] = ui -> addCircley1 -> value();
    circleDimensions[int(Circle::Specifications::RADIUS)] = ui -> addCircler -> value();

    dim::specs *dims = circleDimensions;

    Shape* p_Shape = new class::Circle(allShapes.incrementShapeCount(), SHAPES_LIST[CIRCLE], NUM_CIRCLE_SPECS, dims);
    QPen pen;
    QBrush brush;

    pen.setColor(QColor(ui -> addCirclePenColor->currentText()));
    pen.setWidth(ui -> addCirclePenWidth -> value());
    pen.setStyle(convertToPenStyle((ui -> addCirclePenStyle -> currentText()).toStdString()));
    pen.setCapStyle(convertToPenCapStyle((ui -> addCircleCapStyle -> currentText()).toStdString()));
    pen.setJoinStyle(convertToPenJoinStyle((ui -> addCircleJoinStyle -> currentText()).toStdString()));

    brush.setColor(QColor(ui -> addCircleBrushColor -> currentText()));
    brush.setStyle(convertToBrushStyle((ui -> addCircleBrushStyle -> currentText().toStdString())));

    p_Shape -> setPen(pen);
    p_Shape -> setBrush(brush);
    allShapes.newShape(p_Shape);

    QMessageBox::information(this, "Save Successful", "New Circle Added\nClick Update to View Changes", QMessageBox::Ok);
    clearAddCircle();
}

void MainWindow::on_circleCancel_clicked()
{
    clearAddCircle();
}

void MainWindow::on_editCircleSave_clicked()
{
    dim::specs circleDimensions[NUM_CIRCLE_SPECS];
    circleDimensions[int(Circle::Specifications::X1)] = ui -> editCirclex1 -> value();
    circleDimensions[int(Circle::Specifications::Y1)] = ui -> editCircley1 -> value();
    circleDimensions[int(Circle::Specifications::RADIUS)] = ui -> editCircler -> value();

    dim::specs *dims = circleDimensions;

    int shapeId;
    QPen pen;
    QBrush brush;

    shapeId = (ui->editShapeID->currentText()).toInt();

    pen.setColor(QColor(ui -> editCirclePenColor->currentText()));
    pen.setWidth(ui -> editCirclePenWidth -> value());
    pen.setStyle(convertToPenStyle((ui -> editCirclePenStyle -> currentText()).toStdString()));
    pen.setCapStyle(convertToPenCapStyle((ui -> editCircleCapStyle -> currentText()).toStdString()));
    pen.setJoinStyle(convertToPenJoinStyle((ui -> editCircleJoinStyle -> currentText()).toStdString()));

    brush.setColor(QColor(ui -> editCircleBrushColor -> currentText()));
    brush.setStyle(convertToBrushStyle((ui -> editCircleBrushStyle -> currentText().toStdString())));

    allShapes.editShape(shapeId, NUM_CIRCLE_SPECS, dims, pen, brush);

    QMessageBox::information(this, "Edit Successful", "Circle Updated\nChanges are now visible", QMessageBox::Ok);
    setCurrentShapeInfo();
}

void MainWindow::on_editCircleCancel_clicked()
{
    setCurrentShapeInfo();
}

void MainWindow::on_textSave_clicked()
{
    dim::specs textDimensions[NUM_TEXT_SPECS];
    textDimensions[int(Text::Specifications::X1)] = ui -> addTextx1 -> value();
    textDimensions[int(Text::Specifications::Y1)] = ui -> addTexty1 -> value();
    textDimensions[int(Text::Specifications::W)] = ui -> addTextw -> value();
    textDimensions[int(Text::Specifications::H)] = ui -> addTexth -> value();

    dim::specs *dims = textDimensions;

    QPen pen;
    QFont font;
    Qt::AlignmentFlag alignFlag = convertToAlignmentFlag((ui -> addTextAlignment -> currentText()).toStdString());
    std::string newText = (ui -> addTexttext -> text()).toStdString();

    pen.setColor(QColor(ui -> addTextColor -> currentText()));

    font.setPointSize(ui -> addTextSize -> value());
    font.setFamily(ui -> addTextFontFamily -> currentText());
    font.setWeight(convertToQFontWeight((ui -> addTextFontWeight -> currentText()).toStdString()));
    font.setStyle(convertToQFontStyle((ui -> addTextFontStyle -> currentText()).toStdString()));

    Shape* p_Shape = new class::Text(allShapes.incrementShapeCount(), SHAPES_LIST[TEXT], NUM_TEXT_SPECS, dims, font, newText, alignFlag);

    p_Shape -> setPen(pen);
    allShapes.newShape(p_Shape);

    QMessageBox::information(this, "Save Successful", "New Text Added\nClick Update to View Changes", QMessageBox::Ok);
    clearAddText();
}

void MainWindow::on_textCancel_clicked()
{
    clearAddText();
}

void MainWindow::on_editTextSave_clicked()
{
    dim::specs textDimensions[NUM_TEXT_SPECS];
    textDimensions[int(Text::Specifications::X1)] = ui -> editTextx1 -> value();
    textDimensions[int(Text::Specifications::Y1)] = ui -> editTexty1 -> value();
    textDimensions[int(Text::Specifications::W)] = ui -> editTextw -> value();
    textDimensions[int(Text::Specifications::H)] = ui -> editTexth -> value();

    dim::specs *dims = textDimensions;

    int shapeId;
    QPen pen;
    QFont font;

    shapeId = (ui->editShapeID->currentText()).toInt();
    Qt::AlignmentFlag alignFlag = convertToAlignmentFlag((ui -> editTextAlignment -> currentText()).toStdString());
    std::string newText = (ui -> editTexttext -> text()).toStdString();

    pen.setColor(QColor(ui -> editTextColor -> currentText()));

    font.setPointSize(ui -> editTextSize -> value());
    font.setFamily(ui -> editTextFontFamily -> currentText());
    font.setWeight(convertToQFontWeight((ui -> editTextFontWeight -> currentText()).toStdString()));
    font.setStyle(convertToQFontStyle((ui -> editTextFontStyle -> currentText()).toStdString()));

    allShapes.editShape(shapeId, NUM_TEXT_SPECS, dims, pen, font, alignFlag, newText);

    QMessageBox::information(this, "Edit Successful", "Text Updated\nChanges are now visible", QMessageBox::Ok);
    setCurrentShapeInfo();
}

void MainWindow::on_editTextCancel_clicked()
{
    setCurrentShapeInfo();
}

void MainWindow::on_updateButton_clicked()
{
    ui -> renderArea -> getShapes(allShapes.getVector());
    ui -> editShapeID -> clear();
    ui -> deleteShapeID -> clear();
    ui -> editShapeID -> addItems(set_getShapeIds());
    ui -> deleteShapeID -> addItems(set_getShapeIds());
    updateShapeTables();

    for(Shape *it : allShapes.getVector())
    {
        cout << it -> print();
        cout << endl;
    }

    ui -> addShapeType -> clearEditText();
}

void MainWindow::on_addPolylineNumPoints_currentIndexChanged(int index)
{
    disablePolylineSpinBoxes();

    switch(index)
    {
    case 0: break;
    case 1: ui -> addPolylinex1 -> setEnabled(true);
            ui -> addPolyliney1 -> setEnabled(true);
        break;
    case 2: ui -> addPolylinex1 -> setEnabled(true);
            ui -> addPolyliney1 -> setEnabled(true);
            ui -> addPolylinex2 -> setEnabled(true);
            ui -> addPolyliney2 -> setEnabled(true);
        break;
    case 3: ui -> addPolylinex1 -> setEnabled(true);
            ui -> addPolyliney1 -> setEnabled(true);
            ui -> addPolylinex2 -> setEnabled(true);
            ui -> addPolyliney2 -> setEnabled(true);
            ui -> addPolylinex3 -> setEnabled(true);
            ui -> addPolyliney3 -> setEnabled(true);
        break;
    case 4: ui -> addPolylinex1 -> setEnabled(true);
            ui -> addPolyliney1 -> setEnabled(true);
            ui -> addPolylinex2 -> setEnabled(true);
            ui -> addPolyliney2 -> setEnabled(true);
            ui -> addPolylinex3 -> setEnabled(true);
            ui -> addPolyliney3 -> setEnabled(true);
            ui -> addPolylinex4 -> setEnabled(true);
            ui -> addPolyliney4 -> setEnabled(true);
        break;
    case 5: ui -> addPolylinex1 -> setEnabled(true);
            ui -> addPolyliney1 -> setEnabled(true);
            ui -> addPolylinex2 -> setEnabled(true);
            ui -> addPolyliney2 -> setEnabled(true);
            ui -> addPolylinex3 -> setEnabled(true);
            ui -> addPolyliney3 -> setEnabled(true);
            ui -> addPolylinex4 -> setEnabled(true);
            ui -> addPolyliney4 -> setEnabled(true);
            ui -> addPolylinex5 -> setEnabled(true);
            ui -> addPolyliney5 -> setEnabled(true);
        break;
    case 6: ui -> addPolylinex1 -> setEnabled(true);
            ui -> addPolyliney1 -> setEnabled(true);
            ui -> addPolylinex2 -> setEnabled(true);
            ui -> addPolyliney2 -> setEnabled(true);
            ui -> addPolylinex3 -> setEnabled(true);
            ui -> addPolyliney3 -> setEnabled(true);
            ui -> addPolylinex4 -> setEnabled(true);
            ui -> addPolyliney4 -> setEnabled(true);
            ui -> addPolylinex5 -> setEnabled(true);
            ui -> addPolyliney5 -> setEnabled(true);
            ui -> addPolylinex6 -> setEnabled(true);
            ui -> addPolyliney6 -> setEnabled(true);
        break;
    case 7: ui -> addPolylinex1 -> setEnabled(true);
            ui -> addPolyliney1 -> setEnabled(true);
            ui -> addPolylinex2 -> setEnabled(true);
            ui -> addPolyliney2 -> setEnabled(true);
            ui -> addPolylinex3 -> setEnabled(true);
            ui -> addPolyliney3 -> setEnabled(true);
            ui -> addPolylinex4 -> setEnabled(true);
            ui -> addPolyliney4 -> setEnabled(true);
            ui -> addPolylinex5 -> setEnabled(true);
            ui -> addPolyliney5 -> setEnabled(true);
            ui -> addPolylinex6 -> setEnabled(true);
            ui -> addPolyliney6 -> setEnabled(true);
            ui -> addPolylinex7 -> setEnabled(true);
            ui -> addPolyliney7 -> setEnabled(true);
        break;
    case 8: ui -> addPolylinex1 -> setEnabled(true);
            ui -> addPolyliney1 -> setEnabled(true);
            ui -> addPolylinex2 -> setEnabled(true);
            ui -> addPolyliney2 -> setEnabled(true);
            ui -> addPolylinex3 -> setEnabled(true);
            ui -> addPolyliney3 -> setEnabled(true);
            ui -> addPolylinex4 -> setEnabled(true);
            ui -> addPolyliney4 -> setEnabled(true);
            ui -> addPolylinex5 -> setEnabled(true);
            ui -> addPolyliney5 -> setEnabled(true);
            ui -> addPolylinex6 -> setEnabled(true);
            ui -> addPolyliney6 -> setEnabled(true);
            ui -> addPolylinex7 -> setEnabled(true);
            ui -> addPolyliney7 -> setEnabled(true);
            ui -> addPolylinex8 -> setEnabled(true);
            ui -> addPolyliney8 -> setEnabled(true);
        break;
    case 9: ui -> addPolylinex1 -> setEnabled(true);
            ui -> addPolyliney1 -> setEnabled(true);
            ui -> addPolylinex2 -> setEnabled(true);
            ui -> addPolyliney2 -> setEnabled(true);
            ui -> addPolylinex3 -> setEnabled(true);
            ui -> addPolyliney3 -> setEnabled(true);
            ui -> addPolylinex4 -> setEnabled(true);
            ui -> addPolyliney4 -> setEnabled(true);
            ui -> addPolylinex5 -> setEnabled(true);
            ui -> addPolyliney5 -> setEnabled(true);
            ui -> addPolylinex6 -> setEnabled(true);
            ui -> addPolyliney6 -> setEnabled(true);
            ui -> addPolylinex7 -> setEnabled(true);
            ui -> addPolyliney7 -> setEnabled(true);
            ui -> addPolylinex8 -> setEnabled(true);
            ui -> addPolyliney8 -> setEnabled(true);
            ui -> addPolylinex9 -> setEnabled(true);
            ui -> addPolyliney9 -> setEnabled(true);
        break;
    case 10: ui -> addPolylinex1 -> setEnabled(true);
            ui -> addPolyliney1 -> setEnabled(true);
            ui -> addPolylinex2 -> setEnabled(true);
            ui -> addPolyliney2 -> setEnabled(true);
            ui -> addPolylinex3 -> setEnabled(true);
            ui -> addPolyliney3 -> setEnabled(true);
            ui -> addPolylinex4 -> setEnabled(true);
            ui -> addPolyliney4 -> setEnabled(true);
            ui -> addPolylinex5 -> setEnabled(true);
            ui -> addPolyliney5 -> setEnabled(true);
            ui -> addPolylinex6 -> setEnabled(true);
            ui -> addPolyliney6 -> setEnabled(true);
            ui -> addPolylinex7 -> setEnabled(true);
            ui -> addPolyliney7 -> setEnabled(true);
            ui -> addPolylinex8 -> setEnabled(true);
            ui -> addPolyliney8 -> setEnabled(true);
            ui -> addPolylinex9 -> setEnabled(true);
            ui -> addPolyliney9 -> setEnabled(true);
            ui -> addPolylinex10 -> setEnabled(true);
            ui -> addPolyliney10 -> setEnabled(true);
        break;
    }
}

void MainWindow::on_addPolygonNumPoints_currentIndexChanged(int index)
{
    disablePolygonSpinBoxes();

    switch(index)
    {
    case 0: break;
    case 1: ui -> addPolygonx1 -> setEnabled(true);
            ui -> addPolygony1 -> setEnabled(true);
        break;
    case 2: ui -> addPolygonx1 -> setEnabled(true);
            ui -> addPolygony1 -> setEnabled(true);
            ui -> addPolygonx2 -> setEnabled(true);
            ui -> addPolygony2 -> setEnabled(true);
        break;
    case 3: ui -> addPolygonx1 -> setEnabled(true);
            ui -> addPolygony1 -> setEnabled(true);
            ui -> addPolygonx2 -> setEnabled(true);
            ui -> addPolygony2 -> setEnabled(true);
            ui -> addPolygonx3 -> setEnabled(true);
            ui -> addPolygony3 -> setEnabled(true);
        break;
    case 4: ui -> addPolygonx1 -> setEnabled(true);
            ui -> addPolygony1 -> setEnabled(true);
            ui -> addPolygonx2 -> setEnabled(true);
            ui -> addPolygony2 -> setEnabled(true);
            ui -> addPolygonx3 -> setEnabled(true);
            ui -> addPolygony3 -> setEnabled(true);
            ui -> addPolygonx4 -> setEnabled(true);
            ui -> addPolygony4 -> setEnabled(true);
        break;
    case 5: ui -> addPolygonx1 -> setEnabled(true);
            ui -> addPolygony1 -> setEnabled(true);
            ui -> addPolygonx2 -> setEnabled(true);
            ui -> addPolygony2 -> setEnabled(true);
            ui -> addPolygonx3 -> setEnabled(true);
            ui -> addPolygony3 -> setEnabled(true);
            ui -> addPolygonx4 -> setEnabled(true);
            ui -> addPolygony4 -> setEnabled(true);
            ui -> addPolygonx5 -> setEnabled(true);
            ui -> addPolygony5 -> setEnabled(true);
        break;
    case 6: ui -> addPolygonx1 -> setEnabled(true);
            ui -> addPolygony1 -> setEnabled(true);
            ui -> addPolygonx2 -> setEnabled(true);
            ui -> addPolygony2 -> setEnabled(true);
            ui -> addPolygonx3 -> setEnabled(true);
            ui -> addPolygony3 -> setEnabled(true);
            ui -> addPolygonx4 -> setEnabled(true);
            ui -> addPolygony4 -> setEnabled(true);
            ui -> addPolygonx5 -> setEnabled(true);
            ui -> addPolygony5 -> setEnabled(true);
            ui -> addPolygonx6 -> setEnabled(true);
            ui -> addPolygony6 -> setEnabled(true);
        break;
    case 7: ui -> addPolygonx1 -> setEnabled(true);
            ui -> addPolygony1 -> setEnabled(true);
            ui -> addPolygonx2 -> setEnabled(true);
            ui -> addPolygony2 -> setEnabled(true);
            ui -> addPolygonx3 -> setEnabled(true);
            ui -> addPolygony3 -> setEnabled(true);
            ui -> addPolygonx4 -> setEnabled(true);
            ui -> addPolygony4 -> setEnabled(true);
            ui -> addPolygonx5 -> setEnabled(true);
            ui -> addPolygony5 -> setEnabled(true);
            ui -> addPolygonx6 -> setEnabled(true);
            ui -> addPolygony6 -> setEnabled(true);
            ui -> addPolygonx7 -> setEnabled(true);
            ui -> addPolygony7 -> setEnabled(true);
        break;
    case 8: ui -> addPolygonx1 -> setEnabled(true);
            ui -> addPolygony1 -> setEnabled(true);
            ui -> addPolygonx2 -> setEnabled(true);
            ui -> addPolygony2 -> setEnabled(true);
            ui -> addPolygonx3 -> setEnabled(true);
            ui -> addPolygony3 -> setEnabled(true);
            ui -> addPolygonx4 -> setEnabled(true);
            ui -> addPolygony4 -> setEnabled(true);
            ui -> addPolygonx5 -> setEnabled(true);
            ui -> addPolygony5 -> setEnabled(true);
            ui -> addPolygonx6 -> setEnabled(true);
            ui -> addPolygony6 -> setEnabled(true);
            ui -> addPolygonx7 -> setEnabled(true);
            ui -> addPolygony7 -> setEnabled(true);
            ui -> addPolygonx8 -> setEnabled(true);
            ui -> addPolygony8 -> setEnabled(true);
        break;
    case 9: ui -> addPolygonx1 -> setEnabled(true);
            ui -> addPolygony1 -> setEnabled(true);
            ui -> addPolygonx2 -> setEnabled(true);
            ui -> addPolygony2 -> setEnabled(true);
            ui -> addPolygonx3 -> setEnabled(true);
            ui -> addPolygony3 -> setEnabled(true);
            ui -> addPolygonx4 -> setEnabled(true);
            ui -> addPolygony4 -> setEnabled(true);
            ui -> addPolygonx5 -> setEnabled(true);
            ui -> addPolygony5 -> setEnabled(true);
            ui -> addPolygonx6 -> setEnabled(true);
            ui -> addPolygony6 -> setEnabled(true);
            ui -> addPolygonx7 -> setEnabled(true);
            ui -> addPolygony7 -> setEnabled(true);
            ui -> addPolygonx8 -> setEnabled(true);
            ui -> addPolygony8 -> setEnabled(true);
            ui -> addPolygonx9 -> setEnabled(true);
            ui -> addPolygony9 -> setEnabled(true);
        break;
    case 10: ui -> addPolygonx1 -> setEnabled(true);
            ui -> addPolygony1 -> setEnabled(true);
            ui -> addPolygonx2 -> setEnabled(true);
            ui -> addPolygony2 -> setEnabled(true);
            ui -> addPolygonx3 -> setEnabled(true);
            ui -> addPolygony3 -> setEnabled(true);
            ui -> addPolygonx4 -> setEnabled(true);
            ui -> addPolygony4 -> setEnabled(true);
            ui -> addPolygonx5 -> setEnabled(true);
            ui -> addPolygony5 -> setEnabled(true);
            ui -> addPolygonx6 -> setEnabled(true);
            ui -> addPolygony6 -> setEnabled(true);
            ui -> addPolygonx7 -> setEnabled(true);
            ui -> addPolygony7 -> setEnabled(true);
            ui -> addPolygonx8 -> setEnabled(true);
            ui -> addPolygony8 -> setEnabled(true);
            ui -> addPolygonx9 -> setEnabled(true);
            ui -> addPolygony9 -> setEnabled(true);
            ui -> addPolygonx10 -> setEnabled(true);
            ui -> addPolygony10 -> setEnabled(true);
        break;
    }
}

void MainWindow::on_tabs_currentChanged(int index)
{
    clearAdd();

    if(index == 0)
        ui -> adminAdd -> show();
    else if(index == 1)
        ui -> adminEdit -> show();
    else if(index == 2)
        ui -> adminDelete -> show();

}

void MainWindow::on_moveButton_clicked()
{
    ui -> xShiftBox -> setEnabled(true);
    ui -> yShiftBox -> setEnabled(true);
    ui -> editShapeSpecs -> hide();
}

void MainWindow::on_editButton_clicked()
{
    setCurrentShapeInfo();
    ui -> xShiftBox -> setEnabled(false);
    ui -> yShiftBox -> setEnabled(false);
    ui -> editShapeSpecs -> show();

}

void MainWindow::on_editShapeID_currentTextChanged(const QString &arg1)
{
    if(ui->editShapeID->count() != 0)
    {
        setCurrentShapeInfo();
    }

    if(allShapes.findShape((arg1).toInt()) == "Line"){
        ui -> editLine -> show();
        ui -> editPolygon -> hide();
        ui -> editPolyline -> hide();
        ui -> editRectangle -> hide();
        ui -> editSquare -> hide();
        ui -> editEllipse -> hide();
        ui -> editCircle -> hide();
        ui -> editText -> hide();}
    else if(allShapes.findShape((arg1).toInt()) == "Polyline"){
        ui -> editPolyline -> show();
        disableEditPolylineSpinBoxes();
        ui -> editPolygon -> hide();
        ui -> editLine -> hide();
        ui -> editRectangle -> hide();
        ui -> editSquare -> hide();
        ui -> editEllipse -> hide();
        ui -> editCircle -> hide();
        ui -> editText -> hide();}
    else if(allShapes.findShape((arg1).toInt()) == "Polygon"){
        ui -> editPolygon -> show();
        disableEditPolygonSpinBoxes();
        ui -> editLine -> hide();
        ui -> editPolyline -> hide();
        ui -> editRectangle -> hide();
        ui -> editSquare -> hide();
        ui -> editEllipse -> hide();
        ui -> editCircle -> hide();
        ui -> editText -> hide();}
    else if(allShapes.findShape((arg1).toInt()) == "Rectangle"){
        ui -> editRectangle -> show();
        ui -> editPolygon -> hide();
        ui -> editPolyline -> hide();
        ui -> editLine -> hide();
        ui -> editSquare -> hide();
        ui -> editEllipse -> hide();
        ui -> editCircle -> hide();
        ui -> editText -> hide();}
    else if(allShapes.findShape((arg1).toInt()) == "Square"){
        ui -> editSquare -> show();
        ui -> editLine -> hide();
        ui -> editPolyline -> hide();
        ui -> editRectangle -> hide();
        ui -> editPolygon -> hide();
        ui -> editEllipse -> hide();
        ui -> editCircle -> hide();
        ui -> editText -> hide();}
    else if(allShapes.findShape((arg1).toInt()) == "Ellipse"){
        ui -> editEllipse -> show();
        ui -> editPolygon -> hide();
        ui -> editPolyline -> hide();
        ui -> editRectangle -> hide();
        ui -> editSquare -> hide();
        ui -> editLine -> hide();
        ui -> editCircle -> hide();
        ui -> editText -> hide();}
    else if(allShapes.findShape((arg1).toInt()) == "Circle"){
        ui -> editCircle -> show();
        ui -> editPolygon -> hide();
        ui -> editPolyline -> hide();
        ui -> editRectangle -> hide();
        ui -> editSquare -> hide();
        ui -> editEllipse -> hide();
        ui -> editLine -> hide();
        ui -> editText -> hide();}
    else if(allShapes.findShape((arg1).toInt()) == "Text"){
        ui -> editText -> show();
        ui -> editPolygon -> hide();
        ui -> editPolyline -> hide();
        ui -> editRectangle -> hide();
        ui -> editSquare -> hide();
        ui -> editEllipse -> hide();
        ui -> editCircle -> hide();
        ui -> editLine -> hide();}
}

void MainWindow::on_editPolygonNumPoints_currentIndexChanged(int index)
{
    disableEditPolygonSpinBoxes();

    switch(index)
    {
    case 0: break;
    case 1: ui -> editPolygonx1 -> setEnabled(true);
            ui -> editPolygony1 -> setEnabled(true);
        break;
    case 2: ui -> editPolygonx1 -> setEnabled(true);
            ui -> editPolygony1 -> setEnabled(true);
            ui -> editPolygonx2 -> setEnabled(true);
            ui -> editPolygony2 -> setEnabled(true);
        break;
    case 3: ui -> editPolygonx1 -> setEnabled(true);
            ui -> editPolygony1 -> setEnabled(true);
            ui -> editPolygonx2 -> setEnabled(true);
            ui -> editPolygony2 -> setEnabled(true);
            ui -> editPolygonx3 -> setEnabled(true);
            ui -> editPolygony3 -> setEnabled(true);
        break;
    case 4: ui -> editPolygonx1 -> setEnabled(true);
            ui -> editPolygony1 -> setEnabled(true);
            ui -> editPolygonx2 -> setEnabled(true);
            ui -> editPolygony2 -> setEnabled(true);
            ui -> editPolygonx3 -> setEnabled(true);
            ui -> editPolygony3 -> setEnabled(true);
            ui -> editPolygonx4 -> setEnabled(true);
            ui -> editPolygony4 -> setEnabled(true);
        break;
    case 5: ui -> editPolygonx1 -> setEnabled(true);
            ui -> editPolygony1 -> setEnabled(true);
            ui -> editPolygonx2 -> setEnabled(true);
            ui -> editPolygony2 -> setEnabled(true);
            ui -> editPolygonx3 -> setEnabled(true);
            ui -> editPolygony3 -> setEnabled(true);
            ui -> editPolygonx4 -> setEnabled(true);
            ui -> editPolygony4 -> setEnabled(true);
            ui -> editPolygonx5 -> setEnabled(true);
            ui -> editPolygony5 -> setEnabled(true);
        break;
    case 6: ui -> editPolygonx1 -> setEnabled(true);
            ui -> editPolygony1 -> setEnabled(true);
            ui -> editPolygonx2 -> setEnabled(true);
            ui -> editPolygony2 -> setEnabled(true);
            ui -> editPolygonx3 -> setEnabled(true);
            ui -> editPolygony3 -> setEnabled(true);
            ui -> editPolygonx4 -> setEnabled(true);
            ui -> editPolygony4 -> setEnabled(true);
            ui -> editPolygonx5 -> setEnabled(true);
            ui -> editPolygony5 -> setEnabled(true);
            ui -> editPolygonx6 -> setEnabled(true);
            ui -> editPolygony6 -> setEnabled(true);
        break;
    case 7: ui -> editPolygonx1 -> setEnabled(true);
            ui -> editPolygony1 -> setEnabled(true);
            ui -> editPolygonx2 -> setEnabled(true);
            ui -> editPolygony2 -> setEnabled(true);
            ui -> editPolygonx3 -> setEnabled(true);
            ui -> editPolygony3 -> setEnabled(true);
            ui -> editPolygonx4 -> setEnabled(true);
            ui -> editPolygony4 -> setEnabled(true);
            ui -> editPolygonx5 -> setEnabled(true);
            ui -> editPolygony5 -> setEnabled(true);
            ui -> editPolygonx6 -> setEnabled(true);
            ui -> editPolygony6 -> setEnabled(true);
            ui -> editPolygonx7 -> setEnabled(true);
            ui -> editPolygony7 -> setEnabled(true);
        break;
    case 8: ui -> editPolygonx1 -> setEnabled(true);
            ui -> editPolygony1 -> setEnabled(true);
            ui -> editPolygonx2 -> setEnabled(true);
            ui -> editPolygony2 -> setEnabled(true);
            ui -> editPolygonx3 -> setEnabled(true);
            ui -> editPolygony3 -> setEnabled(true);
            ui -> editPolygonx4 -> setEnabled(true);
            ui -> editPolygony4 -> setEnabled(true);
            ui -> editPolygonx5 -> setEnabled(true);
            ui -> editPolygony5 -> setEnabled(true);
            ui -> editPolygonx6 -> setEnabled(true);
            ui -> editPolygony6 -> setEnabled(true);
            ui -> editPolygonx7 -> setEnabled(true);
            ui -> editPolygony7 -> setEnabled(true);
            ui -> editPolygonx8 -> setEnabled(true);
            ui -> editPolygony8 -> setEnabled(true);
        break;
    case 9: ui -> editPolygonx1 -> setEnabled(true);
            ui -> editPolygony1 -> setEnabled(true);
            ui -> editPolygonx2 -> setEnabled(true);
            ui -> editPolygony2 -> setEnabled(true);
            ui -> editPolygonx3 -> setEnabled(true);
            ui -> editPolygony3 -> setEnabled(true);
            ui -> editPolygonx4 -> setEnabled(true);
            ui -> editPolygony4 -> setEnabled(true);
            ui -> editPolygonx5 -> setEnabled(true);
            ui -> editPolygony5 -> setEnabled(true);
            ui -> editPolygonx6 -> setEnabled(true);
            ui -> editPolygony6 -> setEnabled(true);
            ui -> editPolygonx7 -> setEnabled(true);
            ui -> editPolygony7 -> setEnabled(true);
            ui -> editPolygonx8 -> setEnabled(true);
            ui -> editPolygony8 -> setEnabled(true);
            ui -> editPolygonx9 -> setEnabled(true);
            ui -> editPolygony9 -> setEnabled(true);
        break;
    case 10: ui -> editPolygonx1 -> setEnabled(true);
            ui -> editPolygony1 -> setEnabled(true);
            ui -> editPolygonx2 -> setEnabled(true);
            ui -> editPolygony2 -> setEnabled(true);
            ui -> editPolygonx3 -> setEnabled(true);
            ui -> editPolygony3 -> setEnabled(true);
            ui -> editPolygonx4 -> setEnabled(true);
            ui -> editPolygony4 -> setEnabled(true);
            ui -> editPolygonx5 -> setEnabled(true);
            ui -> editPolygony5 -> setEnabled(true);
            ui -> editPolygonx6 -> setEnabled(true);
            ui -> editPolygony6 -> setEnabled(true);
            ui -> editPolygonx7 -> setEnabled(true);
            ui -> editPolygony7 -> setEnabled(true);
            ui -> editPolygonx8 -> setEnabled(true);
            ui -> editPolygony8 -> setEnabled(true);
            ui -> editPolygonx9 -> setEnabled(true);
            ui -> editPolygony9 -> setEnabled(true);
            ui -> editPolygonx10 -> setEnabled(true);
            ui -> editPolygony10 -> setEnabled(true);
        break;
    }
}

void MainWindow::on_editPolylineNumPoints_currentIndexChanged(int index)
{
    disableEditPolylineSpinBoxes();

    switch(index)
    {
    case 0: break;
    case 1: ui -> editPolylinex1 -> setEnabled(true);
            ui -> editPolyliney1 -> setEnabled(true);
        break;
    case 2: ui -> editPolylinex1 -> setEnabled(true);
            ui -> editPolyliney1 -> setEnabled(true);
            ui -> editPolylinex2 -> setEnabled(true);
            ui -> editPolyliney2 -> setEnabled(true);
        break;
    case 3: ui -> editPolylinex1 -> setEnabled(true);
            ui -> editPolyliney1 -> setEnabled(true);
            ui -> editPolylinex2 -> setEnabled(true);
            ui -> editPolyliney2 -> setEnabled(true);
            ui -> editPolylinex3 -> setEnabled(true);
            ui -> editPolyliney3 -> setEnabled(true);
        break;
    case 4: ui -> editPolylinex1 -> setEnabled(true);
            ui -> editPolyliney1 -> setEnabled(true);
            ui -> editPolylinex2 -> setEnabled(true);
            ui -> editPolyliney2 -> setEnabled(true);
            ui -> editPolylinex3 -> setEnabled(true);
            ui -> editPolyliney3 -> setEnabled(true);
            ui -> editPolylinex4 -> setEnabled(true);
            ui -> editPolyliney4 -> setEnabled(true);
        break;
    case 5: ui -> editPolylinex1 -> setEnabled(true);
            ui -> editPolyliney1 -> setEnabled(true);
            ui -> editPolylinex2 -> setEnabled(true);
            ui -> editPolyliney2 -> setEnabled(true);
            ui -> editPolylinex3 -> setEnabled(true);
            ui -> editPolyliney3 -> setEnabled(true);
            ui -> editPolylinex4 -> setEnabled(true);
            ui -> editPolyliney4 -> setEnabled(true);
            ui -> editPolylinex5 -> setEnabled(true);
            ui -> editPolyliney5 -> setEnabled(true);
        break;
    case 6: ui -> editPolylinex1 -> setEnabled(true);
            ui -> editPolyliney1 -> setEnabled(true);
            ui -> editPolylinex2 -> setEnabled(true);
            ui -> editPolyliney2 -> setEnabled(true);
            ui -> editPolylinex3 -> setEnabled(true);
            ui -> editPolyliney3 -> setEnabled(true);
            ui -> editPolylinex4 -> setEnabled(true);
            ui -> editPolyliney4 -> setEnabled(true);
            ui -> editPolylinex5 -> setEnabled(true);
            ui -> editPolyliney5 -> setEnabled(true);
            ui -> editPolylinex6 -> setEnabled(true);
            ui -> editPolyliney6 -> setEnabled(true);
        break;
    case 7: ui -> editPolylinex1 -> setEnabled(true);
            ui -> editPolyliney1 -> setEnabled(true);
            ui -> editPolylinex2 -> setEnabled(true);
            ui -> editPolyliney2 -> setEnabled(true);
            ui -> editPolylinex3 -> setEnabled(true);
            ui -> editPolyliney3 -> setEnabled(true);
            ui -> editPolylinex4 -> setEnabled(true);
            ui -> editPolyliney4 -> setEnabled(true);
            ui -> editPolylinex5 -> setEnabled(true);
            ui -> editPolyliney5 -> setEnabled(true);
            ui -> editPolylinex6 -> setEnabled(true);
            ui -> editPolyliney6 -> setEnabled(true);
            ui -> editPolylinex7 -> setEnabled(true);
            ui -> editPolyliney7 -> setEnabled(true);
        break;
    case 8: ui -> editPolylinex1 -> setEnabled(true);
            ui -> editPolyliney1 -> setEnabled(true);
            ui -> editPolylinex2 -> setEnabled(true);
            ui -> editPolyliney2 -> setEnabled(true);
            ui -> editPolylinex3 -> setEnabled(true);
            ui -> editPolyliney3 -> setEnabled(true);
            ui -> editPolylinex4 -> setEnabled(true);
            ui -> editPolyliney4 -> setEnabled(true);
            ui -> editPolylinex5 -> setEnabled(true);
            ui -> editPolyliney5 -> setEnabled(true);
            ui -> editPolylinex6 -> setEnabled(true);
            ui -> editPolyliney6 -> setEnabled(true);
            ui -> editPolylinex7 -> setEnabled(true);
            ui -> editPolyliney7 -> setEnabled(true);
            ui -> editPolylinex8 -> setEnabled(true);
            ui -> editPolyliney8 -> setEnabled(true);
        break;
    case 9: ui -> editPolylinex1 -> setEnabled(true);
            ui -> editPolyliney1 -> setEnabled(true);
            ui -> editPolylinex2 -> setEnabled(true);
            ui -> editPolyliney2 -> setEnabled(true);
            ui -> editPolylinex3 -> setEnabled(true);
            ui -> editPolyliney3 -> setEnabled(true);
            ui -> editPolylinex4 -> setEnabled(true);
            ui -> editPolyliney4 -> setEnabled(true);
            ui -> editPolylinex5 -> setEnabled(true);
            ui -> editPolyliney5 -> setEnabled(true);
            ui -> editPolylinex6 -> setEnabled(true);
            ui -> editPolyliney6 -> setEnabled(true);
            ui -> editPolylinex7 -> setEnabled(true);
            ui -> editPolyliney7 -> setEnabled(true);
            ui -> editPolylinex8 -> setEnabled(true);
            ui -> editPolyliney8 -> setEnabled(true);
            ui -> editPolylinex9 -> setEnabled(true);
            ui -> editPolyliney9 -> setEnabled(true);
        break;
    case 10: ui -> editPolylinex1 -> setEnabled(true);
            ui -> editPolyliney1 -> setEnabled(true);
            ui -> editPolylinex2 -> setEnabled(true);
            ui -> editPolyliney2 -> setEnabled(true);
            ui -> editPolylinex3 -> setEnabled(true);
            ui -> editPolyliney3 -> setEnabled(true);
            ui -> editPolylinex4 -> setEnabled(true);
            ui -> editPolyliney4 -> setEnabled(true);
            ui -> editPolylinex5 -> setEnabled(true);
            ui -> editPolyliney5 -> setEnabled(true);
            ui -> editPolylinex6 -> setEnabled(true);
            ui -> editPolyliney6 -> setEnabled(true);
            ui -> editPolylinex7 -> setEnabled(true);
            ui -> editPolyliney7 -> setEnabled(true);
            ui -> editPolylinex8 -> setEnabled(true);
            ui -> editPolyliney8 -> setEnabled(true);
            ui -> editPolylinex9 -> setEnabled(true);
            ui -> editPolyliney9 -> setEnabled(true);
            ui -> editPolylinex10 -> setEnabled(true);
            ui -> editPolyliney10 -> setEnabled(true);
        break;
    }
}

void MainWindow::on_moveUpdateButton_clicked()
{
    int shapeId = (ui->editShapeID->currentText()).toInt();
    QPoint shift;

    shift.setX(ui->xShiftBox->value());
    shift.setY(ui->yShiftBox->value());

    allShapes.moveShape(shapeId, shift);

    ui -> renderArea -> getShapes(allShapes.getVector());

    ui->xShiftBox->setValue(0);
    ui->yShiftBox->setValue(0);
}

void MainWindow::on_deleteShapeButton_clicked()
{
    int shapeId = (ui->editShapeID->currentText()).toInt();

    if(QMessageBox::warning(this, "Delete Confirmation", "Are you sure you want to delete this shape?", QMessageBox::Yes, QMessageBox::No)
       == QMessageBox::Yes)
    {
        allShapes.deleteShape(shapeId);
        ui -> renderArea -> getShapes(allShapes.getVector());
        ui -> editShapeID -> clear();
        ui -> deleteShapeID -> clear();

        if(allShapes.getShapeCount() != 0)
        {
            ui -> editShapeID -> addItems(set_getShapeIds());
            setCurrentShapeInfo();
            ui -> deleteShapeID -> addItems(set_getShapeIds());
        }

        updateShapeTables();

    }
}

void MainWindow::on_sortTabs_tabBarClicked(int index)
{
    switch(index)
    {
    case 0: sortIDTable();
        break;
    case 1: sortPerimeterTable();
        break;
    case 2: sortAreaTable();
        break;
    }
}

void MainWindow::on_actionView_Contact_Info_triggered()
{
    ui->contactUs->show();
    ui->renderArea->hide();
    ui->tabs->hide();
}

void MainWindow::on_actionSave_Progress_triggered()
{
    if(QMessageBox::question(this, "Save Current Progress", "Would you like to save all current shapes?", QMessageBox::Yes, QMessageBox::No)
       == QMessageBox::Yes)
    {
        allShapes.printAll();
    }
}

void MainWindow::on_exitContactUsWindow_clicked()
{
    ui->contactUs->hide();
    ui->renderArea->show();
    ui->tabs->show();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox exitBox;
    exitBox.setIcon(QMessageBox::Question);
    exitBox.setWindowTitle("Exit Confirmation");
    exitBox.setText("The canvas has been modified.");
    exitBox.setInformativeText("Do you want to save your changes?");
    exitBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    exitBox.setDefaultButton(QMessageBox::Cancel);
    int ret = exitBox.exec();

    switch(ret)
    {
    case QMessageBox::Save: allShapes.printAll();
                            event->accept();
        break;
    case QMessageBox::Discard: event->accept();
        break;
    case QMessageBox::Cancel: event->ignore();
                              exitBox.close();
        break;
    }
}
