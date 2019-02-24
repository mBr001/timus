#include <iostream>

int main()
{
    int n, k;
    std::cin >> n >> k;

    if(n <= k) {
        std::cout << 2 << std::endl;
        return 0;
    }

    if(2 * n % k == 0) {
        std::cout << 2 * n / k << std::endl;
	    return 0;
    }

    std::cout << 2 * n / k + 1 << std::endl;
}
