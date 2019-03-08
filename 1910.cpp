#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int *arr = new int[n];

    for(int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int maxSum = 0, index = 0;
    for(int curSum = 0, i = 1; i < n - 1; ++i) {
        curSum = arr[i-1] + arr[i] + arr[i+1];
        if(curSum > maxSum) {
            maxSum = curSum;
            index = i;
        }
    }

    delete [] arr;
    std::cout << maxSum << " " << ++index << std::endl;
    return 0;
}