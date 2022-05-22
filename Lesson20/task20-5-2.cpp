#include <iostream>
#include <ctime>
#include <fstream>


int main(){
    int height;
    int width;
    std::srand(std::time(nullptr));
    std::ofstream file("pic.txt");
    if (file.is_open()){
        std::cin >> height >> width;
        int arr[height][width];
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                file << rand() % 2 << " ";
            }
            file << std::endl;
        }
    }else {
        std::cout << "File is not exist" << std::endl;
    }

}