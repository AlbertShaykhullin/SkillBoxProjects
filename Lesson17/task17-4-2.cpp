#include <iostream>

void inversearr(int *parr){
    for (int i = 0; i < 5; ++i) {
        int temp = 0;
        temp = *(parr + i);
        *(parr + i) = *(parr + (9-i));
        *(parr + (9-i)) = temp;
    }
}

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int *parr = arr;
    inversearr(parr);
    for (int i = 0; i < 10; ++i) {
        std::cout << *(arr + i)<< " ";
    }
}