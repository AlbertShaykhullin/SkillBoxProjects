#include <iostream>

bool substr(char* a, char* b){
    bool check = true;
    int i = 0;
    while (*(a+i) != '\0'){
        int j = 0;
        while (*(b + j) != '\0'){
            if (*(a+i+j) != *(b + j)){
                check = false;
                break;
            } else{
                check = true;
            }
            ++j;
        }
        if (check == true){
            return check;
        }
        ++i;
    }
    return false;
}

int main() {
    char* a = "Hello world";

    char* b = "wor";

    char* c = "banana";

    std::cout << substr(a,b) << " " << substr(a,c);
}