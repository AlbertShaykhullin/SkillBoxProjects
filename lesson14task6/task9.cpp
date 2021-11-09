#include <iostream>

void initialization_gameField (int gameField[10][10]){
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            gameField[i][j] = 0;
        }
    }
}

void enter_ship(int gameField[10][10], int player, int size){
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    bool correct = true;
    while (true){
        int counter = 0;
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
                    if(gameField[i][j] != 0){
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
    std::cout << "--------------------------------" << std::endl;
}
void print_gameField_player(int gameField[10][10], int player){
    if (player > 0){
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (gameField[i][j] == 10){
                    std::cout << "X  ";
                } else if (gameField[i][j] == -10){
                    std::cout << "Y  ";
                } else if (gameField[i][j] >= 0) {
                    std::cout << gameField[i][j] << "  ";
                } else {
                    std::cout << 0 << "  ";
                }
            }
            std::cout << std::endl;
        }
    } else {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (gameField[i][j] == 10){
                    std::cout << "X  ";
                } else if (gameField[i][j] == -10){
                    std::cout << "Y  ";
                } else if (gameField[i][j] < 0) {
                    std::cout << gameField[i][j] << " ";
                } else {
                    std::cout << 0 << "  ";
                }
            }
            std::cout << std::endl;
        }
    }
}
int count_ship_cell (int gameField[10][10], int player){
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (player == 1 && gameField[i][j] > 0 && gameField[i][j] != 10 || player == -1 && gameField[i][j] < 0 && gameField[i][j] != 10){
                count++;
            }
        }
    }
    return count;
}

bool game_run(int gameField[10][10], int player1, int player2){
    if (count_ship_cell(gameField,player1) == 0 || count_ship_cell(gameField,player2) == 0){
        return false;
    } else {
        return true;
    }
}

void shoot_player(int gameField[10][10], int player){
    int x = 0;
    int y = 0;
    print_gameField_player(gameField, player);
    while (game_run(gameField, 1, -1)){
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "Player ";
        player > 0 ? std::cout << "1" : std::cout << "2";
        std::cout << " shoots" << std::endl;
        std::cout << "Enter x1" << std::endl;
        std::cin >> x;
        std::cout << "Enter y1" << std::endl;
        std::cin >> y;
        if (x > 9 || x < 0 || y > 9 || y < 0 || gameField[x][y] > 0 && player > 0 || gameField[x][y] < 0 && player < 0 || std::abs(gameField[x][y]) == 10){
            std::cout << "Error invalid data, please input correct data" << std::endl;
        } else {
            if (gameField[x][y] != 0) {
                std::cout << "Player ";
                player > 0 ? std::cout << "1" : std::cout << "2";
                std::cout << " get in target" << std::endl;
                gameField[x][y] = 10 * player;
                print_gameField_player(gameField, player);
                std::cout << "Player 1 ship cells count - " << count_ship_cell(gameField, 1) << std::endl;
                std::cout << "Player 2 ship cells count - " << count_ship_cell(gameField, -1) << std::endl;
            } else {
                std::cout << "Player ";
                player > 0 ? std::cout << "1" : std::cout << "2";
                std::cout << " missed" << std::endl;
                std::cout << "-------------------------------------" << std::endl;
                break;
            }
        }
    }
}

int main() {
    int player1 = 1;
    int player2 = -1;
    int gameField[10][10]; /*= {{1,  -1, 1,  -1, 1,  -1, 1,  -1, 2,  2},
                             {-2, -2, 2,  2,  -2, -2, 2,  2,  -2, -2},
                             {3,  3,  3,  -3, -3, -3, 3,  3,  3,  0},
                             {-3, -3, -3, 4,  4,  4,  4,  0,  0,  0},
                             {-4, -4, -4, -4, 0,  0,  0,  0,  0,  0},
                             {0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                             {0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                             {0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                             {0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                             {0,  0,  0,  0,  0,  0,  0,  0,  0,  0}};*/
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
    while (game_run(gameField, player1, player2)){
        shoot_player(gameField,player1);
        shoot_player(gameField,player2);
    }
    std::cout << "--------------------------------" << std::endl;
    if (count_ship_cell(gameField, player1) == 0 && count_ship_cell(gameField, player2) > 0) {
        std::cout << "Player 2 won" << std::endl;
    } else if (count_ship_cell(gameField, player2) == 0 && count_ship_cell(gameField, player1) > 0){
        std::cout << "Player 1 won" << std::endl;
    } else {
        std::cout << "Nobody won" << std::endl;
    }
}