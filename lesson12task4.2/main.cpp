#include <iostream>

int main() {
    int numbers[15] = {114,111, 106, 107, 108, 105, 115,  108, 110, 109, 112, 113, 116, 117, 118};
    int x = numbers[0];
    int result = 0;
    for(int i = 0; i < 15; i++){
        if (numbers[i] < x){
            x = numbers[i];
        }
    }
    for (int j = 0; j < 15; ++j) {
        int counter = 0;
        for(int i = 0; i < 15; i++){
            if ((x + j) == numbers[i]){
                counter++;
                if(counter == 2){
                    result = x + j;
                    break;
                }
            }
        }
    }
    std::cout << "Duplicate " << result << std::endl;
    std::cout << "X " << x << std::endl;
    return 0;
}
