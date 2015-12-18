#include "ownexception.h"

OwnException::OwnException(std::string message, bool fatal)
    : _message(message), _fatal(fatal)
{
}

const char *OwnException::what() const throw()
{
    return _message.c_str();
}

bool OwnException::isFatal() const throw()
{
    return _fatal;
}
