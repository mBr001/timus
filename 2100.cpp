#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    std::string buf;
    buf.reserve(24);

    int persons = n + 2;
    for(int i = 0; i < n; ++i) {
        std::cin >> buf;
        if(buf.find("+") != std::string::npos) {
            ++persons;
        }
    }

    if(persons == 13) {
        ++persons;
    }

    std::cout << persons * 100 << std::endl;
}