//
// Created by 李春程 on 2020/12/2.
//

#ifndef JSONTEST_BRIDGEINFO_H
#define JSONTEST_BRIDGEINFO_H

#include <iostream>
#include<string>
#include<fstream>
#include<string.h>
#include "jsoncpp/json/json.h"
using namespace std;
using namespace Json;

/*
protcol:
    operator:0/1 #参数的操作类型，0代表get，1代表set
    name:key #参数的key
    type:[0-4] #参数的值类型，分别为0-int/1-bool/2-uint/3-double/4-string
    value:val #参数的值
*/
class BridgeInfo
{
private:
    string json;

    int op;
    string name;
    int type;
    Value val;

    bool parsed;
public:
    BridgeInfo(string& json);

    int getOp();
    string getName();
    int getType();
    void getValue(int& val0, bool& val1, unsigned int& val2, double& val3, string& val4);
    bool isParsed();

    Value getVal();

    string toString();
};


#endif //JSONTEST_BRIDGEINFO_H
