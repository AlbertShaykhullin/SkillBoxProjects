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

std::vector<int>  sort_vect (std::vector<int> vec) {
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
std::vector<int> insert_vec(std::vector<int>vectemp, std::vector<int>vec){
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] <= vectemp[4]){
            vectemp.push_back(vec[i]);
        }
    }
    vectemp = sort_vect(vectemp);
    while (vectemp.size() > 5){
        vectemp.pop_back();
    }
    return vectemp;
}

int main() {
    std::vector<int> vec;
    std::vector<int> vectemp;
    std::string input;
    int command;
    std::cout << "Please, enter 5 numbers minimum" << std::endl;
    std::getline (std::cin, input);
    vectemp = input_vec(input);
    command = vectemp[vectemp.size()-1];
    if (command == -1 || command == -2){
        vectemp.pop_back();
    }
    vectemp = sort_vect(vectemp);
    while (vectemp.size() > 5){
        vectemp.pop_back();
    }
    if (command == -1) {
        std::cout << vectemp[4] << std::endl;
    } else if(command == -2){
        std::cout << vectemp[4] << std::endl;
        return 0;
    }
    do{ std::getline (std::cin, input);
        vec = input_vec(input);
        command = vec[vec.size()-1];
        if (command == -1 || command == -2){
            vectemp.pop_back();
        }
        vectemp = insert_vec(vectemp,vec);
        if (command == -1 || command == -2) {
            std::cout << vectemp[4] << std::endl;
        }
    } while (command != -2);

    return 0;
}