#pragma once
#include "Factory.h"
#include "MultiProperties.h"

class MultiPropertiesFactory :public Factory {
private:
    vector<string>* paths = nullptr;
    string prefix;
public:
    virtual ~MultiPropertiesFactory();

    MultiPropertiesFactory(vector<string>* paths, const string& prefix = "");

    Properties* createProperties() override;
};

