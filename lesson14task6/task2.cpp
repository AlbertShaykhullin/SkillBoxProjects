#include <iostream>

void enter_xy (char gameField[3][3], char type){
    while (true) {
        int x;
        int y;
        std::cout << "Enter x for " << type << std::endl;
        std::cin >> x;
        std::cout << "Enter y for " << type << std::endl;
        std::cin >> y;
        if (x < 1 || x > 3 || y < 1 || y > 3 || gameField[x - 1][y - 1] != '-') {
            std::cout << "Error please enter correct value" << std::endl;
        } else {
            gameField[x - 1][y - 1] = type;
            break;
        }
    }
}

void print_field(char gameField[3][3]){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << gameField[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::string winner (char gameField[3][3], char type){
    for (int i = 0; i < 3; ++i) {
        int winVertical = 0;
        int winHorizontal = 0;
        for (int j = 0; j < 3; ++j) {
            if(gameField[i][j] == type){
                winVertical++;
            }
            if(gameField[j][i] == type){
                winHorizontal++;
            }
        }
        if(winVertical == 3 || winHorizontal == 3){
            std::string out = " is winner";
            return  type + out;
        }
    }
    return "No winners";
}

void game_part(char gameField[3][3], char type, bool &gameRun, int &counter){
    if (counter <= 9){
        std::string gameStatus;
        enter_xy(gameField, type);
        counter++;
        gameStatus = winner(gameField,type);
        if (gameStatus == "No winners" && counter == 9){
            gameRun = false;
            print_field(gameField);
            std::cout << "Draw - there is no winners"<< std::endl;
        } else if(gameStatus != "No winners"){
            gameRun = false;
            print_field(gameField);
            std::cout << "Step "<< type << ":" << gameStatus<< std::endl;
        } else {
            print_field(gameField);
            std::cout << "Step "<< type << ":" << gameStatus<< std::endl;
        }
    }
}

int main() {
    std::string gameStatus;
    bool gameRun = true;
    int counter = 0;
    char gameField[3][3] = {{'-', '-', '-'},
                            {'-', '-', '-'},
                            {'-', '-', '-'}};
    print_field(gameField);
    for (int i = 0; i < 9; ++i) {
        game_part(gameField, 'X', gameRun, counter);
        if (!gameRun) break;
        game_part(gameField, 'O', gameRun,counter);
        if (!gameRun) break;
    }
}