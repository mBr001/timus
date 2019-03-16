#include <iostream>
#include <string>
#include <map>

int main()
{
    std::multimap<char, std::string, std::less<char>> table;
    
    int n;
    std::cin >> n;

    std::string buf;
    for (int i = 0; i < n; ++i) {
        std::cin >> buf;
        table.emplace(buf[0], buf);
    }

    char first;
    std::cin >> first;

    auto range = table.equal_range(first);

    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->second << std::endl;
    }

    return 0;
}