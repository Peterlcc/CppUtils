//
// Created by 李春程 on 2020/12/2.
//

#include "param_server/BridgeInfo.h"

BridgeInfo::BridgeInfo(string& json)
{
    this->json = json;
    const char * str=json.c_str();
    Value root;
    JSONCPP_STRING err;
    Json::CharReaderBuilder b;
    Json::CharReader* reader(b.newCharReader());
    if (reader->parse(str, str + strlen(str), &root, &err)) {
        this->op=root["operator"].asInt();
        this->name = root["name"].asString();
        this->type = root["type"].asInt();
        this->val = root["value"];
        this->parsed = true;
    }
    else {
        cout << "parse failed!because: "<<err << endl;
        this->parsed = false;
    }
}

int BridgeInfo::getOp()
{
    return op;
}

string BridgeInfo::getName()
{
    return name;
}

int BridgeInfo::getType()
{
    return type;
}

void BridgeInfo::getValue(int& val0, bool& val1, unsigned int& val2, double& val3, string& val4)
{
    switch (type)
    {
        case 0:
            val0=val.asInt();
            break;
        case 1:
            val1 = val.asBool();
            break;
        case 2:
            val2 = val.asUInt();
            break;
        case 3:
            val3 = val.asDouble();
            break;
        case 4:
            val4 = val.asString();
            break;
        default:
            break;
    }
}

bool BridgeInfo::isParsed()
{
    return parsed;
}

Value BridgeInfo::getVal()
{
    return this->val;
}

string BridgeInfo::toString()
{
    return this->json;
}
