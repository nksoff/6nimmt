#ifndef MAIN_H
#define MAIN_H

// common #include-s
#include <QWidget>
#include <QDebug>

#include <functional>
#include "lib/ownexception.h"

inline static void throwError(const std::string &str, bool isFatal = true) {
    throw OwnException(str, isFatal);
}

inline static void checkNullPointer(void *pointer, std::function<void()> onError = [](){}) {
    if(pointer == NULL) {
        onError();
        throwError("Couldn't allocate memory. Sorry!");
    }
}

#endif // MAIN_H

