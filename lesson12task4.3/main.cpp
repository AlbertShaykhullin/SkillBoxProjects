#include <iostream>

int main() {
    float input[15];
    std::cout << "Input:";
    for (int i = 0; i < 15; ++i) {
        std::cin >> input[i];
    }
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 14; ++j) {
            if(input[j + 1] < input[j]){
                float buffer = input[j + 1];
                input [j + 1] = input[j];
                input[j] = buffer;
            }
        }
    }
    std::cout << "Output:";
    for (int i = 0; i < 15; ++i) {
        std::cout << input[i] << " ";
    }
    return 0;
}
