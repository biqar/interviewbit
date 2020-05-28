//
// Created by Islam, Abdullah Al Raqibul on 5/28/20.
//

int Solution::romanToInt(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    string dict[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int num[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    int i=0, index=0, ret=0, sz = A.size();

    while(i<sz && index<13) {
        string target = dict[index];
        string cur = A.substr(i, target.size());
        if(cur == target) {
            ret += num[index];
            i += target.size();
        }
        else {
            index++;
        }
    }
    return ret;
}
