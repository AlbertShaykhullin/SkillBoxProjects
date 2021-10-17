/*
Что нужно сделать
Проверьте, задаёт ли введённая пользователем строка корректный IP-адрес четвёртой версии (IPv4).
IP-адрес должен представлять из себя четыре числа, разделённые точками без пробелов, причём каждое число должно быть в диапазоне от 0 до 255 включительно.
Числа не должны содержать ведущих нулей. Других символов в строке, кроме вышеописанных, присутствовать не должно.

Пользователь вводит строку, задающую ip-адрес. Программа должна вывести слово Yes, если адрес корректен, и слово No, если это не так.
Советы и рекомендации
Активно используйте оператор индексации строки str[i], но помните что индексы начинаются с нуля, а не с единицы.
Создайте отдельную функцию для получения отдельных чисел из IP-адреса и валидируйте эти отдельные числа.
Для валидации отдельных цифр у чисел следует использовать оператор сравнения с константами символов. Символы от ‘0’ до ‘9’
расположены последовательно и поэтому уместные операторы <= и >=.
*/

#include <iostream>
//Определяем позицию точки в IP адресе, в слчае когда вызывается 0-я точка или 4-я точка, возвращается 0 и длина строки соответственно для корректной работы ip_number.
int dot_position (std::string input, int dotNumber){
    int dotCounter = 0;
    if (dotNumber == 0){
        return -1;
    } else if (dotNumber == 4){
        return input.length();
    } else {
        for (int i = 0; i < input.length();i++){
            if (input[i] == '.'){
                dotCounter++;
                if (dotCounter == dotNumber){
                    return i;
                }
            }
        }
    }
}
// Вытаскиваем число по порядковому номеру из ip адреса
std::string ip_number(std::string input, int numberCount){
    int startDotPosition = dot_position(input, numberCount - 1) + 1;
    int endDotPosition = dot_position(input, numberCount);
    std::string output = "";
    for (int i = startDotPosition; i < endDotPosition; i++){
        output += input[i];
    }
    return output;
}
// Проверяем на правильность число, чтобы в нем не присутствовали другие символы
bool number_validation(std::string input){
    if (input == "") {
        return false;
    } else {
        for (int i = 0; i < input.length(); i++) {
            if (input[i] < '0' || input[i] > '9'){
                return false;
            }
        }
    }
    return true;
}
// Проверяем на правильность число из ip адреса под условие от 0 до 255 и чтобы 0 не был первым знаком в числе.
bool ip_number_validation (std::string input){
    if (!number_validation(input)){
        return false;
    } else {
        int inputNumber = std::stoi(input);
        if (inputNumber > 255 || inputNumber < 0){
            return false;
        } else if (input.length() > 1 && input[0] == '0'){
            return false;
        } else {
            return true;
        }
    }
}

int main() {
    std::string input;
    std::cout << "Input the IP-address:" << std::endl;
    std::cin >> input;
    if (ip_number_validation(ip_number(input,1)) && ip_number_validation(ip_number(input,2))
        && ip_number_validation(ip_number(input,3)) && ip_number_validation(ip_number(input,4))){
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    return 0;
}
