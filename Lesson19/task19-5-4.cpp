#include <fstream>
#include <iostream>
#include <vector>

bool check_extension(char* buffer){
    int first = *buffer;
    std::string ext;
    for (int i = 1; i < 4; ++i) {
        ext +=*(buffer+i);
    }
    if (first == -119 && ext == "PNG"){
        return true;
    } else return false;

}

int main() {
    char buffer[8];
    std::ifstream bank;
    std::string path;
    std::string fileExt = "";
    std::cout << "Enter path of file " << std::endl;
    std::cin >> path;//"E:\jaguar.png"
    try{
        if (path.rfind('.') > path.size()){
            throw "No point in address";
        }else{
            fileExt = path.substr(path.rfind('.'));
        }

    }
    catch (const char* msg){
        std::cout << msg << std::endl;
    }

    if (fileExt == ".png"){
        bank.open(path, std::ios::binary);
        if (bank.is_open()) {
            bank >> buffer;

            if (check_extension(buffer)){
                std::cout << "File extension is .png" << std::endl;
            } else {
                std::cout << "File extension is not .png" << std::endl;
            }

            bank.close();
        } else {
            std::cout << "File is not exist" << std::endl;
        }
    } else {
        std::cout << "File extension is not .png" << std::endl;
    }
    return 0;
}