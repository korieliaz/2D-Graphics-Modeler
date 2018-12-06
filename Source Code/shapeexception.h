/*!
 * \class shapeException
 * \brief   Overrides the standard exception class to output specific error messages for this application.
*/
#ifndef SHAPEEXCEPTION_H
#define SHAPEEXCEPTION_H

#include <exception>
#include <string>
using namespace std;

/*! Allows for program-specific error messages to print when an object of type shapeException is caught in a try-throw-catch block.
 * \sa Parser::getShapePtr()
 * \sa Parser::parseShapes()
 * \sa idCompare(Shape* bestShape, Shape* currentShape)
 */
class shapeException : public exception
{
public:
    //! Overrides the standard exception class constructor
    /*! If no specific error message is included, outputs a generic one.
     */
    shapeException(string msg = "\n***ERROR - CANNOT COMPLETE COMMAND***\n\n") {errorMsg = msg;}

    //! Overrides the standard exception what() function
    /*! Outputs a specific error message to the console.
     */
    const char* what() const noexcept override {return this -> errorMsg.c_str();}

private:
    string errorMsg;    /*!< The string containing the specific or generic error message that is displayed when an exception is caught */
};

#endif // SHAPEEXCEPTION_H
