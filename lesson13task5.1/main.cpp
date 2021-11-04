#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    int q;
    std::cin >> q;
    while (q != -1){
        if(q == 1){
            std::cin >> q;
            vec.push_back(q);
        } else {
            if (q == 2){
                if(vec.empty()){
                    std::cout << "Error, vector is empty" << std::endl;
                } else {
                    vec.pop_back();
                }
            } else {
                if (q == 3){
                    if(vec.empty()){
                        std::cout << "Error, vector is empty" << std::endl;
                    } else {
                        std::cout << vec.front() << " " << vec.back() << std::endl;
                    }
                }
            }
        }
        std::cin >> q;
    }
}