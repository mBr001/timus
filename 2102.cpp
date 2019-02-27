// Use (1 <= N <= 10^18).
// 1) Minimal possible N for "Yes" is 2^20.
// 2) Maximal prime factor: (2^19 * P <= 10^18) ==> (P < 2*10^12).
// 3) P is prime if there are no deviders <= sqrt(P).
// 4) So we need all primes up to 2*10^6.


#include <iostream>
#include <tuple>
#include <cmath>


int main()
{
    int64_t n;
    std::cin >> n;

    constexpr int minPossible = 1 << 20;
    if(n < minPossible) {
        std::cout << "No" << std::endl;
        return 0;
    }

    const int64_t limit = 1'000'000'000'000'000'000; // 10^18
    const int primeLimit = std::sqrt(limit / (1 << 19));

    int cnt = 0;
    for(int i = 2; i < primeLimit && n != 1;) {
        if(n % i) {
            ++i;
            continue;
        }
        ++cnt;
        n /= i;
    }

    if(n == 1 && cnt == 20 || n != 1 && cnt == 19) {
        std::cout << "Yes" << std::endl;
        return 0;
    }

    std::cout << "No" << std::endl;
    return 0;
}