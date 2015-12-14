#include "ownexception.h"

OwnException::OwnException(std::string message)
    : _message(message)
{
}

const char *OwnException::what() const throw() {
    return _message.c_str();
}
