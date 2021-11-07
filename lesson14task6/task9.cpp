#include <iostream>

void initialization_gameField (int gameField[10][10]){
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            gameField[i][j] = 0;
        }
    }
}

void enter_ship(int gameField[10][10], int player, int size){
    int x1;
    int y1;
    int x2;
    int y2;
    int counter = 0;
    bool correct = true;
    while (true){
        std::cout << "Enter x1" << std::endl;
        std::cin >> x1;
        std::cout << "Enter y1" << std::endl;
        std::cin >> y1;
        if(size == 1){
            if(gameField[x1][y1] != 0){correct = false;}
            if(!correct) {
                std::cout << "Error wrong data, please enter correct data" << std::endl;
                correct = true;
            } else {
                gameField[x1][y1] = player*size;
                break;
            }
        } else {
            std::cout << "Enter x2" << std::endl;
            std::cin >> x2;
            std::cout << "Enter y2" << std::endl;
            std::cin >> y2;
            for (int i = x1; i <= x2; ++i) {
                for (int j = y1; j <= y2; ++j) {
                    if(gameField[i][i] != 0){
                        correct = false;
                    }
                    counter++;
                }
            }
            if(counter != size || !correct || ((x1 != x2) && (y1 != y2))) {
                std::cout << "Error wrong data, please enter correct data" << std::endl;
                correct = true;
            } else {
                for (int i = x1; i <= x2; ++i) {
                    for (int j = y1; j <= y2; ++j) {
                        gameField[i][j] = player*size;
                    }
                }
                break;
            }
        }
    }

}

void print_gameField(int gameField[10][10]){
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (gameField[i][j] >= 0) {
                std::cout << gameField[i][j] << "  ";
            } else {
                std::cout << gameField[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    int player1 = 1;
    int player2 = -1;
    int gameField[10][10];
    initialization_gameField(gameField);
    for (int j = 4; j > 0; --j) {
        for (int i = 0; i < j; ++i) {
            std::cout << "Player 1" << std::endl;
            std::cout << "Ship size " << 5-j << std::endl;
            enter_ship(gameField, player1, 5-j);
            print_gameField(gameField);
            std::cout << "Player 2" << std::endl;
            std::cout << "Ship size " << 5-j << std::endl;
            enter_ship(gameField, player2, 5-j);
            print_gameField(gameField);
        }
    }

}