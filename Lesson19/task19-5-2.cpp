#include <fstream>
#include <iostream>
#include <vector>

void clear_array(char* buffer, int size){
    char* begin = buffer;
    char* end = begin + size;
    std::fill(begin, end, 0);
}

int main() {
    char buffer[20];
    std::ifstream bank;
    std::string path;
    std::cout << "Enter path of file " << std::endl;
    std::cin >> path;//"E:\words.txt"
    bank.open(path, std::ios::binary);
    //buffer[20] = '\0';
    if (bank.is_open()){
        while(!bank.eof()){
            clear_array(buffer, sizeof (buffer));
            bank.read(buffer, sizeof (buffer));
            std::cout << buffer;
        }
    }
    bank.close();
    return 0;
}
