#include <fstream>
#include <sstream>
#include <iostream>


int main(){
    std::ofstream file("list_income.txt", std::ios::app);
    std::stringstream ss;
    if (file.is_open()){
        while(true){
            std::string input;
            std::string name;
            std::string surname;
            std::string date;
            std::string sum;
            std::getline(std::cin, input);
            if (input == "exit"){
                break;
            }
            ss << input;
            ss >> name >> surname >> date >> sum;
            int day = std::stoi(date.substr(0, 2));
            int month = std::stoi(date.substr(3, 2));
            int year = std::stoi(date.substr(6, 4));
            if (month < 1 || month > 12){
                std::cout << "Error! wrong month" << std::endl;
            } else if (day < 1 || day > 31){
                std::cout << "Error! wrong date" << std::endl;
            } else if (year < 1900 || year > 2022){
                std::cout << "Error! wrong year" << std::endl;
            } else if (std::stoi(sum) < 0){
                std::cout << "Error! wrong sum" << std::endl;
            } else {
                file << name << " " << surname << " " << date << " " << sum << std::endl;
            }
        }
    } else {
        std::cout << "File is not exist" << std::endl;
    }

}