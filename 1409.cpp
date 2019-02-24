#include <iostream>

int main() {
    int Garry, Larry, total;
    std::cin >> Garry >> Larry;
    total = Garry + Larry - 1;
    std::cout << total - Garry << " " << total - Larry << std::endl;
}