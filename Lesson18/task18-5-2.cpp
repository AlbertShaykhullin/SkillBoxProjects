#include <iostream>

// 1 1 1 1
// 1 1 2
// 1 2 1
// 2 1 1
// 2 2

void put_rabbit( int new_place, int* n,const int* L, const int* R)
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
	for (int i = 1; i <= *R; i++){
        put_rabbit( new_place + i, n,  L, R);
    }
}

int main(){
    int n = 0;	// количество решений
    int R = 3; // максимальный прыжок
    int L = 5; // длина лестницы
    std::cin >> L;
    if (L < 0){
        std::cout << "Error stair length can't be less then 0";
    } else{
        int* pn = &n;
        int* pR = &R;
        int* pL = &L;
        // количество вариантов
        put_rabbit( 0, pn, pL, pR);
        std::cout << "max jump " << R << std::endl;
        std::cout << "stair length " << L << std::endl;
        std::cout << "solution count " << n << std::endl;
    }

}