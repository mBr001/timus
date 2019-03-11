#include <iostream>
#include <string>
#include <map>

int main()
{
    std::map<std::string, int> counter;

    int n;
    std::cin >> n;

    std::string name;
    for (int i = 0; i < n; ++i) {
        std::cin >> name;
        ++counter[name];
    }

    for (auto cnt : counter) {
        if (cnt.second > 1) {
            std::cout << cnt.first << std::endl;
        }
    }

    return 0;
}