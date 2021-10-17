/*
Задание 2. Проверка корректности email-адреса


Что нужно сделать
Напишите программу, которая проверяет корректность email-адреса, введённого пользователем.

Согласно международным требованиям, корректный email-адрес должен состоять из двух частей, разделённых знаком @.
 Первая часть должна иметь длину не менее одного и не более 64 символов, вторая часть — не менее одного и не более 63 символов.
 Из символов допускаются только английские буквы, цифры и знак «-» (дефис), а также точка. Точка не может быть первым или последним символом,
 а кроме того, две точки не могут идти подряд. В первой части (которая предшествует символу @), кроме вышеперечисленных, разрешены ещё следующие символы:

!#$%&'*+-/=?^_`{|}~
Пользователь вводит строку, задающую email-адрес. Программа должна вывести слово Yes, если адрес корректен, а в противном случае — слово No.

Советы и рекомендации
Активно используйте оператор индексации строки str[i], но помните что индексы начинаются с нуля, а не с единицы.
Создайте отдельные функции, которые выдают первую и вторую части адреса для их последующего анализа.
Для валидации отдельных символов внутри части используйте дополнительные строки-словари, состоящие из всех корректных символов для соответствующей части.
*/

#include <iostream>
bool is_dog_in_email(std::string input){
    for (int i = 0; i < input.length(); i++){
        if (input[i] == '@') {
            return true;
        } else {
            return false;
        }
    }
}

int dog_position(std::string input){
    for (int i = 0; i < input.length(); i++){
        if (input[i] == '@') {
            return i;
        }
    }
}

std::string first_part_email(std::string input){
    std::string output = "";
    for (int i = 0; i < dog_position(input); i++){
        output = output + input[i];
    }
}
std::string second_part_email(std::string input){
    std::string output = "";
    for (int i = dog_position(input); i < input.length(); i++){
        output = output + input[i];
    }
}

bool two_points (std::string input) {
    for (int i = 0; i < input.length() - 1; i++){
        if (input[i] == '.' && input[i+1] == '.'){
            return true;
        }
    }
    return false;
}

bool part_validation (std::string input, std::string rightSpells, int maxLength){
    if (firstPart.length() == 0 || input.length() > maxLength){
        return false;
    } else if (firstPart[0] == '.' || firstPart[firstPart.length()] == '.' || two_points(input)){
        return false;
    } else {
        for (int i = 0; i < input.length(); i++){
            bool is_match = false;
            for (int j = 0; j < rightSpells.length && !is_match; j++) {
                if (firstPart[i] == rightSpells[j]){
                    is_match = true;
                }
            }
            is_match ? is_match :  return false;
        }
        return true;
    }
}


int main() {
    std::string input;
    bool validation = true;
    std::string firstPartRightSpells = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&'*+-/=?^_`{|}~";
    std::string secondPartRightSpells = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::cout << "Input the email address:" << std::endl;
    std::cin >> input;
    if (!is_dog_in_email(input)){
        validation = false;
    } else if (!part_validation(first_part_email(input,firstPartRightSpells, 64))){
        validation = false;
    } else if (!part_validation(second_part_email(input,secondPartRightSpells, 63))){
        validation = false;
    } else {
        validation = true;
    }
    validation ? std::cout << "Yes" << std::endl : std::cout << "No" << std::endl;
}
