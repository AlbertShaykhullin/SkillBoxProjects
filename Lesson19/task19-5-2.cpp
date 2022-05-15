#include <fstream>
#include <iostream>
#include <vector>

/*void clear_array(char* buffer, int size){
    char* begin = buffer;
    char* end = begin + size;
    std::fill(begin, end, 0);
}*/

int main() {
    char buffer[21];
    std::ifstream bank;
    std::string path;
    std::cout << "Enter path of file " << std::endl;
    std::cin >> path;//"E:\words.txt"
    bank.open(path, std::ios::binary);
    buffer[20] = '\0';
    if (bank.is_open()){
        while(!bank.eof()){
            //clear_array(buffer, sizeof (buffer)-1);
            bank.read(buffer, sizeof (buffer));
            buffer[bank.gcount()] = '\0';
            std::cout << buffer;
        }
    }
    bank.close();
    return 0;
}
