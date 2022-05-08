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
    bank.open("C:\\Users\\HP Omen\\CLionProjects\\Lesson19\\words.txt", std::ios::binary);
    while(!bank.eof()){
        bank >> lotr;
        vec.push_back(lotr);
    }
    bank.close();
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == keyWord){
            counter++;
        }
    }
    std::cout << "word count is " << counter;
    return 0;
}
