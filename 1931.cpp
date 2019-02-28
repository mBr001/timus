#include <iostream>

int main() 
{
    int n;
    std::cin >> n;

    int *arr = new int[n];

    for(int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int index = 0, cur = 0, max_range = 0;
    for(int helper = arr[cur], i = 1; i < n; ++i) {
        
        if(arr[i] < helper) {
            helper = arr[i];

            if(i - cur >= max_range) {
                max_range = i - cur;
                index = cur;
            }

            cur = i;
        }
    }

    if(n - 1 - cur >= max_range) {
        index = cur;
    }

    std::cout << ++index << std::endl;

    delete [] arr;
    return 0;
}