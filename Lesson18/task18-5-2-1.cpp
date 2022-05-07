#include <iostream>

// 1 1 1 1
// 1 1 2
// 1 2 1
// 2 1 1
// 2 2

int put_rabbit(const int* L, int new_place = 0)
{
    int R = 3;
    int n = 0;
	// проверка параметров
	if ((new_place < 0)|| (new_place > *L)){
        return 0;
    }
	// стоп игра!!!
	if (new_place == *L){
        n++;
    }
	// собственно рекурсия
	for (int i = 1; i <= R; i++){
        n += put_rabbit(L,new_place + i);
    }
    return n;
}

int main(){
    int n = 0;	// количество решений
    int R = 3; // максимальный прыжок
    int L = 5; // длина лестницы
    std::cin >> L;
    if (L < 0){
        std::cout << "Error stair length can't be less then 0";
    } else{
        int* pL = &L;
        // количество вариантов
        n = put_rabbit(pL);
        std::cout << "max jump " << R << std::endl;
        std::cout << "stair length " << L << std::endl;
        std::cout << "solution count " << n << std::endl;
    }

}