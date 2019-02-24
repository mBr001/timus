#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int> readVec() 
{   
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    return v;
}


int main() 
{
    std::vector<int> v1, v2, v3;
    v1 = readVec();
    v2 = readVec();
    v3 = readVec();

    int counter = 0;
    for(auto i  = v1.cbegin(), j  = v2.cbegin(), k  = v3.cbegin(); 
             i != v1.cend() && j != v2.cend() && k != v3.cend();  ) 
    {   
        if(*i == *j && *j == *k) {
            ++counter; ++i; ++j; ++k;
            continue;
        }
        int min = std::min(std::min(*i, *j), *k);
        if(*i == min) ++i;
        if(*j == min) ++j;
        if(*k == min) ++k;
    }

    std::cout << counter << std::endl;
    return 0;
}