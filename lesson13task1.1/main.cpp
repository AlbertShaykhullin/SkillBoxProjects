#include <iostream>
#include <vector>


std::vector<int> addl (std::vector<int> vec, int val) {
    std::vector<int> newVec(vec.size() + 1);
    for (int i = 0; i < vec.size(); ++i) {
        newVec[i] = vec[i];
    }
    newVec[newVec.size()-1] = val;
    return newVec;
}
int main() {
    std::cout << "How many robots?";

    std::vector<int> vec = {3, 4 , 35, 19, 1};
    int num = 0;
    while(num != -1){
        std::cout << "Please, enter your robot: ";
        std::cin >> num;
        vec = addl(vec, num);
    }
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
}


