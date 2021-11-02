#include <iostream>
#include <vector>


std::vector<int> addl (std::vector<int> vec, int val) {
    std::vector<int> newVec(vec.size() + 1);
    for (int i = 0; i < vec.size(); ++i) {
        newVec[i] = vec[i];
    }
    newVec[newVec.size()-1] = val;
    return newVec;
}
int main() {
    std::vector<int> vec = {};
    int num = 0;
    int summary = 0;
    do{
        std::cout << "Enter age of patient:";
        std::cin >> num;
        if(num <= 0){
            break;
        } else {
            vec = addl(vec, num);
        }
    } while (num > 0);
    for (int i = 0; i < vec.size(); ++i) {
        summary += vec[i];
    }
    std::cout << summary << " " << summary/vec.size() << " " << vec.size();
}


