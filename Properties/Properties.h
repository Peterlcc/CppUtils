#pragma once
#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
#include<set>

using namespace std;

class Properties {
protected:
    map<string, string>* props = nullptr;
    set<string>* keys = nullptr;

    void trim(string& s);

    void loadKeys();
    vector<string> split(const string& str, char pattern);
    bool startWith(const string& s, const string& sub);

    void loadHelper(const string& path, const string& prefix, bool addPath = false);

public:
    map<string, string>* getProps() const;

    set<string>* getKeys() const;

    //load data from file path
    virtual bool load(const string& path) = 0;

    //get value with key
    virtual string getProperty(const string& key) = 0;

    //set key and value
    virtual void setProperty(const string& key, const string& value) = 0;

    bool save(const string& path);

    Properties();

    virtual ~Properties();
};

