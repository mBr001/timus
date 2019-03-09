// Use Warnsdorf's rule.

#include <iostream>
#include <string>
#include <vector>


using Field = std::string;
using MoveList = std::vector<Field>;


class Board 
{
    int size;
    bool **matrix;

public:
    Board(int n) : size(n) {
        matrix = new bool*[n];
        for (int i = 0; i < n; ++i) {
            matrix[i] = new bool[n];
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = false;
            }
        }
    }

    inline void hold(const Field& f) {
        int v = f[0] - 'a';
        int h = f[1] - '1';
        matrix[v][h] = true;
    }

    inline void release(const Field& f) {
        int v = f[0] - 'a';
        int h = f[1] - '1';
        matrix[v][h] = false;
    }

    MoveList filterPossible(const MoveList& moves) const {
        MoveList mvs;
        for (Field f : moves) {
            int v = f[0] - 'a';
            int h = f[1] - '1';
            if (0 <= v && v < size && 0 <= h && h < size && !matrix[v][h]) {
                mvs.push_back(f);
            }
        }
        return mvs;
    }

    ~Board() {
        for (int i = 0; i < size; ++i) {
            delete [] matrix[i];
        }
        delete [] matrix;
    }
};


class Knight 
{
public:
    static MoveList moves(const Field& pos) {

        MoveList mvs = {
            {static_cast<char>(pos[0] + 2), static_cast<char>(pos[1] + 1)},
            {static_cast<char>(pos[0] + 2), static_cast<char>(pos[1] - 1)},
            {static_cast<char>(pos[0] - 2), static_cast<char>(pos[1] + 1)},
            {static_cast<char>(pos[0] - 2), static_cast<char>(pos[1] - 1)},
            {static_cast<char>(pos[0] + 1), static_cast<char>(pos[1] + 2)},
            {static_cast<char>(pos[0] + 1), static_cast<char>(pos[1] - 2)},
            {static_cast<char>(pos[0] - 1), static_cast<char>(pos[1] + 2)},
            {static_cast<char>(pos[0] - 1), static_cast<char>(pos[1] - 2)}
        };

        return mvs;
    }
};


int main() 
{
    int n;
    std::cin >> n;

    if (n == 1) {
        std::cout << "a1" << std::endl;
        return 0;
    }

    if (n < 5) {
        std::cout << "IMPOSSIBLE" << std::endl;
        return 0;
    }

    Board    board(n);
    MoveList history;
    history.reserve(n*n);

    Field next = "a1";
    for (int minAvailableMoves = n*n; minAvailableMoves > 0; ) {

        board.hold(next);
        history.push_back(next);
        
        minAvailableMoves = n*n;
        for (auto field : board.filterPossible(Knight::moves(next))) {

            board.hold(field);
            int moves = board.filterPossible(Knight::moves(field)).size();
            board.release(field);

            if (!moves) {
                minAvailableMoves = 0;
                board.hold(field);
                history.push_back(field);
                break;
            }
            
            if (moves < minAvailableMoves) {
                minAvailableMoves = moves;
                next = field;
            }
        }
    }
    
    for (auto f : history) {
        std::cout << f << std::endl;
    }

    return 0;
}