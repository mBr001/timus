#include <iostream>
#include <algorithm>


int sum(int* arr, int first, int last) 
{
    int sum = 0;
    for(int i = first; i <= last ; ++i) {
        sum += arr[i];
    }
    return sum;
}

int main() 
{
    int n;
    std::cin >> n;

    int *arr = new int[n];
    
    for(int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int p1, p2;
    std::cin >> p1 >> p2;
    --p1, --p2;

    int score1, score2;

    if(p1 == p2) {
        int left  = sum(arr, 0, p1 - 1);
        int right = sum(arr, p1 + 1, n - 1);
        score1 = std::max(left, right) + arr[p1];
        score2 = std::min(left, right);
    }
    else if(p1 < p2) {
        int cellsBetweenPlayers = p2 - p1 - 1;
        int p1_last = p1 + cellsBetweenPlayers / 2 + cellsBetweenPlayers % 2;
        int p2_1st  = p2 - cellsBetweenPlayers / 2;

        score1 = sum(arr, 0, p1_last);
        score2 = sum(arr, p2_1st, n - 1);
    }
    else {
        int cellsBetweenPlayers = p1 - p2 - 1;
        int p1_1st   = p1 - cellsBetweenPlayers / 2 - cellsBetweenPlayers % 2;
        int p2_last  = p2 + cellsBetweenPlayers / 2;

        score1 = sum(arr, p1_1st, n - 1);
        score2 = sum(arr, 0, p2_last);
    }
    
    std::cout << score1 << " " << score2 << std::endl;

    delete [] arr;
    return 0;
}