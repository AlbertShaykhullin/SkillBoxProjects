#include <iostream>
#include <vector>

void print_vector(std::vector<int> vec){
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec;
    int input = 0;
    while (input != -1){
        if(vec.size() >= 20){
            vec.erase(vec.cbegin());
            std::cout << "Input new element:";
            std::cin >> input;
            vec.push_back(input);
        } else {
            std::cout << "Input new element:";
            std::cin >> input;
            vec.push_back(input);
        }
        //print_vector(vec);
    }
    print_vector(vec);
    return 0;
}