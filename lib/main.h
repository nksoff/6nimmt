#ifndef MAIN_H
#define MAIN_H

#include <functional>
#include "lib/ownexception.h"

inline void throwError(const std::string &str) {
    throw OwnException(str);
}

inline void checkNullPointer(void *pointer, std::function<void()> onError = [](){}) {
    if(pointer == NULL) {
        throwError("Couldn't allocate memory. Sorry!");
        onError();
    }
}

#endif // MAIN_H

