#ifndef CANVAS_H
#define CANVAS_H

#include <QPen>
#include <QWidget>
#include "vector.h"
#include "shape.h"

class canvas : public QWidget
{
public:
    explicit canvas(QWidget *parent = nullptr);

    void getShapes(myVector::vector<Shape*> shapes);

public slots:

//    void setShape(const std::string shapeType);
//    void setPen(const QPen &inPen) {}
//    void setBrush(const QBrush &brush);
    void getShape(Shape* currentShape);
    void setPainter(QPainter &painter, std::string shapeType);

protected:

    void paintEvent(QPaintEvent *event) override;

private:
    myVector::vector<Shape *> v_Shapes;
};


#endif // CANVAS_H
