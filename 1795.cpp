#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>


struct Husband {
    std::string product;
    int         amount;
};


int main()
{
    std::map<std::string, int> store;

    int m, n, amount;
    std::string buf;
    buf.reserve(20);
    
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        std::cin >> amount >> buf >> buf;
        store.emplace(buf, amount);
    }

    std::cin >> n;
    std::vector<Husband> queue(n);
    for (auto& h : queue) {
        std::cin >> h.amount >> buf >> h.product;
    }

    int timeMin = 0;
    auto prod = store.end();
    for (auto h = queue.begin(); h != queue.end() - 1; ++timeMin) {
        
        prod = store.find(h->product);
        
        if (prod == store.end() || prod->second == 0) {
            ++h;
            continue;
        }
        
        if (prod->second >= h->amount) {
            prod->second -= h->amount;
            ++h;
            continue;
        }

        h->amount = prod->second;
        std::swap(*h, *(h + 1));
    }

    std::cout << ++timeMin << std::endl;

    return 0;
}