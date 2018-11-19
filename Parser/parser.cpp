#include "parser.h"

void Parser::parseShapes(myVector::vector<Shape*> &v_shapes)
{
    using std::string;

    std::fstream datafile("shapes.txt", std::ios::in);
    string line;

    // ALL SHAPE STUFF
    int tempId;
    string tempName;
    string dimString;
    int tempNumDimensions;
    int *tempDimensions;

    if(datafile.is_open())
    {
        while(datafile.good())
        {
            tempId = stoi(getStringFromFile(datafile));

            tempName = getStringFromFile(datafile);

            Shape *p_Shape = nullptr;
            p_Shape = getShapePtr(tempName);

            myVector::vector<int> v_dims;
            int dim;

            // TAKES IN & STORES STRING
            dimString = getStringFromFile(datafile);
            std::istringstream buffer{dimString};

            // PARSES THROUGH STRING
            while(buffer >> dim)
            {
                // ADDS DIMENSION TO THE DIMENSION VECTOR
                v_dims.push_back(dim);

                // LOOKS AHEAD FOR WHITE SPACE + COMMA, IF IT SEES THIS, IGNORES THESE CHARACTERS AND TAKES IN NEXT DIMENSION
                if((buffer >> std::ws).peek() == ',')
                {
                    buffer.ignore();
                }
            } // end while

            tempNumDimensions = v_dims.size();

            tempDimensions = new int[v_dims.size()];

            for(int i = 0; i < v_dims.size(); ++i)
            {
                tempDimensions[i] = v_dims[i];
            } // end for

            p_Shape -> setBaseInfo(tempId, tempName, tempNumDimensions, tempDimensions);

            delete[] tempDimensions;
            tempDimensions = nullptr;

            if(tempName == "Text")
            {
                // CREATES TEMPORARY TEXT POINTER TO ACCESS TEXT-SPECIFIC METHODS
                Text *p_text = nullptr;

                QPen pen;
                QFont font;

                // READS IN DATA, SETS PEN, FONT, TEXT QUALITIES
                p_text -> setText(getStringFromFile(datafile));
                pen.setColor(QColor(convertToGlobalColor(getStringFromFile(datafile))));
                p_text -> setAlignment(convertToAlignmentFlag((getStringFromFile(datafile))));
                font.setPointSize(stoi(getStringFromFile(datafile)));
                font.setFamily(QString::fromStdString(getStringFromFile(datafile)));
                font.setStyle(convertToQFontStyle(getStringFromFile(datafile)));
                font.setWeight(convertToQFontWeight(getStringFromFile(datafile)));

                // SETS QPen AND QFont OBJECTS
                p_text -> setPen(pen);
                p_text -> setFont(font);

                // UPCASTS TEXT POINTER INTO SHAPE POINTER
                p_Shape = dynamic_cast<Shape*>(p_text);
            }
            else
            {
                QPen pen;

                pen.setColor(QColor(convertToGlobalColor(getStringFromFile(datafile))));
                pen.setWidth(stoi(getStringFromFile(datafile)));
                pen.setStyle(convertToPenStyle(getStringFromFile(datafile)));
                pen.setCapStyle(convertToPenCapStyle(getStringFromFile(datafile)));
                pen.setJoinStyle(convertToPenJoinStyle(getStringFromFile(datafile)));

                p_Shape -> setPen(pen);

                if(tempName != "Line" && tempName != "Polyline")
                {
                    QBrush brush;

                    brush.setColor(QColor(convertToGlobalColor(getStringFromFile(datafile))));
                    brush.setStyle(convertToBrushStyle(getStringFromFile(datafile)));

                    p_Shape -> setBrush(brush);
                } // end if
            } // end else

            v_shapes.push_back(p_Shape);

            datafile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } // end while
    } // end if

    // Closes Shape Input file
    closeFile(datafile);

} // end addShape(...)

Shape* Parser::getShapePtr(std::string shapeType)
{
    using namespace ShapeLabels;

    Shape* p_Shape;

    try
    {
        if(shapeType == SHAPES_LIST[eShapes::LINE])
        {
            p_Shape = new Line();
        }
        else if(shapeType == SHAPES_LIST[eShapes::POLYLINE])
        {
            p_Shape = new Polyline();
        }
        else if(shapeType == SHAPES_LIST[eShapes::POLYGON])
        {
            p_Shape = new Polygon();
        }
        else if(shapeType == SHAPES_LIST[eShapes::RECTANGLE])
        {
            p_Shape = new Rectangle();
        }
        else if(shapeType == SHAPES_LIST[eShapes::SQUARE])
        {
            p_Shape = new Square();
        }
        else if(shapeType == SHAPES_LIST[eShapes::ELLIPSE])
        {
            p_Shape = new Ellipse();
        }
        else if(shapeType == SHAPES_LIST[eShapes::CIRCLE])
        {
            p_Shape = new Circle();
        }
        else if(shapeType == SHAPES_LIST[eShapes::TEXT])
        {
            p_Shape = new Text();
        }
        else
        {
            throw shapeException("\n***ERROR - NO APPROPRIATE SHAPE TYPE WAS FOUND IN THE INPUT FILE***\n\n");
        }
    }
    catch(shapeException shapeTypeEx)
    {
        shapeTypeEx.what();
    }

    return p_Shape;
}

void closeFile(fstream &datafile)
{
    try
    {
        if(datafile.is_open())
        {
            datafile.close();
        }
        else
        {
            throw shapeException("\n***ERROR - FILE IS NOT OPEN, CANNOT CLOSE FILE***\n\n");
        }
    }
    catch(shapeException fileEx)
    {
        cout << fileEx.what();
    }
}
