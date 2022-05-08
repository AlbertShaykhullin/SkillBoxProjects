#include <fstream>
#include <iostream>
#include <vector>

int sum_vec(std::vector<int> vector){
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
}

int main() {
    std::ifstream bank;
    std::string path;
    std::string name;
    std::string surname;
    std::vector<std::string> nameVector;
    std::vector<std::string> surnameVector;
    std::vector<int> moneyVector;
    std::vector<std::string> dateVector;

    int money;
    std::string date;
    std::cout << "Enter path of file " << std::endl;
    std::cin >> path;//"E:\table.txt"
    bank.open(path);
    //buffer[20] = '\0';
    if (bank.is_open()){
        while(!bank.eof()){
            bank >> name >> surname >> money >> date;
            nameVector.push_back(name);
            surnameVector.push_back(surname);
            moneyVector.push_back(money);
            dateVector.push_back(date);
            std::cout << name << " " << surname << " " << money << " " << date << std::endl;;
        }
    }
    std::cout << "Total money payment: " << sum_vec(moneyVector) << std::endl;
    std::cout << "Max money payment: " << max_vec(moneyVector) << std::endl;
    std::cout << "Max money receiver: " << nameVector[max_index_vec(moneyVector)];
    std::cout << " " << surnameVector[max_index_vec(moneyVector)] << std::endl;
    bank.close();
    return 0;
}
