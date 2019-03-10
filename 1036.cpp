#include <iostream>
#include <vector>


class BigInteger
{
    static const uint64_t BASE = 1'000'000'000;
    static const int EXP = 9;
    static const int SIZE = 12;

    uint32_t number[SIZE];

public:
    BigInteger() {
        for(auto& v : number) {
            v = 0;
        }
    }

    BigInteger(const BigInteger& big) {
        *this = big;
    }

    BigInteger(uint32_t n) {
        *this = BigInteger();
        number[0] = n;
    }

    BigInteger& operator= (const BigInteger& rhs) {
        for (int i = 0; i < SIZE; ++i) {
            this->number[i] = rhs.number[i];
        }
        return *this;
    }

    bool operator!= (const BigInteger& rhs) {
        for (int i = 0; i < SIZE; ++i) {
            if (this->number[i] != rhs.number[i]) {
                return true;
            }
        }
        return false;
    }

    BigInteger operator+ (const BigInteger& rhs) {
        
        BigInteger result;
        int carry = 0;

        for (int i = 0; i < SIZE; ++i) {
            result.number[i] = this->number[i] + rhs.number[i] + carry;
            carry = 0;

            if (result.number[i] >= BASE || result.number[i] < this->number[i]) {
                carry = 1;
                result.number[i] -= BASE;
            }
        }

        if (carry) {
            throw "overflow";
        }

        return result;
    }

    BigInteger operator* (const BigInteger& rhs) {

        BigInteger result;
        for (int i = 0; i < SIZE / 2 ; ++i) {
            
            int carry = 0;
            for (int j = 0; j < SIZE / 2; ++j) {

                uint64_t cur = result.number[i + j] + 
                    rhs.number[i] * 1LL * this->number[j] + carry;

                result.number[i + j] = cur % BASE;
                carry = cur / BASE;
            }
            
            result.number[SIZE / 2 + i] += carry;
        }
        return result;
    }

    BigInteger& operator+= (const BigInteger& rhs) {
        return *this = *this + rhs;
    }

    friend std::ostream& operator<< (std::ostream &out, const BigInteger& big) {

        char oldFill = out.fill();
        out.fill('0');

        bool mandatory = false;
        for(int i = SIZE - 1; i >= 0; --i) {
            
            if (!mandatory && big.number[i]) {
                mandatory = true;
                out << big.number[i];
            } 
            else if (mandatory) {
                out.width(EXP);
                out << big.number[i];
            }
        }

        if (!mandatory) {
            out << big.number[0];
        }

        out.fill(oldFill);
        return out;
    }
};


struct Record {
    BigInteger number;
    bool empty;
};

BigInteger countLuckyTickets(int n, int sum) 
{
    static std::vector<std::vector<Record>> cache;
    static bool init = false;

    if (!init) {
        cache.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            cache[i].resize(sum + 1);
            for(int j = 0; j <= sum; ++j) {
                cache[i][j].empty = true;
            }
        }
        init = true;
    }

    if (n == 1) {
        if (sum < 10) {
            return 1;
        }
        return 0;
    }

    if (!cache[n][sum].empty) {
        return cache[n][sum].number;
    }

    cache[n][sum].number = 0;
    cache[n][sum].empty = false;

    for(int i = 0; i < 10 && sum - i >= 0; ++i) {
        cache[n][sum].number += countLuckyTickets(n - 1, sum - i);
    }

    return cache[n][sum].number;
}

int main()
{
    int n, sum;
    std::cin >> n >> sum;

    if (!sum) {
        std::cout << 1 << std::endl;
        return 0;
    }

    if (sum % 2 || 9 * n * 2 < sum) {
        std::cout << 0 << std::endl;
        return 0;
    }

    sum >>= 1;

    BigInteger counter = countLuckyTickets(n, sum);
    std::cout << counter * counter << std::endl;

    return 0;
}