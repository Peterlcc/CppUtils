// #include"person.h"
#include <bits/stdc++.h>
#include "HttpClient.h"
using namespace std;

int main(int argc, char const *argv[])
{
    HttpClient httpClient;
    std::string getUrlStr = "http://www.baidu.com";
    std::string outTxt;
    httpClient.get(getUrlStr, outTxt);
    cout<<outTxt<<endl;
    string javaHome=getenv("JAVA_HOME");
    cout<<javaHome<<endl;
    return 0;
}
