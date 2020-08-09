#include "Properties.h"

Properties::Properties() {
    this->props = new map<string, string>();
    this->keys = new set<string>();
}

map<string, string>* Properties::getProps() const {
    return props;
}

set<string>* Properties::getKeys() const {
    return keys;
}

void Properties::trim(string& s)
{
    if (!s.empty())
    {
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
    }

}

void Properties::loadKeys()
{
    for (auto i : *props) {
        keys->insert(i.first);
    }
}

vector<string> Properties::split(const string& str, char pattern)
{
    vector<string> res;
    stringstream input(str);
    string temp;
    while (getline(input, temp, pattern))
    {
        res.push_back(temp);
    }
    return res;
}

Properties::~Properties() {
    delete props;
    delete keys;

}

void Properties::loadHelper(const string& path, const string& prefix, bool addPath) {
    vector<string> paths = split(path, '.');

    if (paths.size() == 0 || paths[paths.size() - 1] != "properties") {
        throw new runtime_error(path+" is not a properties file!");
    }
    ifstream input(path);
    if (!input) {
        throw new runtime_error("can't load "+path);
    }
    //windows separetor:\\
    //linux separetor:/
    string fileName = addPath ? path.substr(path.find_last_of("/"),path.find_last_of('.')) : "";
    string line;
    while (getline(input, line))
    {
        trim(line);
        if (line.empty() || line == "\r" || line[0] == '#')
        {
            continue;
        }
        if (!startWith(line, prefix)) {
            continue;
        }
        vector<string> res = split(line, '=');
        if (res.size() < 2)
        {
            cerr << "Properties format error!" << endl;
            throw new exception("Properties format error!");
        }
        int t = res[1].find("#");
        if (t != string::npos) {
            res[1].erase(t);
        }
        for_each(res.begin(), res.end(), [=](string& s)mutable {
            trim(s);
            });
        props->insert(make_pair(fileName + res[0], res[1]));
    }

    input.close();
}

bool Properties::startWith(const string& s, const string& sub) {
    if (sub == "") return true;
    return s.find(sub) == 0;
}

bool Properties::save(const string& path) {
    ofstream output(path);
    if (!output) {
        throw new exception("can 't construct the output file!");
    }
    for (auto item : *props) {
        output << item.first << "=" << item.second << endl;
    }
    return true;
}