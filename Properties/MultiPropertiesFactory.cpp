#include "MultiPropertiesFactory.h"

Properties* MultiPropertiesFactory::createProperties() {
    return new MultiProperties(paths, prefix);
}

MultiPropertiesFactory::MultiPropertiesFactory(vector<string>* paths, const string& prefix) : paths(paths), prefix(prefix) {

}

MultiPropertiesFactory::~MultiPropertiesFactory() {
    delete paths;
}