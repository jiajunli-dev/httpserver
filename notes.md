std::vector<std::string> arr;
size_t start {0};
size_t size = strlen(buffer);
for (size_t i = 0; i < size; ++i)
{
    if (buffer[i] == '\n')
    {

        std::string str = extract(buffer, start, i);
        arr.push_back(str);

        start = i + 1;
    }
}

for (size_t i = 0; i < arr.size(); ++i)
{
    std::cout << buffer[i];
}


// std::vector<std::string> parse = parseBuffer(buffer);
    // std::istringstream ss(parse[0]);
    // std::string method, path, protocol;

    // std::getline(ss, method, ' ');
    // std::getline(ss, path, ' ');
    // std::getline(ss, protocol, ' ');
