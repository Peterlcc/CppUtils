#include "SimpleProperties.h"

bool SimpleProperties::load(const string& path) {
    loadHelper(path, prefix);
    loadKeys();
    return true;
}

string SimpleProperties::getProperty(const string& key) {
    if (props->find(key) == props->end())
    {
        cerr << "can't find value with " << key << endl;
        return "";
    }
    string value =this->props->at(key);
    return value;
}

void SimpleProperties::setProperty(const string& key, const string& value) {
    if (!startWith(key, prefix))
        this->props->insert(make_pair(prefix + key, value));
    else
        this->props->insert(make_pair(key, value));
}

ostream& operator<<(ostream& os, const SimpleProperties& properties) {
    string line = "";
    for_each(properties.keys->begin(), properties.keys->end(), [&](string t) {
        line += t + ",";
        });
    os << "Simple Properies:[keys:" << line << "]";
    return os;
}

SimpleProperties::SimpleProperties(const string& prefix) :prefix(prefix), Properties() {}