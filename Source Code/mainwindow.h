#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QGraphicsView>
#include <QCloseEvent>
#include "allshapes.h"
#include "qtconversions.h"
#include "selectionsort.h"

class Canvas;

// FORWARD DECLARATIONS
namespace Ui {
class MainWindow;
}

using namespace ShapeLabels;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateShapeTables();
    void sortIDTable();
    void sortPerimeterTable();
    void sortAreaTable();
    void updateEditShapeId();

    void disablePolylineSpinBoxes();
    void disablePolygonSpinBoxes();

    void clearAddLine();
    void clearAddPolyline();
    void clearAddPolygon();
    void clearAddRectangle();
    void clearAddSquare();
    void clearAddEllipse();
    void clearAddCircle();
    void clearAddText();
    void clearAdd();

    void clearEditLine();
    void clearEditPolyline();
    void clearEditPolygon();
    void clearEditRectangle();
    void clearEditSquare();
    void clearEditEllipse();
    void clearEditCircle();
    void clearEditText();
    void clearEdit();

    QStringList set_getShapeIds();

    void setCurrentShapeInfo();

    void disableEditPolylineSpinBoxes();
    void disableEditPolygonSpinBoxes();

private slots:
    void closeEvent(QCloseEvent *event);
    void on_addShapeType_currentIndexChanged(const QString &arg1);

    // LINE UPDATES
    void on_lineSave_clicked();
    void on_lineCancel_clicked();
    void on_editLineSave_clicked();
    void on_editLineCancel_clicked();

    // POLYLINE UPDATES
    void on_polylineSave_clicked();
    void on_polylineCancel_clicked();
    void on_addPolylineNumPoints_currentIndexChanged(int index);
    void on_editPolylineSave_clicked();
    void on_editPolylineCancel_clicked();
    void on_editPolylineNumPoints_currentIndexChanged(int index);

    // POLYGON UPDATES
    void on_polygonSave_clicked();
    void on_polygonCancel_clicked();
    void on_addPolygonNumPoints_currentIndexChanged(int index);
    void on_editPolygonSave_clicked();
    void on_editPolygonCancel_clicked();
    void on_editPolygonNumPoints_currentIndexChanged(int index);

    // RECTANGLE UPDATES
    void on_rectangleSave_clicked();
    void on_rectangleCancel_clicked();
    void on_editRectangleSave_clicked();
    void on_editRectangleCancel_clicked();

    // SQUARE UPDATES
    void on_squareSave_clicked();
    void on_squareCancel_clicked();
    void on_editSquareSave_clicked();
    void on_editSquareCancel_clicked();

    // ELLIPSE UPDATES
    void on_ellipseSave_clicked();
    void on_ellipseCancel_clicked();
    void on_editEllipseSave_clicked();
    void on_editEllipseCancel_clicked();

    // CIRCLE UPDATES
    void on_circleSave_clicked();
    void on_circleCancel_clicked();
    void on_editCircleSave_clicked();
    void on_editCircleCancel_clicked();

    // TEXT UPDATES
    void on_textSave_clicked();
    void on_textCancel_clicked();
    void on_editTextSave_clicked();
    void on_editTextCancel_clicked();

    void on_updateButton_clicked();

    void on_tabs_currentChanged(int index);

    void on_moveButton_clicked();

    void on_editButton_clicked();

//    void on_editShapeID_currentIndexChanged(int index);

    void on_moveUpdateButton_clicked();

    void on_deleteShapeButton_clicked();

    void on_editShapeID_currentTextChanged(const QString &arg1);

    void on_sortTabs_tabBarClicked(int index);


    void on_actionView_Contact_Info_triggered();

    void on_actionSave_Progress_triggered();

    void on_exitContactUsWindow_clicked();

private:
    Ui::MainWindow  *ui;
    AllShapes allShapes;
    enum column {TYPE, ID, PERIMETER, AREA};


};

#endif // MAINWINDOW_H
