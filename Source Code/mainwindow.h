/*!
 * \brief   MainWindow Header File - Team Mittens USA
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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QGraphicsView>
#include <QCloseEvent>
#include "allshapes.h"
#include "qtconversions.h"
#include "selectionsort.h"

/*! Forward declaration of the Canvas class */
class Canvas;

/*! \namespace <Ui> Includes forward declaration of the MainWindow class */
namespace Ui {
class MainWindow;
}

using namespace ShapeLabels;

//! The class that manages the main window of the application.
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    //! Constructor
    explicit MainWindow(QWidget *parent = nullptr);

    //! Destructor
    ~MainWindow();

    //! Updates the shape tables with their sorted values.
    void updateShapeTables();

    //! Sorts the ID table.
    void sortIDTable();

    //! Sorts the perimeter table.
    void sortPerimeterTable();

    //! Sorts the area table.
    void sortAreaTable();

    //! Updates the combo box of shape ID's in the edit form.
    void updateEditShapeId();

    //! Disables all polyline spin boxes.
    void disablePolylineSpinBoxes();

    //! Disables all polygon spin boxes.
    void disablePolygonSpinBoxes();

    //! Clears the add line form.
    void clearAddLine();

    //! Clears the add polyline form.
    void clearAddPolyline();

    //! Clears the add polygon form.
    void clearAddPolygon();

    //! Clears the add rectangle form.
    void clearAddRectangle();

    //! Clears the add square form.
    void clearAddSquare();

    //! Clears the add ellipse form.
    void clearAddEllipse();

    //! Clears the add circle form.
    void clearAddCircle();

    //! Clears the add text form.
    void clearAddText();

    //! Clears all add shape forms.
    void clearAdd();

    //! Clears the edit line form.
    void clearEditLine();

    //! Clears the edit polyline form.
    void clearEditPolyline();

    //! Clears the edit polygon form.
    void clearEditPolygon();

    //! Clears the edit rectangle form.
    void clearEditRectangle();

    //! Clears the edit square form.
    void clearEditSquare();

    //! Clears the edit ellipse form.
    void clearEditEllipse();

    //! Clears the edit circle form.
    void clearEditCircle();

    //! Clears the edit text form.
    void clearEditText();

    //! Clears all edit forms.
    void clearEdit();

    //! Sets and gets all current Shape ID's to the appropriate combo boxes.
    QStringList set_getShapeIds();

    //! Sets the current shape information on the appropriate edit shape form.
    void setCurrentShapeInfo();

    //! Disables all edit polyline spin boxes.
    void disableEditPolylineSpinBoxes();

    //! Disables all edit polygon spin boxes.
    void disableEditPolygonSpinBoxes();

private slots:
    //! Overrides the close event when the red x at the top left of the application window is clicked.
    void closeEvent(QCloseEvent *event);

    //! Displays the appropriate add shape form depending on which type of shape is elected to be added.
    void on_addShapeType_currentIndexChanged(const QString &arg1);

    //! Adds a new line.
    void on_lineSave_clicked();

    //! Cancels addition of a line.
    void on_lineCancel_clicked();

    //! Edits an existing line.
    void on_editLineSave_clicked();

    //! Cancels edit of a line.
    void on_editLineCancel_clicked();

    //! Adds a new polyline.
    void on_polylineSave_clicked();

    //! Cancels addition of a polyline.
    void on_polylineCancel_clicked();

    //! Changes the number of enabled spin boxes in the add polyline form depending on the number of points the user chooses to have.
    void on_addPolylineNumPoints_currentIndexChanged(int index);

    //! Edits an existing polyline.
    void on_editPolylineSave_clicked();

    //! Cancels edit of a polyline.
    void on_editPolylineCancel_clicked();

    //! Changes the number of enabled spin boxes in the edit polyline form depending on the number of points the user chooses to have.
    void on_editPolylineNumPoints_currentIndexChanged(int index);

    //! Adds a new polygon.
    void on_polygonSave_clicked();

    //! Cancels addition of a polygon.
    void on_polygonCancel_clicked();

    //! Changes the number of enabled spin boxes in the add polygon form depending on the number of sides the user chooses to have.
    void on_addPolygonNumPoints_currentIndexChanged(int index);

    //! Edits an existing polygon.
    void on_editPolygonSave_clicked();

    //! Cancels edit of a polygon.
    void on_editPolygonCancel_clicked();

    //! Changes the number of enabled spin boxes in the edit polygon form depending on the number of sides the user chooses to have.
    void on_editPolygonNumPoints_currentIndexChanged(int index);

    //! Adds a new rectangle.
    void on_rectangleSave_clicked();

    //! Cancels addition of a rectangle.
    void on_rectangleCancel_clicked();

    //! Edits an existing rectangle.
    void on_editRectangleSave_clicked();

    //! Cancels edit of a rectangle.
    void on_editRectangleCancel_clicked();

    //! Adds a new square.
    void on_squareSave_clicked();

    //! Cancels addition of a square.
    void on_squareCancel_clicked();

    //! Edits an existing square.
    void on_editSquareSave_clicked();

    //! Cancels edit of a square.
    void on_editSquareCancel_clicked();

    //! Adds a new ellipse.
    void on_ellipseSave_clicked();

    //! Cancels addition of an ellipse.
    void on_ellipseCancel_clicked();

    //! Edits an existing ellipse.
    void on_editEllipseSave_clicked();

    //! Cancels edit of an ellipse.
    void on_editEllipseCancel_clicked();

    //! Adds a new circle.
    void on_circleSave_clicked();

    //! Cancels addition of a circle.
    void on_circleCancel_clicked();

    //! Edits an existing circle.
    void on_editCircleSave_clicked();

    //! Cancels edit of a circle.
    void on_editCircleCancel_clicked();

    //! Adds a new text box.
    void on_textSave_clicked();

    //! Cancels addition of a text box.
    void on_textCancel_clicked();

    //! Edits an existing text box.
    void on_editTextSave_clicked();

    //! Cancels edit of a text.
    void on_editTextCancel_clicked();

    //! Updates the rendering area after changing the vector.
    void on_updateButton_clicked();

    //! Changes the shape form that is visible when the user changes the current tab they are on.
    void on_tabs_currentChanged(int index);

    //! Enables the move shift spin boxes.
    void on_moveButton_clicked();

    //! Enables the edit form.
    void on_editButton_clicked();

    //! Moves the selected shape by a certain offset.
    void on_moveUpdateButton_clicked();

    //! Deletes a shape from the vector.
    void on_deleteShapeButton_clicked();

    //! Changes the specific shape form based on the shape ID the user chooses.
    void on_editShapeID_currentTextChanged(const QString &arg1);

    //! Sorts and displays the appropriate shape details.
    void on_sortTabs_tabBarClicked(int index);

    //! Opens the contact us window.
    void on_actionView_Contact_Info_triggered();

    //! Prints the current vector to the shape file.
    void on_actionSave_Progress_triggered();

    //! Exits the contact us window.
    void on_exitContactUsWindow_clicked();

    //! Logs out the user.
    void on_action_LogOut_triggered();

    //! Logs in the user.
    void on_pushButton_Login_clicked();

    //! Exits the program from the log in window.
    void on_pushButton_Exit_clicked();

private:
    Ui::MainWindow  *ui;    /*!< the pointer to the main window */
    AllShapes allShapes;    /*!< the object allowing access to the AllShapes controller class */
    int accessLevel;        /*!< the access level of the current user depending on their type (basic user, admin) */

    //! The enumeration representing the access levels of all user types.
    enum accessLevels {
                        USER,   /*!< access level of a basic user - add, edit, and delete are disabled */
                        ADMIN,  /*!< access level of an administrator - add, edit, and delete are enabled */
                        NONE    /*!< no specified access level (between logins) */
                      };

    //! The enumeration representing the column location in the sorted Shape tables. */
    enum column {
                    TYPE,       /*!< the shape type column */
                    ID,         /*!< the shape ID column */
                    PERIMETER,  /*!< the perimeter column */
                    AREA        /*!< the area column */
                };



};

#endif // MAINWINDOW_H
