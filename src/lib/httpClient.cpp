#include "httpClient.hpp"
#include <curl/curl.h>

httpClient::httpClient(const std::string& url, const std::string& authorization) {
    this.url = url;
    this.authorizatio = authorization;
}

void httpClient::httpPost(const std::string& data) {
    Curl curl = curl_easy_init();

    struct curl_slist *headers = NULL;

    chunk = curl_slist_append(chunk, "Content-Type: application/json");

    if (authorization) {
        chunk = curl_slist_append(chunk, "Authorization: " + authorization);
    }

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, readResponse);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
}

string httpClient::getResponse() {
	return response;
}

size_t readResponse(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
}
