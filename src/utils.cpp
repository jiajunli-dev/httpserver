#include <sstream>
#include <vector>

std::vector<std::string> parseBuffer(char buffer[]) {
  std::vector<std::string> lines;
  std::istringstream ss(buffer);
  std::string line;
  while (std::getline(ss, line)) {
    if (!line.empty() && line.back() == '\r') {
      line.pop_back();
    }
    lines.push_back(line);
  }

  return lines;
}
