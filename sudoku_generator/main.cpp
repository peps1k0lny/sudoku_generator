#include <iostream>

bool check(int a, short field[9][9], int y, int x);

void func(short field[9][9], int y, int x, long long &count) {
    
    if (y == 8 and x == 9) {
        ++count;
        std::cout << count << std::endl;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                std::cout << field[i][j] << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << "----------" << std::endl;
        return;
    }
    
    if (x == 9) {
        x = 0;
        ++y;
    }
    
    for (int a = 1; a < 10; ++a) {
        if (check(a, field, y, x) == 1) {
            field[y][x] = a;
            func(field, y, x + 1, count);
        }
    }
}
        
bool check(int a, short field[9][9], int y, int x) {
    
    for (int i = 0; i < x; ++i) {
        if (a == field[y][i]) return 0;
    }
    
    for (int i = 0; i < y; ++i) {
        if (a == field[i][x]) return 0;
    }
    int x1 = x - x % 3, y1 = y - y % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (x == j + x1 and y == i + y1) break;
            if (a == field[i + y1][j + x1]) {
                return 0;
            }
        }
    }
    return 1;
}



int main() {
    std::cout << "Оч крутая штука" << std::endl;
    short field[9][9];
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            field[i][j] = 0;
        }
    }
    long long count = 0;
    func(field, 0, 0, count);
}
