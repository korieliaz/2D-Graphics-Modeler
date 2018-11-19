#ifndef SHAPEEXCEPTION_H
#define SHAPEEXCEPTION_H

#include <exception>
#include <string>
using namespace std;

/*************************************************
 * CLASS shapeException : overrides std::exception
 * -----------------------------------------------
 * This overriden exception class allows for
 * program-specific error messages to print when
 * an object of type shapeException is caught in a
 * try-throw-catch block
 *************************************************/

class shapeException : public exception
{
public:
    shapeException(string msg = "\n***ERROR - CANNOT COMPLETE COMMAND***\n\n") {errorMsg = msg;}

    const char* what() const noexcept override {return this -> errorMsg.c_str();}

private:
    string errorMsg;
};

#endif // SHAPEEXCEPTION_H
