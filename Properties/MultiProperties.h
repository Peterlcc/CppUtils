#pragma once
#include "Properties.h"

class MultiProperties :public Properties {
private:
    vector<string>* paths = nullptr;
    string prefix = "";
    bool load(const string& path) override;
public:
    MultiProperties(vector<string>* paths, string& prefix);
    bool load();
    string getProperty(const string& key) override;

    void setProperty(const string& key, const string& value) override;

    virtual ~MultiProperties();
};

