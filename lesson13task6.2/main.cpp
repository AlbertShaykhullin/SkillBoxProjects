#include <iostream>
#include <vector>

std::vector<float> full_price (std::vector<float> price, std::vector<int> purchase){
    std::vector<float> result;
    for (int i = 0; i < purchase.size(); ++i){
        result.push_back(price[purchase[i]]);
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

void print_vector_float(std::vector<float> vec){
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}
void print_vector_int(std::vector<int> vec){
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}


int main() {
    std::vector<float> price = {2.5, 4.25, 3.0, 10.0};
    std::vector<int> purchase = {1, 1, 0, 3};
    std::vector<float> result = full_price(price, purchase);
    print_vector_float(price);
    print_vector_int(purchase);
    print_vector_float(result);
    std::cout << "Summary:" << sum_elements(result);
}