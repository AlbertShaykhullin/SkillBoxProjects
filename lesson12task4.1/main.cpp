#include <iostream>

int main() {
    int apartmentNumber[] = {0, 0, 0};
    std::string house[10];
    for (int i = 0; i < 10; i++){
        std::cin >> house[i];
    }
    for (int i = 0; i < 3; i++){
        std::cin >> apartmentNumber[i];
        if (apartmentNumber[i] > 10 || apartmentNumber[i] < 1) {
            std::cout << "Error! wrong number of apartment" << std::endl;
        } else {
            std::cout << house[apartmentNumber[i]-1] << std::endl;
        }
    }
}