#include <iostream>

void enter_area (int &xStart,int &yStart,int &xEnd,int &yEnd){
    while(true){
        std::cout << "Enter start position x" << std::endl;
        std::cin >> xStart;
        std::cout << "Enter start position y" << std::endl;
        std::cin >> yStart;
        std::cout << "Enter end position x" << std::endl;
        std::cin >> xEnd;
        std::cout << "Enter end position y" << std::endl;
        std::cin >> yEnd;
        if(xStart < 0 || xStart > 11 ||
           yStart < 0 || yStart > 11 ||
           xEnd < 0 || xEnd > 11 ||
           yEnd < 0 || yEnd > 11 ){
            std::cout << "Error please enter valid data" << std::endl;
        } else {
            break;
        }
    }
}

void bubble_pop(bool pup[12][12], int xStart, int yStart, int xEnd, int yEnd){
    for (int i = xStart; i <= xEnd; ++i) {
        for (int j = yStart; j <= yEnd; ++j) {
            if (pup[i][j] == true){
                pup[i][j] = false;
                std::cout << "POP" << " ";
            } else if (pup[i][j] == false){
                std::cout << "   " << " ";
            }
        }
        std::cout << std::endl;
    }
}

void print_matrix (bool pup[12][12]){
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            pup[i][j]? std::cout << "o" << " ": std::cout << "x" << " ";
        }
        std::cout << std::endl;
    }
}

void init_matrix (bool pup [12][12]){
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            pup[i][j] = true;
        }
    }
}

bool is_all_false(bool pup[12][12]){
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            if(pup[i][j] == true){
                return false;
            }
        }
    }
    return true;
}

int main() {
    bool pup [12][12];
    int xStart;
    int yStart;
    int xEnd;
    int yEnd;
    init_matrix(pup);
    print_matrix(pup);
    while(!is_all_false(pup)){
        enter_area(xStart,yStart,xEnd,yEnd);
        bubble_pop(pup,xStart,yStart,xEnd,yEnd);
        print_matrix(pup);
    }
    std::cout << "All the bubbles burst!" << std::endl;
}

