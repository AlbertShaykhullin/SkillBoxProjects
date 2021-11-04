#include <iostream>
#include <vector>

int main() {
    int mark = 0;
    std::vector<int> vec;
    for (int i = 0; i < 200; ++i) {
        vec.push_back(i);
        std::cout << "Vector capacity: " << vec.capacity() << " vector size " << vec.size() << std::endl;
        if (vec.capacity() - vec.size() == 2){
            std::cout << "It's only 2 free space!" << std::endl;
        }
    }
}