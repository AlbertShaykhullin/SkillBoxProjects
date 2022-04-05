#include <iostream>
#include <sstream>
#include <cmath>

int power_second_part(int second_part){
    int counter = 0;
    while(second_part > 0){
        second_part /= 10;
        counter++;
    }
    return counter;
}

int main() {
    int first_part;
    int second_part;
    double result;
    std::cin >> first_part >> second_part;
    result = first_part + second_part*pow(10, -power_second_part(second_part));
    std::cout << result << std::endl;
    return 0;
}