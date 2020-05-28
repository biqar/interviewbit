//
// Created by Islam, Abdullah Al Raqibul on 5/28/20.
//

//todo: getting a Compilation Error now, but solved and scored it previously

int Solution::lengthOfLastWord(const string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int sz = A.size(), i, j, k;
    int len = 0, ret = 0;

    for(i=0; i<sz; i+=1) {
        if(A[i] == ' ') {
            if(len != 0) ret = len;
            len = 0;
        } else {
            len += 1;
        }
    }
    if(len != 0) ret = len;

    return ret;
}
