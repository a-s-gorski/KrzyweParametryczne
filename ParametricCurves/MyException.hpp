//Andrzej Kusiak
#include <iostream>
#include <exception>

class EnteredValueIsNotAnInteger : public std::exception {
public:
    virtual const char* what() const throw()
    {
        return "Non-Integer value.";
    }
}notinteger;