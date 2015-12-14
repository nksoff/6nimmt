#ifndef OWNEXCEPTION_H
#define OWNEXCEPTION_H

#include <exception>
#include <string>

class OwnException : public std::exception
{
private:
    std::string _message;
public:
    OwnException(std::string str);
    virtual const char *what() const throw();
};

#endif // OWNEXCEPTION_H
