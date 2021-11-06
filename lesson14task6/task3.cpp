#include <iostream>

int main() {
    int array[5][5];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            array[j][i] = std::abs(j - i%2 * 4) + 5*i;
        }
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << array[j][i] << " ";
        }
        std::cout << std::endl;
    }
}
