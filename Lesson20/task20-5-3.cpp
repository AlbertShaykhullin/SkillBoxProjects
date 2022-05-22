#include <iostream>
#include <fstream>

int main(){
    std::ifstream in_file("river.txt");
    std::ofstream out_file("basket.txt", std::ios::app);
    if (in_file.is_open() && out_file.is_open()){
        std::string user_fish;
        int count = 0;
        std::cin >> user_fish;
        while(!in_file.eof()){
            std::string current_fish;
            in_file >> current_fish;
            if (current_fish == user_fish){
                out_file << current_fish << std::endl;
                count++;
            }
        }
        std::cout << "Fish count " << count << std::endl;
    }else {
        std::cout << "File is not exist" << std::endl;
    }

}