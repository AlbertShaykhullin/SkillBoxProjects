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

void diag_matrix (int A[4][4]){
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (j != i && j != (3 - i)){
                A[j][i] = 0;
            }
        }
    }
}

int main() {
    int A [4][4];
    std::cout << "Enter matrix" << std::endl;
    import_matrix(A);
    std::cout << "A matrix" << std::endl;
    print_matrix(A);
    std::cout << "Diag matrix" << std::endl;
    diag_matrix(A);
    print_matrix(A);
}
