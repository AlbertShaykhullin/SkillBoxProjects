#include <iostream>
#include <vector>
#include <string>

std::vector<int> input_vec (std::string input) {
    std::string temp = "";
    std::vector<int> vec;
    for (int i = 0; i < input.size(); ++i) {
        if(input[i] != ' '){
            temp.push_back(input[i]);
        } else {
            vec.push_back(std::stoi(temp));
            temp = "";
        }
    }
    vec.push_back(std::stoi(temp));
    return vec;
}

std::vector<int> sort_vec (std::vector<int> vec) {
    for (int i = vec.size()-1; i >= 0; i--) {
        int maxind = 0;
        for (int j = 0; j <= i; ++j) {
            if (vec[j] > vec[maxind]){
                maxind = j;
            }
        }
        int temp = vec[i];
        vec[i] = vec[maxind];
        vec[maxind] = temp;
    }
    return vec;
}

int main() {
    std::vector<int> vec;
    std::vector<int> vectemp;
    std::string input;
    int command;
    std::cout << "Please, enter 5 numbers minimum" << std::endl;
    do{
        std::getline (std::cin, input);
        vectemp = input_vec(input);
        command = vectemp[vectemp.size()-1];
        if (command == -1){
            vectemp.pop_back();
        }
        for (int i = 0; i < vectemp.size(); ++i) {
            vec.push_back(vectemp[i]);
        }
        if (vec.size() < 6 ) {
            std::cout << "Error, not enough numbers, must be entered 5 numbers minimum"<< std::endl;
            std::cout << "Please, enter more numbers" << std::endl;
        } else {
            vec = sort_vec(vec);
            if (command == -1) {
                std::cout << vec[4] << std::endl;
            }
        }
    } while (command != -2);

    return 0;
}