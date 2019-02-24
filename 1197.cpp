#include <iostream>
#include <cstdlib>
#include <vector>

class Field 
{
public:
    char v, h;

    Field() = default;
    Field(char v, char h) : v(v), h(h) {}

    bool isCorrect() {
        if('a' <= v && v <= 'h' && '1' <= h && h <= '8') {
               return true;
        }
        return false;
    }
};


class Knight 
{
public:
    Field f;

    Knight() = default;
    Knight(Field f) : f(f) {}

    std::vector<Field> fieldsUnderAttack()
    {
        Field underAttack[8] = {
            Field(f.v + 2, f.h + 1),
            Field(f.v + 2, f.h - 1),
            Field(f.v - 2, f.h + 1),
            Field(f.v - 2, f.h - 1),
            Field(f.v + 1, f.h + 2),
            Field(f.v + 1, f.h - 2),
            Field(f.v - 1, f.h + 2),
            Field(f.v - 1, f.h - 2),
        };

        std::vector<Field> vec;
        for(Field f: underAttack) {
            if(f.isCorrect()) {
                vec.push_back(f);
            }
        }

        return vec;
    }
};


int main() 
{
    int test_n;
    std::cin >> test_n;

    Knight k;
    for(int i = 0; i < test_n; ++i) {
        std::cin.get(); // \n
        k.f.v = std::cin.get();
        k.f.h = std::cin.get();
        std::cout << k.fieldsUnderAttack().size() << std::endl;
    }
}