#include <iostream>
#include <vector>


std::vector<int> add_to_position (std::vector<int> vec, int val, int position) {
    std::vector<int> newVec(vec.size() + 1);
    for (int i = 0; i < position; ++i) {
        newVec[i] = vec[i];
    }
    newVec[position] = val;
    for (int i = position + 1; i < (vec.size() + 1); ++i) {
        newVec[i] = vec[i - 1];
    }
    return newVec;
}
int main() {
    std::vector<int> vec = {3, 4 , 35, 19, 1, 45, 66, 74, 11, 12};
    int num = 0;
    int position = 0;
    while(num != -1){
        std::cout << "Please, enter your robot: ";
        std::cin >> num;
        if(num != -1) {
            std::cin >> position;
            vec = add_to_position(vec, num, position);
        } else {
            vec = add_to_position(vec, num, vec.size());
        }
    }
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
}


