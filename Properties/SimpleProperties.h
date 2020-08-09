#pragma once

#include <ostream>
#include "Properties.h"

class SimpleProperties : public Properties {
private:
    string prefix;
public:
    SimpleProperties(const string& prefix);

    virtual bool load(const string& path) override;

    virtual string getProperty(const string& key) override;

    virtual void setProperty(const string& key, const string& value) override;

    friend ostream& operator<<(ostream& os, const SimpleProperties& properties);
};

