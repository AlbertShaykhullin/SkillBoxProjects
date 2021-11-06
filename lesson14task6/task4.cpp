#include <iostream>

void import_matrix (int A[4][4]){
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cin >> A[j][i];
        }
    }
}

void print_matrix (int A[4][4]){
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << A[j][i] << " ";
        }
        std::cout << std::endl;
    }
}

bool equal_matrix (int A[4][4], int B[4][4]){
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (A[j][i] != B[j][i]){
                return false;
            }
        }
    }
    return true;
}

int main() {
    int A [4][4];
    int B [4][4];
    std::cout << "Enter A matrix" << std::endl;
    import_matrix(A);
    std::cout << "Enter A matrix" << std::endl;
    import_matrix(B);
    std::cout << "A matrix" << std::endl;
    print_matrix(A);
    std::cout << "B matrix" << std::endl;
    print_matrix(B);
    equal_matrix(A,B)? std::cout << "A equal B" : std::cout << "A not equal B";
}
