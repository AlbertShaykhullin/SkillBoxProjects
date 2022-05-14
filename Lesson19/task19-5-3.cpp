#include <fstream>
#include <iostream>
#include <vector>

/*int sum_vec(std::vector<int> vector){
    int summ = 0;
    for (int i = 0; i < vector.size(); ++i) {
        summ += vector[i];
    }
    return summ;
}

int max_vec(std::vector<int> vector){
    int max = 0;
    for (int i = 0; i < vector.size(); ++i) {
        if (max < vector[i]){
            max = vector[i];
        }
    }
    return max;
}

int max_index_vec(std::vector<int> vector){
    int max = max_vec(vector);
    for (int i = 0; i < vector.size(); ++i) {
        if (max == vector[i]) {
            return i;
        }
    }
}*/

int main() {
    std::ifstream bank;
    std::string path;
    std::string name;
    std::string surname;
    std::string date;

    std::string max_money_name;
    std::string max_money_surname;
    std::string max_money_date;


    int money;
    int summ = 0;
    int max_money = 0;

    std::cout << "Enter path of file " << std::endl;
    std::cin >> path;//"E:\table.txt"
    bank.open(path);
    //buffer[20] = '\0';

    if (bank.is_open()){
        while(!bank.eof()){
            bank >> name >> surname >> money >> date;
            if (money > max_money){
                max_money = money;
                max_money_name = name;
                max_money_surname = surname;
                max_money_date = date;
            }
            summ += money;

            std::cout << name << " " << surname << " " << money << " " << date << std::endl;;
        }
    }
    std::cout << "Total money payment: " << summ << std::endl;
    std::cout << "Max money payment: " << max_money << std::endl;
    std::cout << "Max money receiver: " << max_money_name;
    std::cout << " " << max_money_surname << std::endl;
    bank.close();
    return 0;
}
