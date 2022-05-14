#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

void clear_array(char* buffer, int size){
    char* begin = buffer;
    char* end = begin + size;
    std::fill(begin, end, 0);
}
void print_vec(std::vector<int> vec){
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int get_position(std::vector<int>vec, int* start){
    if (*start > 11){
        *start = (*start)%13;
    }
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == *start){
            return i;
        }
    }
    *start += 1;
    return  get_position(vec, start);
}

std::string get_text_from_file(std::string directory,std::vector<int> step,const int* pCurrentPos){
    std::ifstream bank;
    char buffer[21];
    std::string question = "";
    std::string filePath = "../" + directory + "\\" + std::to_string(step[*pCurrentPos]) + ".txt";
    bank.open(filePath,std::ios::binary);
    buffer[21] = '\0';
    if (bank.is_open()){
        while (!bank.eof()){
            clear_array(buffer, sizeof (buffer)-1);
            bank.read(buffer, sizeof (buffer)-1);
            question = question + buffer;
        }
    }
    bank.close();
    return question;
}

int main() {
    std::vector<int> step;
    for (int i = 0; i < 13; ++i) {
        step.push_back(i);
    }
    int scoreViewers = 0;
    int scoreExperts = 0;
    int currentPos = 0;
    int* pCurrentPos = &currentPos;
    while(step.size()!=1 && scoreViewers < 6 && scoreExperts < 6){
        int temp = currentPos;
        std::cout << "Please enter the offset: " << std::endl;
        std::cin >> currentPos;
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.sync();
            std::cin >> currentPos;
        }
        currentPos += temp;
        currentPos = get_position(step, pCurrentPos);
        step.erase(step.begin() + currentPos);
        //print_vec(step);

        std::string question = get_text_from_file("questions",step, pCurrentPos);
        std::cout << question << std::endl;
        std::string answer = get_text_from_file("answers",step, pCurrentPos);
        std::string playerAnswer;
        std::cin >> playerAnswer;
        std::transform(playerAnswer.begin(), playerAnswer.end(), playerAnswer.begin(), tolower);
        std::transform(answer.begin(), answer.end(), answer.begin(), tolower);
        if (playerAnswer == answer){
            std::cout << "Correct" << std::endl;
            scoreExperts++;
        } else {
            std::cout << "Wrong" << std::endl;
            scoreViewers++;
        }
    }
    if (scoreExperts==6){
        std::cout << "Experts wins" << std::endl;
    } else {
        std::cout << "Viewers wins" << std::endl;
    }
    //currentPos = step[0];
    return 0;
}