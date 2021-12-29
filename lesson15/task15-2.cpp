#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 1, 1, 5, 5, 7, 4, 6, 1, 5};

    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] != -1){
            for (int j = i + 1; j < vec.size(); ++j) {
                if (vec[j] == vec[i]){
                    vec[j] = -1;
                }
            }
        }
    }

    int res = 0;
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] != -1){
            ++res;
        }
    }
    std::cout << res << std::endl;
    return 0;
}
