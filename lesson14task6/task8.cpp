#include <iostream>
#include <array>

void enter_height (int cube[5][5][10]){
    int height = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            while (true){
                std::cout << "Enter height for block " << i << " " << j << std::endl;
                std::cin >> height;
                if (height > 10 || height < 0){
                    std::cout << "Error enter valid height" << std::endl;
                } else{
                    for (int k = 0; k < 10; ++k) {
                        if (k < height){
                            cube[i][j][k] = 1;
                        } else {
                            cube[i][j][k] = 0;
                        }
                    }
                    break;
                }
            }
        }
    }
}

void horizontal_section (int cube[5][5][10], int section[5][5], int layer){
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            section[i][j] = cube[i][j][layer];
        }
    }
}

void print_array (int section[5][5]){
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << section[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int cube [5][5][10];
    int section[5][5];
    int layer = 0;
    enter_height(cube);
    std::cout << "Enter layer" << std::endl;
    std::cin >> layer;
    horizontal_section(cube,section,layer);
    print_array(section);
}