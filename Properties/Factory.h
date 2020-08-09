#pragma once
#include "Properties.h"

class Factory {
public:
    virtual Properties* createProperties() = 0;
};


