#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main() {
    std::vector<int> vec = {-100,-50, -5, 1, 10, 15};

    for (int i = vec.size()-1; i >= 0; i--) {
        int maxind = 0;
        for (int j = 0; j <= i; ++j) {
            if (abs(vec[j]) > abs(vec[maxind])){
                maxind = j;
            }
        }
        int temp = vec[i];
        vec[i] = vec[maxind];
        vec[maxind] = temp;
    }
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    return 0;
}