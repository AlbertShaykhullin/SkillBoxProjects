#include <iostream>
#include <ctime>
#include <fstream>


int main(){
    int height;
    int width;
    std::srand(std::time(nullptr));
    std::ofstream file("E:\\pic.txt");
    std::cin >> height >> width;
    int arr[height][width];
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            arr[i][j] = rand() % 2;
        }
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            file << arr[i][j] << " ";
        }
        file << std::endl;
    }
}