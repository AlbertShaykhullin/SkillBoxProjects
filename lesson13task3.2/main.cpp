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
std::vector<int> remove_from_position (std::vector<int> vec, int position) {
    std::vector<int> newVec(vec.size() - 1);
    for (int i = 0; i < position; ++i) {
        newVec[i] = vec[i];
    }
    for (int i = position + 1; i < vec.size(); ++i) {
        newVec[i-1] = vec[i];
    }
    return newVec;
}
int main() {
    int count = 0;
    std::cout << "Enter robots count" << std::endl;
    std::cin >> count;
    std::vector<int> vec(count);
    for (int i = 0; i < count; ++i) {
        std::cout << "Please, enter your robot: ";
        std::cin >> vec[i];
    }
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    int num = 0;
    while (num != -1){
        std::cout << "Which robot is bought?";
        std::cin >> num;
        vec = remove_from_position(vec, num);
        for (int i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << " ";
        }
        std::cout << "Which robot is bring to shelf?";
        std::cin >> num;
        vec = add_to_position(vec, num, vec.size());
        for (int i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << " ";
        }
    }
}