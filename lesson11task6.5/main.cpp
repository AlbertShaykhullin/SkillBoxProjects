/*
Задание 5. Анализ результатов игры в крестики-нолики

Что нужно сделать
Петя и Вася играли в крестики-нолики и не стёрли результаты своей игры. Теперь перед вами табличка 3 × 3,
которая осталась после их поединка. Вы хотите понять, выиграл ли кто-то из них или они не доиграли.
На вход программе даётся три строки, кодирующие верхнюю, среднюю и нижнюю строчки игрового поля. Крестик обозначается
символом X (английская заглавная буква X), нолик — символом O (заглавная латинская буква O), пустая клетка — точкой.
Если ввод некорректен, то есть такая таблица не могла получиться в ходе настоящей игры, то надо написать в ответ слово Incorrect.
Если таблица корректна и выиграли крестики, то нужно вывести в ответ слова Petya won, если нолики — то Vanya won,
а иначе (то есть они не доиграли или сыграли вничью) надо написать Nobody.

Примеры
X..
OXO
OOO
Ответ: Incorrect (потому что ноликов в конце игры не может быть больше, чем крестиков).

X..
.X.
OO.
Ответ: Nobody (потому что они не доиграли).

XXO
OOX
XOX
Ответ: Nobody (потому что это ничья).

XO.
XO.
X.O
Ответ: Incorrect (крестики уже победили, и ноликов не может быть столько же).

OX.
XOX
X.O
Ответ: Incorrect (потому что нолики выиграли за три хода, и на поле за это время не могло успеть появиться четыре крестика).

..X
OX.
X.O
Ответ: Petya won.

0..
...
...
Ответ: Incorrect (потому что допускаются только символы X, O и точка, а цифра 0 не является допустимым символом).

Советы и рекомендации
Активно используйте оператор индексации строки str[i], но помните что индексы начинаются с нуля, а не с единицы.
Для того, чтобы обращаться к элементам игрового поля, стоит написать отдельную функцию получения элемента поля по его координатам (x, y).
В таком случае, часть алгоритмов поиска победителя можно обобщить.
Функции проверки поля на корректность можно отделить от функций и алгоритмов проверки победителя.
При достаточной модульности функций, некоторые операции можно реализовать через уже существующие процедуры.
0К примеру, если уже есть проверка победителя в строке и имеется функция получения колонки по индексу,
то функцию поиска победителя в колонке можно реализовать через обе них.
Проход по диагонали поля можно осуществить в цикле, используя счётчик цикла в качестве обоих координат элемента.
Для второй диагонали нужно обратить одну из координат (2 - x или 2 - y).
Общие условия некорректности поля таковы:
Выявлено несколько победителей одновременно
Нолики победили, а крестиков больше чем ноликов
Крестики победили, а ноликов столько же или больше
Нолики и крестики победили несколько раз
На поле есть невалидные символы
*/

#include <iostream>
bool game_field_validation (std::string input){
    if (input.length() != 3){
        return false;
    } else {
        for (int i = 0; i < input.length(); i++){
            if (input[i] != 'X' || input[i] != '.' || input[i] != 'O'){
                return false;
            }
        }
        return true;
    }
}
char game_field_element (std::string firstString, std::string secondSting, std::string thirdString, int x, int y){
    if (x == 0){
        return firstString[y];
    } else if (x == 1){
        return secondSting[y];
    } else if (x == 2){
        return thirdString[y];
    }
}

int win_count_row_column (std::string firstString, std::string secondSting, std::string thirdString,bool row, char character){
    int winCount = 0;
    for (int i = 0; i < 3; i++){
        int count = 0;
        for (int j = 0; j < 3; j++){
            if (row){
                if (game_field_element(firstString, secondSting, thirdString, j, i) == character){
                    count++;
                }
            } else {
                if (game_field_element(firstString, secondSting, thirdString, i, j) == character){
                    count++;
                }
            }
        }
        if (count == 3){
            winCount++;
        }
    }
    return winCount;
}

int win_count_diag (std::string firstString, std::string secondSting, std::string thirdString,bool positive, char character){
    int winCount = 0;
    int count = 0;
    for (int i = 0; i < 3; i++){
        if (positive) {
            if (game_field_element(firstString, secondSting, thirdString, i, i) == character) {
                count++;
            }
        } else {
            if (game_field_element(firstString, secondSting, thirdString, i, 2-i) == character) {
                count++;
            }
        }
    }
    if (count == 3){
        winCount++;
    }
    return winCount;
}

std::string game_won (std::string firstString, std::string secondSting, std::string thirdString){
    int winXCountRow = win_count_row_column(firstString,secondSting,thirdString, true, 'X');
    int winOCountRow = win_count_row_column(firstString,secondSting,thirdString, true, 'O');
    int winXCountColumn = win_count_row_column(firstString,secondSting,thirdString, false, 'X');
    int winOCountColumn = win_count_row_column(firstString,secondSting,thirdString, false, 'O');
    int winXCountDiagPositive = win_count_diag(firstString,secondSting,thirdString, true, 'X');
    int winOCountDiagPositive = win_count_diag(firstString,secondSting,thirdString, true, 'O');
    int winXCountDiagNegative = win_count_diag(firstString,secondSting,thirdString, false, 'X');
    int winOCountDiagNegative = win_count_diag(firstString,secondSting,thirdString, false, 'O');
    int winSumm = winXCountRow+winOCountRow+winXCountColumn+winOCountColumn+winXCountDiagPositive+winOCountDiagPositive+winXCountDiagNegative+winOCountDiagNegative;
    if (winSumm > 1){
        return "Incorrect";
    } else if (winSumm == 0) {
        return "Nobody";
    } else if (winXCountRow == 1 || winXCountColumn == 1 || winXCountDiagPositive == 1 || winXCountDiagNegative == 1) {
        return "Petya won";
    } else if (winOCountRow == 1 || winOCountColumn == 1 || winOCountDiagPositive == 1 || winOCountDiagNegative == 1 ){
        return "Vanya won";
    }
}
int main() {
    std::string firstString;
    std::string secondString;
    std::string thirdString;
    std::cout << "Input first string:" << std::endl;
    std::cin >> firstString;
    std::cout << "Input second string:" << std::endl;
    std::cin >> secondString;
    std::cout << "Input third string:" << std::endl;
    std::cin >> thirdString;
    if (game_field_validation(firstString) && game_field_validation(secondString) && game_field_validation(thirdString)){
        std::cout << game_won(firstString,secondString, thirdString) << std::endl;
    } else {
        std::cout << "Incorrect" << std::endl;
    }
    return 0;
}
