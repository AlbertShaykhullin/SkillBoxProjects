#include <iostream>
void print_matrix (int matrix [2] [12]){
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 12; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


int main() {
    int tableware [2][12] = {{4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                             {4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}};
    int dishes [2][12] = {{3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                          {3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}};
    int chears [2][12] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                          {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    chears[0][4] += 1;
    tableware[1][2] -= 1;
    tableware[0][0] -= 1;
    tableware[1][2] += 1;
    dishes[0][0] -= 1;
    std::cout << "Tableware" << std::endl;
    print_matrix(tableware);
    std::cout << "dishes" << std::endl;
    print_matrix(dishes);
    std::cout << "chears" << std::endl;
    print_matrix(chears);
    return 0;
}
