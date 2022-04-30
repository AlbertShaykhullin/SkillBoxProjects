#include <iostream>
#include <string>
#include <vector>
#include <sstream>
// 1 1 1 1
// 1 1 2
// 1 2 1
// 2 1 1
// 2 2

void put_rabbit( int new_place, int* n,const int* L, int R = 3)
{
	// проверка параметров
	if ((new_place < 0)|| (new_place > *L)){
        return;
    }
	// стоп игра!!!
	if (new_place == *L){
        (*n)++;
    }
	// собственно рекурсия
	for (int i = 1; i <= R; i++){
        put_rabbit( new_place + i, n,  L, R);
    }
}

std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

int main(){
    int n = 0;	// количество решений
    int R = 0; // максимальный прыжок
    int L = 5; // длина лестницы
    std::vector<std::string> vec;
    std::string input;
    std::getline(std::cin, input);
    vec = split(input,',');
    L = std::stoi(vec[0]);
    if(vec.size() >=2){
        R = std::stoi(vec[1]);
    }
    if (L < 0){
        std::cout << "Error stair length can't be less then 0";
    } else{
        int* pn = &n;
        int* pR = &R;
        int* pL = &L;
        // количество вариантов
        if (R > 0){
            put_rabbit( 0, pn, pL, R);
            std::cout << "max jump " << R << std::endl;
        }else{
            put_rabbit( 0, pn, pL);
            std::cout << "max jump " << 3 << std::endl;
        }
        std::cout << "stair length " << L << std::endl;
        std::cout << "solution count " << n << std::endl;
    }

}