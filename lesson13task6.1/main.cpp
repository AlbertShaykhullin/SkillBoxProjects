#include <iostream>
#include <vector>

std::vector<int> erase_element (std::vector<int> vec, int deleted){
    for (int i = 0; i < vec.size(); ++i) {
        while(vec[i] == deleted && i < vec.size()){
            vec.erase(vec.cbegin() + i);
        }
    }
    return vec;
}

void print_vector(std::vector<int> vec){
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int count = 0;
    int input = 0;
    int deleted = 0;
    std::cout << "Enter vector size:";
    std::vector<int> vec;
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        std::cout << "Enter vector number:";
        std::cin >> input;
        vec.push_back(input);
    }
    print_vector(vec);
    std::cout << "Enter number to delete:";
    std::cin >> deleted;
    vec = erase_element(vec, deleted);
    print_vector(vec);
    return 0;
}