#include <iostream>

int main() {
    int lock1, lock2;
    std::cin >> lock1 >> lock2;

    if(lock1 % 2 == 0 || lock2 % 2 == 1) {
        std::cout << "yes" << std::endl;
        return 0;
    }
    std::cout << "no" << std::endl;
    return 0;
}