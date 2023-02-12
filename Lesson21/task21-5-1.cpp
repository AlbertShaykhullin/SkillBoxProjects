#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

struct list_income
{
    std::string name;
    std::string surname;
    std::string date;
    std::string sum;
};

void save_list_income(std::ofstream& file, list_income& income)
{
    file << income.name << " " << income.surname << " " << income.date << " " << income.sum << std::endl;
}

void load_list_income(std::ifstream& file, list_income& income)
{
    file >> income.name  >> income.surname >> income.date >> income.sum;
}

bool check_income(list_income& income)
{
    int day = std::stoi(income.date.substr(0, 2));
    int month = std::stoi(income.date.substr(3, 2));
    int year = std::stoi(income.date.substr(6, 4));
    if (month < 1 || month > 12){
        std::cout << "Error! wrong month" << std::endl;
        return false;
    } else if (day < 1 || day > 31){
        std::cout << "Error! wrong date" << std::endl;
        return false;
    } else if (year < 1900 || year > 2023){
        std::cout << "Error! wrong year" << std::endl;
        return false;
    } else if (std::stoi(income.sum) < 0){
        std::cout << "Error! wrong sum" << std::endl;
        return false;
    } else {
        return true;
    }
}


int main() {
    std::stringstream ss;
    while (true) {
        std::cout << "Input the command (list, add, exit):" << std::endl;
        std::string input;
        list_income income;
        std::getline(std::cin, input);
        if (input == "exit") {
            break;
        } else if (input == "list") {
            std::ifstream file("list_income.txt", std::ios::app);
            while (true) {
                load_list_income(file, income);
                if (file.eof()){
                    break;
                } else {
                    std::cout << income.name << " " << income.surname << " " << income.date << " " << income.sum << std::endl;
                }

            }
        } else if (input == "add") {
            std::ofstream file("list_income.txt", std::ios::app);
            if (file.is_open()) {
                std::getline(std::cin, input);
                ss << input;
                ss >> income.name >> income.surname >> income.date >> income.sum;
                if (check_income(income)) {
                    save_list_income(file,income);
                } else {
                    std::cout << "File is not exist" << std::endl;
                }
            }
        }
    }
}