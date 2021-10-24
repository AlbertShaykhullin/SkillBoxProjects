/*
Активно используйте оператор индексации строки str[i], но помните что индексы начинаются с нуля, а не с единицы.
Создайте отдельную функцию для получения целой и дробной частей числа. Её можно сделать на основе задачи об IP-адресах,
т.к. там тоже использовалась точка в качестве разделителя.
Для сравнения дробных частей можно создать специальную функцию безопасного доступа к символу строки по индексу.
Для дробных чисел, если этот индекс больше длины дробной части, данная функция может безопасно вернуть 0.
*/


#include <iostream>


bool float_number_validation (std::string input){
    bool isFloat = true;
    bool point = false;
    int numberCount = 0;
    if (input[0] != '.' && input[0] != '-' && (input[0] > '9' || input [0] < '0')){
        isFloat = false;
    } else {
        if (input[0] == '.'){
            point = true;
        } else if (input[0] <= '9' && input[0] >= '0'){
            numberCount++;
        }
        for (int i = 1; (i < input.length()) && isFloat; i++){
            if(input[i] == '.' && point == true){
                isFloat = false;
            } else if (input[i] == '.' && point == false){
                point = true;
            } else if ((input[i] < '0' || input[i] > '9') && input[i] != '.'){
                isFloat = false;
            } else if (input[i] <= '9' && input[i] >= '0'){
                numberCount++;
            }
        }
    }
    if (isFloat && (numberCount > 0)){
        return true;
    } else {
        return false;
    }
}

int dot_position (std::string input){
    for (int i = 0; i < input.length();i++) {
        if (input[i] == '.') {
            return i;
        }
    }
    return input.length();
}

std::string first_part_float (std::string input){
    int dotPosition = dot_position(input);
    std::string output = "";
    for (int i = 0; i < dotPosition; i++){
        output += input[i];
    }
    return output;
}
std::string second_part_float (std::string input){
    int dotPosition = dot_position(input);
    std::string output = "";
    for (int i = dotPosition + 1; i < input.length(); i++){
        output += input[i];
    }
    return output;
}

char safe_fractional_part(std::string input, int position){
    if (position > input.length()-1 || input == ""){//fixed
        return '0';
    } else {
        return input[position];
    }
}

std::string first_part_compairson(std::string input1, std::string input2){
    int firstPartFloat1 = std::stoi(first_part_float(input1));
    int firstPartFloat2 = std::stoi(first_part_float(input2));
    if (firstPartFloat1 > firstPartFloat2) {
        return "More";
    } else if (firstPartFloat1 < firstPartFloat2){
        return "Less";
    } else {
        return "Equal";
    }
}

std::string second_part_compairson(std::string input1, std::string input2){
    std::string secondPartFloat1 = second_part_float(input1);
    std::string secondPartFloat2 = second_part_float(input2);
    int inputLength = 0;
    if (input1.length() > input2.length()){
        inputLength = secondPartFloat1.length();
    } else {
        inputLength = secondPartFloat2.length();
    }
    for (int i = 0; i < inputLength; i++){
        if (safe_fractional_part(secondPartFloat1, i) > safe_fractional_part(secondPartFloat2, i)){
            return "More";
        } else if (safe_fractional_part(secondPartFloat1, i) < safe_fractional_part(secondPartFloat2, i)){
            return "Less";
        }
    }
    return "Equal";
}

int main() {
    std::string input1;
    std::string input2;
    std::cout << "Input first float number:" << std::endl;
    std::cin >> input1;
    std::cout << "Input second float number:" << std::endl;
    std::cin >> input2;
    if(float_number_validation(input1) && float_number_validation(input2)){
        std::string firstPartCompairson = first_part_compairson(input1, input2);
        if (firstPartCompairson == "More"){
            std::cout << "More" << std::endl;
        } else if (firstPartCompairson == "Less"){
            std::cout << "Less" << std::endl;
        } else {
            std::string secondPartCompairson = second_part_compairson(input1, input2);
            if (secondPartCompairson == "More"){
                std::cout << "More" << std::endl;
            } else if (secondPartCompairson == "Less"){
                std::cout << "Less" << std::endl;
            } else {
                std::cout << "Equal" << std::endl;
            }
        }
    } else {
        std::cout << "Invalid float number" << std::endl;
    }
}