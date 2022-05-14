#include <fstream>
#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> vec;
    std::string lotr;
    std::ifstream bank;
    int counter = 0;
    std::string keyWord;
    std::cout << "Enter name of LOTR person " << std::endl;
    std::cin >> keyWord;
    bank.open("words.txt", std::ios::binary);
    if (!bank.is_open()){
        std::cout << "Error, file is not exist" << std::endl;
    } else {
        while(!bank.eof()){
            bank >> lotr;
            if (lotr == keyWord){
                counter++;
            }
        }
        bank.close();
        std::cout << "word count is " << counter;
    }

    return 0;
}
