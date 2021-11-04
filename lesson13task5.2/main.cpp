#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    int q;
    int co = 0;
    std::cin >> q;
    while (q != -1){
        if(q == 1){
            std::cin >> q;
            vec.push_back(q);
            ++co;
        } else {
            if (q == 2){
                vec.clear();
            } else {
                if (q == 3){
                    std::cout << co << " elements added" << std::endl;
                }
            }
        }
        std::cin >> q;
    }
}