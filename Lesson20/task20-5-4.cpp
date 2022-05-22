#include <iostream>
#include <fstream>

const int MAX_COUNT = 100;
const int COUPURE_COUNT = 4;

int get_summ_atm(int atm[]){
    int summ_atm = 0;
    for (int i = 0; i < MAX_COUNT; ++i) {
        summ_atm += atm[i];
    }
    return summ_atm;
}

int get_summ(int coupure[], int nominale[]){
    int summ = 0;
    for (int i = 0; i < COUPURE_COUNT; ++i) {
        summ += coupure[i]*nominale[i];
    }
    return summ;
}


void get_atm_coupure(int atm[],int atm_coupure[],int nominale[]){
    for (int i = 0; i < MAX_COUNT; ++i){
        for (int j = 0; j < COUPURE_COUNT; ++j) {
            if (atm[i] == nominale[j]) atm_coupure[j]++;
        }
    }
}

bool get_coupure(int coupure[], int atm_coupure[], int nominale[], int* pmoney){
    int temp = *pmoney;
    for (int i = COUPURE_COUNT-1; i >= 0; --i) {
        coupure[i] += temp / nominale[i];
        while (coupure[i] > atm_coupure[i]){
            if (i > 0){
                coupure[i] -= 1;
                coupure[i-1] += nominale[i]/nominale[i-1];
            } else {

                return false;
            }
        }
        temp = temp % nominale[i];
    }
    return true;
}

void get_cash(int atm[], int coupure[], int nominale[], int* pmoney,int summ = 0){
    if (summ == *pmoney) return;
    for (int i = 0; i < COUPURE_COUNT; ++i) {
        for (int j = 0; j < coupure[i]; ++j) {
            for (int k = 0; k < MAX_COUNT; ++k) {
                if (atm[k] == nominale[i]){
                    summ += atm[k];
                    atm[k] = 0;
                    break;
                }
            }
        }
    }
/*    if (summ < *pmoney) {
        int remainder = *pmoney - summ;
        int* premainder = &remainder;
        get_coupure(coupure, nominale, premainder);
        get_cash(atm, coupure, nominale, pmoney, summ);
    }*/
}

void get_atm(int atm[], std::ifstream& in_file){
    int i = 0;
    while(!in_file.eof()){
        in_file >> atm[i];
        i++;
    }
}

void load_atm(int atm[], int coupure[],int nominale[],int i = 0, int maxprev = 0,int max = 0){
    if (i>COUPURE_COUNT-1) return;
    max += coupure[i];
    for (int j = maxprev; j < max; ++j) {
        atm[j] = nominale[i];
    }
    maxprev = max;
    i++;
    load_atm(atm,coupure,nominale, i, maxprev, max);
}


void fill_atm(int atm[],int coupure[],int nominale[], const int* money){

    for (int i = 0; i < MAX_COUNT; ++i) {
        for (int j = 0; j < MAX_COUNT; ++j) {
            for (int k = 0; k < MAX_COUNT; ++k) {
                for (int l = 0; l < MAX_COUNT; ++l) {
                    coupure[0] = l;
                    coupure[1] = k;
                    coupure[2] = j;
                    coupure[3] = i;
                    int sum = coupure[0]*nominale[0] + coupure[1]*nominale[1] + coupure[2]*nominale[2] + coupure[3]*nominale[3];
                    int count = coupure[0] + coupure[1] + coupure[2] + coupure[3];
                    if(count > MAX_COUNT || sum > *money){
                        break;
                    }
                    if(sum == *money && count == MAX_COUNT){
                        load_atm(atm, coupure, nominale);
                    }
                }
            }
        }
    }
    //std::cout << atm[MAX_COUNT-1]<< std::endl;
    //int sum = get_summ_atm(atm);
    //std::cout << sum<< std::endl;
}
//int get_coupure(int atm[MAX_COUNT]){
//
//}

int main(){
    int coupure[COUPURE_COUNT] = {0,0,0,0};
    int atm_coupure[COUPURE_COUNT] = {0,0,0,0};
    int nominale[COUPURE_COUNT] = {100, 500, 1000, 5000};
    int atm[MAX_COUNT];


    //std::ifstream* pin_file = &in_file;

    std::string input;
    std::cin >> input;
    int money = std::stoi(input.substr(1,input.size()-1));
    if (money%100 > 0 || !(input[0] == '+' || input[0] == '-')){
        std::cout << "Error, wrong money count";
    }else{
        int* pmoney = &money;
        if (input[0] == '+'){
            std::ofstream out_file("ATM.txt", std::ios::binary);
            if (out_file.is_open()){
                //int money = 150200;

                fill_atm(atm,coupure,nominale, pmoney);
                int sum = get_summ_atm(atm);
                std::cout << "Money loaded " << sum << std::endl;
                for (int i = 0; i < MAX_COUNT; ++i) {
                    out_file << atm[i] << std::endl;
                }
                out_file.close();
            }else {
                std::cout << "File is not exist" << std::endl;
            }

        } else if (input[0] == '-'){
            std::ifstream in_file("ATM.txt", std::ios::binary);
            if (in_file.is_open()){
                get_atm(atm, in_file);
                in_file.close();
                int summ_atm_begin = get_summ_atm(atm);
                get_atm_coupure(atm, atm_coupure, nominale);
                if(get_coupure(coupure, atm_coupure, nominale, pmoney)){
                    int summ = get_summ(coupure,nominale);
                    get_cash(atm,coupure, nominale,pmoney);
                    int summ_atm = get_summ_atm(atm);
                    int sum_all = summ_atm_begin - money;

                    std::cout << "Money in atm in the begining " << summ_atm_begin << std::endl;
                    std::cout << "Get cash " << summ << std::endl;
                    std::cout << "Money in atm " << summ_atm << std::endl;
                    std::cout << "Money in atm must be " << sum_all << std::endl;

                    std::ofstream out_file("ATM.txt", std::ios::binary);
                    if (out_file.is_open()){
                        for (int i = 0; i < MAX_COUNT; ++i) {
                            out_file << atm[i] << std::endl;
                        }
                        out_file.close();
                    } else {
                        std::cout << "File is not exist" << std::endl;
                    }
                } else {
                    std::cout << "Error, not enough coupure";
                }
            } else {
                std::cout << "File is not exist" << std::endl;
            }
        }
    }

}