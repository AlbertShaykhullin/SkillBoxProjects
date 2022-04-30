#include <iostream>
#include <string>
#include <vector>
#include <sstream>


void evendigits(long long digit, int* pans)
{
	// проверка параметров
	if (digit <= 0){
        return;
    }
	// стоп игра!!!
	if ((digit%10)%2 == 0){
        (*pans)++;
    }
	// собственно рекурсия
    evendigits( digit/10, pans);
}


int main(){
    int ans = 0;
    int* pans = &ans;

    evendigits(9223372036854775806, pans);

    std::cout << ans;
    //ans == 10

    //Пояснение: 9 223 372 036 854 775 806

}