#include "MultiProperties.h"

bool MultiProperties::load(const string& path) {
    loadHelper(path, prefix, true);
    loadKeys();
    return true;
}

string MultiProperties::getProperty(const string& key) {
    set<string>* keys = getKeys();
    for (auto pkey : *keys) {
        if (pkey.find(key) != string::npos) {
            return props->at(key);
        }
    }
    return "";
}

void MultiProperties::setProperty(const string& key, const string& value) {
    this->props->insert(make_pair(key, value));
}

MultiProperties::MultiProperties(vector<string>* paths, string& prefix) : Properties() {
    this->paths = paths;
    this->prefix = prefix;

}

MultiProperties::~MultiProperties() {
    delete paths;
}

bool MultiProperties::load() {
    for (string& path : *paths) {
        if (!load(path)) {
            return false;
        }
    }
    return true;
}
