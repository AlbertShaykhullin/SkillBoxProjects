/*
Задание 1. Реализация шифра Цезаря

        Что нужно сделать
В древности для шифрования сообщений использовался такой способ: все буквы в сообщении сдвигались на одно и то же число позиций в алфавите.
Число позиций могло быть как положительным, так и отрицательным и являлось параметром шифра. Если для сдвига на данное число позиций алфавита
не хватает, то он зацикливается (то есть буква с номером 27 — это снова буква «a», буква с номером 28 — это «b» и так далее).

Например, слово abracadabra при сдвиге на 10 позиций превратится в klbkmknklbk. Этот простейший шифр называется шифром Цезаря.
 Регистр букв (заглавные и строчные) менять не нужно. Напишите функцию encrypt_caesar от строки и числа, которая возвращает исходную строку,
 зашифрованную шифром Цезаря с параметром, равным данному числу. Также напишите функцию decrypt_caesar, выполняющую обратное преобразование.
 Считаем, что входные строки состоят лишь из английских букв; если там содержатся и другие символы, то их надо игнорировать.

Пример 1

The quick brown fox jumps over the lazy dog

        Результат:

Ymj vznhp gwtbs ktc ozrux tajw ymj qfed itl

*/

#include <iostream>

char correct_char_shift(char input, int position){
    std::abs(position) > 26 ? position = position % 26 : position;
    int output = (int)input + position;
    if (input >= 'a' && input <= 'z' ){
        output > 'z'? output = output - ('z' - 'a' + 1) : output;
        output < 'a'? output = output + 'z' - 'a' + 1 : output;
        return (char)output;
    } else if (input >= 'A' && input <= 'Z'){
        output > 'Z'? output = output - ('Z' - 'A' + 1) : output;
        output < 'A'? output = output + 'Z' - 'A' + 1 : output;
        return (char)output;
    } else {
        return input;
    }
}

std::string encrypt_caesar(std::string input, int position){
    std::string output = "";
    for (int i = 0; i < input.length(); i++){
            output = output + correct_char_shift(input[i], position);
    }
    return output;
}
std::string decrypt_caesar(std::string input, int position){
    return encrypt_caesar(input, -position);
}


int main() {
    std::string input;
    int position;
    std::cout << "Input the text:" << std::endl;
    std::getline(std::cin, input);
    std::cout << "Input shift:" << std::endl;
    std::cin >> position;
    position > 255 ? position = position % 255 : position;
    std::string result1 = encrypt_caesar(input,position);
    std::string result2 = decrypt_caesar(result1,position);
    std::cout << "Encrypted text:" << std::endl;
    std::cout << result1 << std::endl;
    std::cout << "Decrypted text:" << std::endl;
    std::cout << result2 << std::endl;
}
