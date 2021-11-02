#include <iostream>

int main() {
    float input[4];
    for (int i = 0; i < 4; ++i) {
        std::cin >> input[i];
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(input[j + 1] < input[j]){
                float buffer = input[j + 1];
                input [j + 1] = input[j];
                input[j] = buffer;
            }
        }
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
