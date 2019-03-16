#include <iostream>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;

    int *teacherList = new int[n + 1];

    for (int i = 0; i < n; ++i) {
        std::cin >> teacherList[i];
    }

    int m;
    std::cin >> m;

    int matches = 0, date;
    for (int i = 0; i < m; ++i) {
        std::cin >> date;
        if (std::binary_search(teacherList, &teacherList[n], date)) {
            ++matches;
        }
    }

    std::cout << matches << std::endl;    

    delete [] teacherList;
    return 0;
}