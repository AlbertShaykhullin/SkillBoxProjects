#include <iostream>

void swap(int* pa, int* pb){
    int temp = 0;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main() {
    int a = 10;

    int b = 20;

    swap(&a, &b);

    std::cout << a << " " << b;
}