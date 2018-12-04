/*!
 * \brief   ShapeException Header File - Team Mittens USA
 * \brief   Overrides the standard exception class to output specific error messages for this application.
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
#ifndef SHAPEEXCEPTION_H
#define SHAPEEXCEPTION_H

#include <exception>
#include <string>
using namespace std;

//! Overrides the standard exception class.
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
