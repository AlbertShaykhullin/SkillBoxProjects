#include <iostream>

int main() {
    std::string house[2];
    for (int i = 0; i < 2; i++){
        std::cin >> house[i];
    }
    for (int i = 0; i < 2; i++){
        std::cout << house[i] << std::endl;
    }
}