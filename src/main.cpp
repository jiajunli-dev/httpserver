#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstring>
#include <vector>
#include <sstream>

#include "utils.h"
#include "path.h"

#define PORT 8080

int main()
{
    int server_fd, client_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] {"buffer"};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (true)
    {
        client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        if (client_socket < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        read(client_socket, buffer, 1024);

        std::vector<std::string> parse = parseBuffer(buffer);
        std::istringstream ss(parse[0]);
        std::string method, path, protocol;

        std::getline(ss, method, ' ');
        std::getline(ss, path, ' ');
        std::getline(ss, protocol, ' ');

        const char undefinedPath[] = "<p>undefined path</p>\r\n";
        std::string response = makeResponse(undefinedPath);

        const char path1[] = "<p>Hello from: /</p>\r\n";
        std::string response1 = makeResponse(path1);

        const char path2[] = "<p>Hello from: /jiajun</p>\r\n";
        std::string response2 = makeResponse(path2);

        const char path3[] = "<p>Hello from: /test</p>\r\n";
        std::string response3 = makeResponse(path3);

        if (path == "/") send(client_socket, response1.c_str(), response1.size(), 0);
        else if (path == "/jiajun") send(client_socket, response2.c_str(), response2.size(), 0);
        else if (path == "/test") send(client_socket, response3.c_str(), response3.size(), 0);
        else send(client_socket, response.c_str(), response.size(), 0);

        close(client_socket);
    }

    close(server_fd);

    return 0;
}
