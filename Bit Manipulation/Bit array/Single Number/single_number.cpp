//
// Created by Islam, Abdullah Al Raqibul on 5/16/20.
//

int Solution::singleNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i, sz = A.size(), res;

    if(sz >= 1) res = A[0];
    else res = 0;

    for(i=1; i<sz; i+=1) {
        res ^= A[i];
    }

    return res;
}
