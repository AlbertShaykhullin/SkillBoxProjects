#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};
    int maxTillNow = vec[0];
    int maxEnding = 0;
    int maxi = 0;
    int maxj = 0;

    for (int i = 0; i < vec.size(); i++){
        maxEnding = maxEnding + vec[i];
        if (maxEnding < 0){
            maxEnding = 0;
            maxi = i + 1;
        } else if (maxTillNow < maxEnding){
            maxTillNow = maxEnding;
            maxj = i;
        }
    }
//    for (int i = 0; i < vec.size(); i++) {
//        int sum = 0;
//        for (int j = i; j < vec.size(); ++j) {
//            sum += vec[j];
//            if (sum > maxsum){
//                maxsum = sum;
//                maxi = i;
//                maxj = j;
//            }
//        }
//    }

    std::cout << maxTillNow << " " << maxi << " " << maxj;

    return 0;
}

