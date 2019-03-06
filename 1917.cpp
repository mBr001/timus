#include <iostream>
#include <map>

int main()
{
    int n, p;
    std::cin >> n >> p;

    std::map<int, int> counter;
    
    for(int resistance, i = 0; i < n; ++i) {
        std::cin >> resistance;
        ++counter[resistance];
    }

    int spellCounter = 0, coinCounter = 0;
    
    int coinsPerSpell = 0;
    for(std::pair<int, int> cnt : counter) {

        if(cnt.first * cnt.second > p) {
            break;
        }       
        
        if(cnt.first * (coinsPerSpell + cnt.second) <= p) {
            coinsPerSpell += cnt.second;
            continue;
        }

        if(coinsPerSpell) {
            coinCounter += coinsPerSpell;
            ++spellCounter;
        }

        coinsPerSpell = cnt.second;
    }

    if(coinsPerSpell) {
        coinCounter += coinsPerSpell;
        ++spellCounter;
    }

    std::cout << coinCounter << " " << spellCounter << std::endl;

    return 0;
}