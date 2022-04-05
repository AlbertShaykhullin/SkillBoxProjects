#include <iostream>
#include <string>
#include <sstream>

enum note{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

int main(){
    std::cout << "Please, enter notes from 1 to 7" << std::endl;
    std::string melody[12];
    int sizeMelody = sizeof (melody) / sizeof (melody[0]);
    for (int i = 0; i < sizeMelody; ++i) {
        std::cin >> melody[i];
    }
    for (int i = 0; i < sizeMelody; ++i) {
        int sizeNote = melody[i].size();
        for (int j = 0; j < sizeNote; ++j) {
            int temp = (int)(melody[i][j])-'0'-1;
            if(temp < 7 && temp >= 0){
                int notes = 1<<temp;
                if(notes & DO){
                    std::cout << "DO";
                } else if(notes & RE){
                    std::cout << "RE";
                }else if(notes & MI){
                    std::cout << "MI";
                }else if(notes & FA){
                    std::cout << "FA";
                }else if(notes & SOL){
                    std::cout << "SOL";
                }else if(notes & LA){
                    std::cout << "LA";
                }else if(notes & SI){
                    std::cout << "SI";
                }
                std::cout << " ";
            }
        }
        std::cout << std::endl;

    }
    return 0;
}



















/*
enum note{
    C = 1,
    D = 2,
    E = 4,
    F = 8,
    G = 16,
    A = 32,
    B = 64
};

int main() {

    std::string input[12];
    std::string text;
    for (int i = 0; i < 2;i++){
        std::cin >> text;
        input[i] = text;
    }
    for (int i = 0; i < 2; i++){
        std::stringstream output;
        for (int j = 0; j < input[i].size(); j++){
            int temp = (int)(input[i][j]) - '0' - 1;
            if (1<<temp == C){
                output << 'C';
            } else if (1<<temp == D){
                output << 'D';
            } else if (1<<temp == E){
                output << 'E';
            } else if (1<<temp == F){
                output << 'F';
            } else if (1<<temp == G){
                output << 'G';
            } else if (1<<temp == A){
                output << 'A';
            } else if (1<<temp == B){
                output << 'B';
            }
            output << ' ';
        }
        std::cout << output.str() << std::endl;
    }
    return 0;
}*/
