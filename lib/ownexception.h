#ifndef OWNEXCEPTION_H
#define OWNEXCEPTION_H

#include <exception>
#include <string>

class OwnException : public std::exception
{
private:
    std::string _message;
    bool _fatal;
public:
    OwnException(std::string str, bool = true);
    virtual const char *what() const throw();
    virtual bool isFatal() const throw();
};

#endif // OWNEXCEPTION_H
