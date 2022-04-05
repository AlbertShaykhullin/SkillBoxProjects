#include <iostream>
#include <sstream>


int main() {
    float first_part;
    float second_part;
    float result;
    char delimiter;
    std::string input;
    std::stringstream text;
    std::cin >> input;
    text << input;
    text >> first_part >> delimiter >> second_part;
    if (delimiter == '*'){
        result = first_part*second_part;
    } else if (delimiter == '/'){
        result = first_part/second_part;
    } else if (delimiter == '+'){
        result = first_part+second_part;
    } else if (delimiter == '-'){
        result = first_part-second_part;
    } else {
        std::cout << "Error, unknown delimiter" << std::endl;
    }
    std::cout << first_part << " " << delimiter << " " << second_part << " = " << result << std::endl;
    return 0;
}