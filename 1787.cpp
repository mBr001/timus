#include <iostream>

int main() {
    int k, n;
    std::cin >> k >> n;
    
    int cur = 0, m;
    for(int i = 0; i < n; i++) {
        std::cin >> m;
        cur += m - k;
        if(cur < 0) cur = 0;
    }
    std:: cout << cur << std::endl;
}