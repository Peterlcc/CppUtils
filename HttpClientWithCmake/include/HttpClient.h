#ifndef CURLTEST_HTTPCLIENT_H
#define CURLTEST_HTTPCLIENT_H
#include <iostream>
#include<string>
#include <vector>
#include <curl/curl.h>
using namespace std;
class HttpClient
{
private:
    struct curl_slist* header_list = nullptr;
    static size_t req_reply(void *ptr, size_t size, size_t nmemb, void *stream);
public:
    HttpClient(vector<string> &headers);
    HttpClient();
    bool get(const string &url,string &response);
    bool post(const string &url,const string &postParams,string &response);

    virtual ~HttpClient();
};

#endif //CURLTEST_HTTPCLIENT_H