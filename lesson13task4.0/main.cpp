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
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i) {
        int mark;
        std::cin >> mark;

        while(vec.size() != 0 && vec[vec.size() - 1] < mark){
            vec.pop_back();
        }
        vec.push_back(mark);
    }
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
}