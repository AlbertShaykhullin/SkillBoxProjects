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
    int sizeMelody = 2;
    int melody[sizeMelody];
    std::string input;
    int temp = 0;

    for (int i = 0; i < sizeMelody; ++i) {
        int tempSum = 0;
        std::cin >> input;
        for (int j = 0; j < input.size(); ++j) {
            temp = 1<<((input[j]-'0')-1);
            tempSum = tempSum + temp;
        }
        melody[i] = tempSum;
    }
    for (int i = 0; i < sizeMelody; ++i) {
        melody[i] & DO? std::cout << "DO ":std::cout << "";
        melody[i] & RE? std::cout << "RE ":std::cout << "";
        melody[i] & MI? std::cout << "MI ":std::cout << "";
        melody[i] & FA? std::cout << "FA ":std::cout << "";
        melody[i] & SOL? std::cout << "SOL ":std::cout << "";
        melody[i] & LA? std::cout << "LA ":std::cout << "";
        melody[i] & SI? std::cout << "SI ":std::cout << "";
        std::cout << std::endl;
    }
    return 0;
}