#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {7, 1, 5, 4, 6, 3};
    int pr = 0;
    int min_w = vec[0];
    for (int i = 1; i < vec.size(); ++i) {
        if(vec[i]-vec[i - 1] > 0){
            pr += vec[i] - vec[i - 1];
        }
    }

    std::cout << pr << std::endl;
    return 0;
}
