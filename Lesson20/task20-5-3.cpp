#include <iostream>
#include <fstream>

int main(){
    std::ifstream in_file("E:\\river.txt");
    std::ofstream out_file("E:\\basket.txt", std::ios::app);
    std::string user_fish;
    std::string current_fish;
    int count = 0;
    std::cin >> user_fish;
    while(!in_file.eof()){
        in_file >> current_fish;
        if (current_fish == user_fish){
            out_file << current_fish << std::endl;
            count++;
        }
        current_fish = "";
    }
    std::cout << "Fish count " << count << std::endl;
}