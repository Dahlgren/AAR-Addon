#pragma once

#include <string>

class httpClient {
public:
    httpClient(const std::string& url, const std::string& authorization);
    std::string getResponse();
    void httpPost(const std::string& data);

    enum status_t { OK = 201, BAD_REQUEST = 400, UNAUTHORIZED = 401, FORBIDDEN = 403, NOT_FOUND = 404, CONNECTION_FAILED = 1000 };
    status_t status;
private:
    std::string authorization;
    std::string response;
    std::string url;
};
