#include "getFromFile.h"

// bool Shape::const operator==(const &otherShape)
// {
//     return (id == otherShape.id);
// }

// bool Shape::const operator<(const &otherShape)
// {
//     return (id < otherShape.id);
// }

string getStringFromFile(fstream &file)
{
    string temp;
 
    file.ignore(numeric_limits<streamsize>::max(), ' ');
    // getline(file, temp, ' ');
    getline(file, temp, '\n');

    return temp;
}

void getFromFile()
{

    fstream datafile("shapes2.txt", ios::in);
    string line;
    
    // ALL SHAPE STUFF
    int tempId;
    string tempName;
    string dimString;
    int tempNumDimensions;
    int *tempDimensions;
    string penColor;
    int penWidth;
    string penStyle;
    string penCapStyle;
    string penJoinStyle;
    string brushColor;
    string brushStyle;


    // TEXT STUFF
    string textString;
    string textColor;
    string textAlignment;
    int textPointSize;
    string textFontFamily;
    string textFontStyle;
    string textFontWeight;
    

    if(datafile.is_open())
    {
        while(datafile.good())
        {
            tempId = stoi(getStringFromFile(datafile));

            tempName = getStringFromFile(datafile);

            vector<int> v_dims;
            int dim;

            dimString = getStringFromFile(datafile);
            istringstream buffer{dimString};

            while(buffer >> dim)
            {
                v_dims.push_back(dim);

                if((buffer >> ws).peek() == ',')
                {
                    buffer.ignore();
                }
            }

            tempNumDimensions = v_dims.size();

            tempDimensions = new int[v_dims.size()];

            for(int i = 0; i < v_dims.size(); ++i)
            {
                tempDimensions[i] = v_dims[i];
            }

            if(tempName == "Text")
            {
                textString = getStringFromFile(datafile);
                textColor = getStringFromFile(datafile);
                textAlignment = getStringFromFile(datafile);
                textPointSize = stoi(getStringFromFile(datafile));
                textFontFamily = getStringFromFile(datafile);
                textFontStyle = getStringFromFile(datafile);
                textFontWeight = getStringFromFile(datafile);
            }
            else
            {
                penColor = getStringFromFile(datafile);
                penWidth = stoi(getStringFromFile(datafile));
                penStyle = getStringFromFile(datafile);
                penCapStyle = getStringFromFile(datafile);
                penJoinStyle = getStringFromFile(datafile);

                if(tempName != "Line" && tempName != "Polyline")
                {
                    brushColor = getStringFromFile(datafile);
                    brushStyle = getStringFromFile(datafile);
                }
            }

            datafile.ignore(numeric_limits<streamsize>::max(), '\n');

            // OUTPUT SECTION
            cout << "ShapeId: " << tempId << endl;
            cout << "ShapeType: " << tempName << endl;
            cout << "ShapeDimensions: ";
            for(int i = 0; i < tempNumDimensions; ++i)
            {
                cout << tempDimensions[i];
                if(i < tempNumDimensions - 1)
                {
                    cout << ", ";
                }
            }
            cout << endl;
            
            if(tempName == "Text")
            {
                cout << "TextString: " << textString << endl;
                cout << "TextColor: " << textColor << endl;
                cout << "TextAlignment: " << textAlignment << endl;
                cout << "TextPointSize: " << textPointSize << endl;
                cout << "TextFontFamily: " << textFontFamily << endl;
                cout << "TextFontStyle: " << textFontStyle << endl;
                cout << "TextFontWeight: " << textFontWeight << endl;
            }
            else
            {
                cout << "PenColor: " << penColor << endl;
                cout << "PenWidth: " << penWidth << endl;
                cout << "PenStyle: " << penStyle << endl;
                cout << "PenCapStyle: " << penCapStyle << endl;
                cout << "PenJoinStyle: " << penJoinStyle << endl;

                if(tempName != "Line" && tempName != "Polyline")
                {
                    cout << "BrushColor: " << brushColor << endl;
                    cout << "BrushStyle: " << brushStyle << endl;
                }
            }
            cout << endl;

            delete[] tempDimensions;
        }
    }

    datafile.close();
}


// make this virtual to Shape (not pure), only override for Text, Line, Polyline
// string Shape::print() const
// {
//     ostringstream oss;

//     oss << "ShapeId: " << shapeId << endl;
//     oss << "ShapeType: " << shapeType << endl;
//     oss << "ShapeDimensions: ";
//     for(int i = 0; i < numDimensions; ++i)
//     {
//         oss << shapeDimensions[i];
//         if(i < numDimensions - 1)
//         {
//             oss << ", ";
//         }
//     }
//     oss << endl;

//     oss << "PenColor: " << penColor << endl;
//     oss << "PenWidth: " << penWidth << endl;
//     oss << "PenStyle: " << penStyle << endl;
//     oss << "PenCapStyle: " << penCapStyle << endl;
//     oss << "PenJoinStyle: " << penJoinStyle << endl;
//     oss << "BrushColor: " << brushColor << endl;
//     oss << "BrushStyle: " << brushStyle << endl;

//     return oss.str();    
// } 

// string Text::print() const override
// {
//     ostringstream oss;

//     oss << "ShapeId: " << shapeId << endl;
//     oss << "ShapeType: " << shapeType << endl;
//     oss << "ShapeDimensions: ";
//     for(int i = 0; i < numDimensions; ++i)
//     {
//         oss << shapeDimensions[i];
//         if(i < numDimensions - 1)
//         {
//             oss << ", ";
//         }
//     }
//     oss << endl;
//     oss << "TextString: " << textString << endl;
//     oss << "TextColor: " << textColor << endl;
//     oss << "TextAlignment: " << textAlignment << endl;
//     oss << "TextPointSize: " << textPointSize << endl;
//     oss << "TextFontFamily: " << textFontFamily << endl;
//     oss << "TextFontStyle: " << textFontStyle << endl;
//     oss << "TextFontWeight: " << textFontWeight << endl;

//     return oss.str();
// }

// string Line::print() const override
// {
//     ostringstream oss;

//     oss << "ShapeId: " << shapeId << endl;
//     oss << "ShapeType: " << shapeType << endl;
//     oss << "ShapeDimensions: ";
//     for(int i = 0; i < numDimensions; ++i)
//     {
//         oss << shapeDimensions[i];
//         if(i < numDimensions - 1)
//         {
//             oss << ", ";
//         }
//     }
//     oss << endl;

//     oss << "PenColor: " << penColor << endl;
//     oss << "PenWidth: " << penWidth << endl;
//     oss << "PenStyle: " << penStyle << endl;
//     oss << "PenCapStyle: " << penCapStyle << endl;
//     oss << "PenJoinStyle: " << penJoinStyle << endl;

//     return oss.str();
// }

// string Polyline::print() const override
// {
//     ostringstream oss;

//     oss << "ShapeId: " << shapeId << endl;
//     oss << "ShapeType: " << shapeType << endl;
//     oss << "ShapeDimensions: ";
//     for(int i = 0; i < numDimensions; ++i)
//     {
//         oss << shapeDimensions[i];
//         if(i < numDimensions - 1)
//         {
//             oss << ", ";
//         }
//     }
//     oss << endl;

//     oss << "PenColor: " << penColor << endl;
//     oss << "PenWidth: " << penWidth << endl;
//     oss << "PenStyle: " << penStyle << endl;
//     oss << "PenCapStyle: " << penCapStyle << endl;
//     oss << "PenJoinStyle: " << penJoinStyle << endl;

//     return oss.str();
// }


// // Grand Printerizer
// void Shape::printAll()
// {
//     fstream fout(fileName.c_str(), ios::out);

//     for(Shape* it = v_Shapes.begin(); it < v_Shapes.end(); ++it)
//     {
//         fout << it -> print();
//         fout << endl;
//     }

//     fout.close();
// }