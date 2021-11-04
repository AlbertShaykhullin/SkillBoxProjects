#include <iostream>
#include <vector>

std::vector<float> full_price (std::vector<float> price, std::vector<int> buy){
    std::vector<float> result;
    for (int i = 0; i < buy.size(); ++i){
        result.push_back(price[buy[i]]);
    }
    return result;
}

float sum_elements(std::vector<float> vec){
    float sum = 0;
    for (int i = 0; i < vec.size(); ++i) {
        sum += vec[i];
    }
    return sum;
}

void print_vector(std::vector<float> vec){
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<float> price = {2.5, 4.25, 3.0, 10.0};
    std::vector<int> buy = {1, 1, 0, 3};
    std::vector<float> result = full_price(price, buy);
    print_vector(result);
    std::cout << "Summary:" << sum_elements(result);
}