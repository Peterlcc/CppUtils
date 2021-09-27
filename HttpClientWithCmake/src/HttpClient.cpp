#include "HttpClient.h"

bool HttpClient::get(const string &url, string &response) {
//curl初始化
    CURL *curl = curl_easy_init();
    // curl返回值
    CURLcode res;
    if (curl) {
        //设置curl的请求头
        if (header_list != nullptr)
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header_list);

        //不接收响应头数据0代表不接收 1代表接收
        curl_easy_setopt(curl, CURLOPT_HEADER, 0);

        //设置请求的URL地址
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        //设置ssl验证
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);

        //CURLOPT_VERBOSE的值为1时，会显示详细的调试信息
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 0);

        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);

        //设置数据接收函数
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, req_reply);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &response);

        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);

        //设置超时时间
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 6); // set transport and time out time
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 6);

        // 开启请求
        res = curl_easy_perform(curl);
    }
    // 释放curl
    curl_easy_cleanup(curl);
    return res == CURLE_OK;
}

HttpClient::HttpClient(vector<string> &headers) {
    for (string &head:headers) {
        header_list = curl_slist_append(header_list, head.c_str());
    }
}

size_t HttpClient::req_reply(void *ptr, size_t size, size_t nmemb, void *stream) {
    //在注释的里面可以打印请求流，cookie的信息
//    cout << "----->reply" << endl;
    string *str = (string *) stream;
//    cout << *str << endl;
    (*str).append((char *) ptr, size * nmemb);
    return size * nmemb;
}

bool HttpClient::post(const string &url, const string &postParams,string &response) {
    // curl初始化
    CURL *curl = curl_easy_init();
    // curl返回值
    CURLcode res;
    if (curl)
    {
        // set params
        //设置curl的请求头
        //设置curl的请求头
        if (header_list != nullptr)
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header_list);

        //不接收响应头数据0代表不接收 1代表接收
        curl_easy_setopt(curl, CURLOPT_HEADER, 0);

        //设置请求为post请求
        curl_easy_setopt(curl, CURLOPT_POST, 1);

        //设置请求的URL地址
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        //设置post请求的参数
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postParams.c_str());

        //设置ssl验证
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);

        //CURLOPT_VERBOSE的值为1时，会显示详细的调试信息
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 0);

        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);

        //设置数据接收和写入函数
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, req_reply);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&response);

        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);

        //设置超时时间
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 6);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 6);

        // 开启post请求
        res = curl_easy_perform(curl);
    }
    //释放curl
    curl_easy_cleanup(curl);
    return res==CURLE_OK;
}

HttpClient::~HttpClient() {
    delete header_list;
}

HttpClient::HttpClient() {

}