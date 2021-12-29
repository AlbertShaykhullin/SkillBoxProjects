#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {2, 7, 11, 15};
    int result = 9;
    int resulti = 0;
    int resultj = 0;

    for (int i = 0; i < vec.size(); i++) {

        for (int j = i; j < vec.size(); ++j) {
            if (result == vec[i] + vec[j]){
                resulti = i;
                resultj = j;
                break;
            }
        }
    }

    std::cout << vec[resulti] << " " << vec[resultj];

    return 0;
}
