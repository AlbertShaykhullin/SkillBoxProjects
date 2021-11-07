#include <iostream>
#include <vector>

std::vector<float> sum_mult(std::vector<float> V, float M[4][4]){
    std::vector<float> result(4);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result[i] += V[i] * M[i][j];
        }
    }
    return result;
}
void print_matrix (float A[4][4]){
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void print_vector (std::vector<float> V){
    for (int i = 0; i < 4; ++i) {
        std::cout << V [i] << " ";
    }
    std::cout << std::endl;
}
int main() {
    std::vector<float> V = {1, 2, 3, 4};
    float M [4][4] = {{1, 1, 1, 1},
                      {2, 2, 2, 2},
                      {3, 3, 3, 3},
                      {4, 4, 4, 4}};
    std::cout << "Vector" << std::endl;
    print_vector(V);
    std::cout << "Matrix" << std::endl;
    print_matrix(M);
    std::vector<float> R = sum_mult(V, M);
    std::cout << "Result" << std::endl;
    print_vector(R);
}