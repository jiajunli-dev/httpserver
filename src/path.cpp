#include <cstring>
#include <vector>
#include <sstream>

std::string makeResponse(const char *body)
{
    return "HTTP/1.1 200 OK\r\n"
           "Content-Type: text/html; charset=UTF-8\r\n"
           "Content-Length: " +
           std::to_string(strlen(body)) + "\r\n"
                                          "\r\n" +
           std::string(body);
}
