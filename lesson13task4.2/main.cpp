#include <iostream>
#include <vector>

int main() {
    int mark = 0;
    std::vector<int> vec;
    while (mark != -1){
        std::cin >> mark;
        while(vec.size() != 0 && mark > vec[vec.size() - 1]){
            vec.pop_back();
        }
        vec.push_back(mark);
    }
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
}