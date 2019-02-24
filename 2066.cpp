#include <iostream>

int main() 
{
    int a, b, c;
    std::cin >> a >> b >> c;

    if(b < 2) {
        std::cout << a - b - c << std::endl;
        return 0;
    }

    std::cout << a - b * c << std::endl;
}