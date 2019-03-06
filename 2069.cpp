#include <iostream>
#include <algorithm>
#include <tuple>


std::tuple<int, int, int> readData(int n)
{
    int first, last;
    std::cin >> first;

    int max = first;
    for(int buf, i = 1; i < n - 1; ++i) {
        std::cin >> buf;
        if(buf > max) {
            max = buf;
        }
    }
    std::cin >> last;
    return std::make_tuple(first, last, max);
}


int main()
{
    int n, m;
    std::cin >> n >> m;

    int left, right, maxVert;
    std::tie(left, right, maxVert) = readData(n);

    int top, bottom, maxHorz;
    std::tie(top, bottom, maxHorz) = readData(m);

    int topRight = std::min(top, right);
    int topVertBottom = std::min(std::min(top, bottom), maxVert);
    int leftBottom = std::min(left, bottom);
    int leftHorzRight = std::min(std::min(left, maxHorz), right);

    int metric = std::max(
        std::max(topRight, topVertBottom), 
        std::max(leftBottom, leftHorzRight));

    std::cout << metric << std::endl;
    
    return 0;
}