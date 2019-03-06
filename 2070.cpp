// Kolya's interesting: any prime.
//
// Asya's interesting:
//   factorization: N = P1^a1 * P2^a2 * ... * Pk^ak;
//   deviders: d(N) = (a1 + 1)(a2 + 1)...(ak + 1);
//   N is interesting if and only if N = P^(a + 1) where (a + 1) is prime.
// 
// Opinions diverge: P^p.
//
// Limits: 
//   P^p <= 10^12, where p = a + 1;
//   max p: (2^p <= 10^12) ==> (p <= 39);
//   max P: (P^2 <= 10^12) ==> (P <= 10^6).


#include <iostream>
#include <tuple>


std::tuple<int*, std::size_t> erat(int n)
{
    const int size = (n >> 1);
    bool* arr = new bool[size];

    for(int i = 3; i <= n; i += 2) {
        arr[i >> 1] = true;
    }

    for(int i = 3; i*i <= n; i += 2) {
        if(arr[i >> 1]) {
            for(int k = i; k*i <= n; k += 2) {
                arr[k*i >> 1] = false;
            }
        }
    }

    int cnt = 1;
    for(int j = 1; j <= size; ++j) {
        if(arr[j]) {
            ++cnt;
        }
    }

    int *res = new int[cnt];
    res[0] = 2;
    for(int i = 0, j = 1; j <= size; ++j) {
        if(arr[j]) {
            res[++i] = (j << 1) + 1;
        }
    }

    delete [] arr;

    return std::make_tuple(res, cnt);
}


inline int64_t pow(int base, int exp) 
{
    int64_t ret = 1;
    for(int i = exp; i > 0; --i) {
        ret *= base;
    }
    return ret;
}


int main()
{
    const int primeLimit = 1'000'000;
    const int exp[11] = {2, 4, 6, 10, 12, 16, 18, 22, 28, 30, 36};
    
    int *primes;
    std::size_t size;
    std::tie(primes, size) = erat(primeLimit);

    int64_t L, R;
    std::cin >> L >> R;

    int64_t cnt = 0, k;
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < 11; ++j) {
            k = pow(primes[i], exp[j]);
            if(L <= k && k <= R) {
                ++cnt;
            }
        }
    }
    std::cout << (R - L + 1) - cnt << std::endl;    

    delete [] primes;
 
    return 0;
}