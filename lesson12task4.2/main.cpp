#include <iostream>

int main() {
    int numbers[15] = {114, 111, 106, 107, 108, 105, 115,  108, 110, 109, 112, 113, 116, 117, 118};
    int numbers2[15] = {0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0};
    int x = numbers[0];
    int result = 0;
    for(int i = 0; i < 15; i++){
        if (numbers[i] < x){
            x = numbers[i];
        }
    }

    for(int i = 0; i < 15; i++){
        if(numbers2[numbers[i] - x] == 0){
            numbers2[numbers[i] - x] = numbers[i] - x;
        } else {
            result = i;
        }
    }

    std::cout << "Duplicate " << numbers[result] << std::endl;
    std::cout << "X " << x << std::endl;
}
